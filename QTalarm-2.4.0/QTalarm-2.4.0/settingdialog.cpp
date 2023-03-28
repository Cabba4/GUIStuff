#include <QSystemTrayIcon>
#include "settingdialog.h"
#include "ui_settingdialog.h"
#include "fileio.h"

SettingDialog::SettingDialog(QWidget *parent,bool *isMilTime, bool *WarnOnPm, QSystemTrayIcon *trayIcon) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    _isMilTime=isMilTime;
    _WarnOnPm=WarnOnPm;
    _trayIcon=trayIcon;


    ui->plebTime->setChecked(!*_isMilTime);
    ui->milTime->setChecked(*_isMilTime);

    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(Save()));
    connect(ui->plebTime,SIGNAL(clicked(bool)),this,SLOT(toggleWarnBox()));
    connect(ui->milTime,SIGNAL(clicked(bool)),this,SLOT(toggleWarnBox()));
}

SettingDialog::~SettingDialog()
{
    delete ui;
}


void SettingDialog::Save()
{

    *_isMilTime=ui->milTime->isChecked();
    FileIO::SaveisMilTime(*_isMilTime);
    FileIO::SaveWarnOnPm(*_WarnOnPm);


    _trayIcon->setIcon(QIcon(":/new/icons/Clock.png"));

    this->deleteLater();
}


