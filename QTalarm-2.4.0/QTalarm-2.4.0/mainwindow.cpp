#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "alarm.h"
#include "fileio.h"
#include "settingdialog.h"
#include "snooze.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QLabel>
#include <QCloseEvent>
#include <QTimeEdit>
#include <QTimer>
#include <QFileDialog>
#include <QDialogButtonBox>
#include <QSlider>
#include <QSystemTrayIcon>
#include <QListWidgetItem>
#include <QCalendarWidget>
#include <QToolTip>
#include <QLocalSocket>
#include <QLocalServer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->_supportsTray = QSystemTrayIcon::isSystemTrayAvailable();
    if(!this->_supportsTray)
    {
        qInfo() << "No system tray detected. What a shitty DE"; //what is this 1993?
    }

    TerminateIfRunning();

    //add buttons

    //Create / load Schedule
    PopulateListWidget();
    DisablePanelIfNoSelection();


    LoadOptions();

    //Setup threading

    //set up alarm singleton
    CurAlarm = &Alarm::GetInstance();


    SetupVolume();

    //Tray icons
    QAction *QAshow=new QAction("&Show",this);
    QAction *QAquit=new QAction("&Quit",this);
    SetupTrayIcon(QAshow,QAquit);


    SetupClock();
    ui->chkBastard->setToolTip("Only stop alarms after a random math problem has been solved.");


    SetupSlots(QAquit,QAshow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    event->ignore();
    if(this->_supportsTray)
    {
        this->hide();
    }else{
        Quit();
    }
}

void MainWindow::SetupClock()
{
    //Set up clock display
    QTimer *CurrentTime=new QTimer(this);
    connect(CurrentTime,SIGNAL(timeout()),this,SLOT(timeCheck()));
    CurrentTime->start(500);
}

void MainWindow::ToggleWindow(QSystemTrayIcon::ActivationReason Reason)
{
    if(Reason==QSystemTrayIcon::DoubleClick || Reason==QSystemTrayIcon::Trigger)
    {
        ToggleWindow();
    }
}

void MainWindow::ToggleWindow()
{
    if(this->CurAlarm->isPlaying())
    {
        this->CurAlarm->Stop();
    }
    ui->TestBtn->setText("Test");
    if(this->isHidden())
    {
        this->show();
    }else{
        this->hide();
    }
}

void MainWindow::SetTime()
{

    //If there is no selected row. Enter was probably hit, the time registered, folowed by
    //on change trigger, execpt the changes have already been logged
    if(ui->listWidget->currentIndex().column()!=-1)
    {
        if(ui->timeEdit->time().hour()>12 && !_isMilTime && _WarnOnPm)
        {
            PMWarning();
        }
        UpdateListWidget();
    }
}


void MainWindow::Quit()
{
    if(this->CurAlarm->isPlaying())
    {
        //message box will cause app to exit even though we told it not too. wtf
        //QMessageBox::warning(this,"Nope","you didn't think it was going to be that easy did you?");
        return;
    }else{
        FileIO::DelExtracted();
        FileIO::SaveVolume(ui->VolumeSlider->value());
        qApp->quit();
    }
}

void MainWindow::timeCheck()
{
    UpdateClock();
    SnoozeMenuCheck();
    if(_isMilTime!=_prevTimeWasMil)
    {
        _prevTimeWasMil=_isMilTime;
        displayTimeMode();
    }
}

void MainWindow::UpdateClock()
{
    if(_isMilTime)
    {
        ui->Clock->setText(QTime::currentTime().toString("H:mm:ss"));
    }else{
        ui->Clock->setText(QTime::currentTime().toString("h:mm:ss ap"));
    }
}


void MainWindow::OpenDiaglog(bool isChecked)
{
    if(isChecked)
    {
        QString AlarmLocation = QFileDialog::getOpenFileName(this,"Select Alarm File",QDir::homePath()); 
    }
}

void MainWindow::TestAlarm()
{

    this->CurAlarm->Start();

    this->testrun=true;
}


void MainWindow::SnoozeMenuCheck()
{
    if((this->testrun==true) || (this->CurAlarm->isPlaying() && this->CurAlarm->canResume))
    {
        //Create Snooze Menu object
        snooze *snMenu=new snooze(this,CurAlarm);
        snMenu->show();
        if(this->_supportsTray && this->testrun==false)
        {
            this->hide();
        }
        this->CurAlarm->canResume=false;
        this->testrun=false;
    }
}


void MainWindow::PMWarning()
{
    QMessageBox::warning(this,"Time Verification","Your selected time is set for PM. If you intended to wake in the morning, now is your chance to fix it");
}


void MainWindow::ShowSettings()
{
    SettingDialog *settingsPage=new SettingDialog(this,&_isMilTime, &_WarnOnPm, trayIcon);
    settingsPage->show();
}

