#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    //: QMainWindow(parent)
    //, ui(new Ui::MainWindow)

:QWidget(parent)
{
    //ui->setupUi(this);
    label = new QLabel("my label 1", this);
    auto *grid = new QGridLayout(this);
    grid->addWidget(label, 0, 0);
    setLayout(grid);
    //ui->label-> setText("UwU team goes UwU");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui-> label-> setText("Button Pressed");
}