void MainWindow::displayTimeMode()
{
    if(_isMilTime)
    {
        ui->timeEdit->setDisplayFormat("H:mm:ss");

    }else{
        ui->timeEdit->setDisplayFormat("h:mm:ss ap");


    }
}

void MainWindow::PopulateListWidget()
{
    ui->listWidget->clear();
    ui->listWidget->setCurrentRow(this->_lastDeletedIndex);
}

void MainWindow::DisablePanelIfNoSelection()
{
    if(ui->listWidget->currentRow()==-1)
    {

        ui->timeEdit->setEnabled(false);

        ui->lblTime->setEnabled(false);


    }
    else
    {
        ui->timeEdit->setEnabled(true);
        ui->chkBastard->setEnabled(true);
        ui->lblTime->setEnabled(true);
    }
}

void MainWindow::UpdateListWidget()
{
    int index=ui->listWidget->currentRow();
    PopulateListWidget();
    ui->listWidget->setCurrentRow(index);
}

void MainWindow::SendTrayMessage(QString title, QString message)
{
    if(!FileIO::LoadSeenSolveText())
    {
        QIcon icon;
        if(FileIO::LoadisMono())
        {
            icon = QIcon(":/new/icons/mono.png");
        }else{
            icon = QIcon(":/new/icons/Clock.png");
        }
        trayIcon->showMessage(title,message,icon);
        FileIO::SaveSeenSolveText();
    }
}

void MainWindow::ChangeIconToDefault()
{
    trayIcon->setToolTip("QTalarm");
    if(FileIO::LoadisMono())
    {
        this->trayIcon->setIcon(QIcon(":/new/icons/mono.png"));
    }else{
        this->trayIcon->setIcon(QIcon(":/new/icons/Clock.png"));
    }
}


void MainWindow::SetupSlots(QAction *QAquit, QAction *QAshow)
{
    //set up ui slots
    connect(QAquit,SIGNAL(triggered()),this,SLOT(Quit()));
    connect(QAshow,SIGNAL(triggered()),this,SLOT(ToggleWindow()));
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(ToggleWindow(QSystemTrayIcon::ActivationReason)));
    connect(ui->actionQuit,SIGNAL(triggered()),this,SLOT(Quit()));
    connect(ui->actionAbout_QT,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    connect(ui->actionAbout_QTalam,SIGNAL(triggered()),this,SLOT(ShowAbout()));
    connect(ui->actionSettings,SIGNAL(triggered(bool)),this,SLOT(ShowSettings()));
    connect(ui->timeEdit,SIGNAL(editingFinished()),this,SLOT(SetTime()));
    connect(ui->chkBastard,SIGNAL(clicked(bool)),this,SLOT(ToggleBastard(bool)));
    connect(ui->TestBtn,SIGNAL(clicked()),this,SLOT(TestAlarm()));
    connect(ui->VolumeSlider,SIGNAL(valueChanged(int)),CurAlarm,SLOT(SetVolume(int)));


}

void MainWindow::SetupTrayIcon(QAction *QAshow, QAction *QAquit)
{
    trayIcon=new QSystemTrayIcon(this);
    trayIconMenu=new QMenu(this);

    trayIconMenu->addAction(QAshow);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(QAquit);
    trayIcon->setContextMenu(trayIconMenu);
    ChangeIconToDefault();
    trayIcon->show();

}

void MainWindow::SetupVolume()
{
    int Volume = FileIO::LoadVolume();
    ui->VolumeSlider->setValue(Volume<=0? 50:Volume);
    CurAlarm->SetVolume(ui->VolumeSlider->value());
}

void MainWindow::LoadOptions()
{
    _isMilTime=FileIO::isMilTime();
    _WarnOnPm=FileIO::LoadWarnOnPm();
    _prevTimeWasMil=_isMilTime;
    displayTimeMode();
}

void MainWindow::TerminateIfRunning()
{
    const QString appKey = "qtalarmLocal";

    QLocalSocket *socket = new QLocalSocket(this);
    socket->connectToServer(appKey);

    QLocalSocket::LocalSocketState status = socket->state();
    if (status == QLocalSocket::ConnectedState)
    {
        socket->close();
        socket->deleteLater();
        qInfo() << "Application already running. Exiting";
        exit(EXIT_FAILURE);
    }
    socket->deleteLater();


    //used for process communication for duplicate processes
    QLocalServer *m_server = new QLocalServer(this);
    connect(m_server, SIGNAL(newConnection()), this, SLOT(handleLocalConnection()));
    m_server->setSocketOptions(QLocalServer::UserAccessOption);

    if (!m_server->listen(appKey))
    {
        qInfo() << "Unable to start Local Process Server";
    } else {
        qInfo() << "Local-only Process Server up and running";
    }
}

void MainWindow::handleLocalConnection()
{
    this->show();
}
