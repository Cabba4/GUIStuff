#include "mainwindow.h"
#include <QGridLayout>>
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QWidget>
#include <qfont.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(400,320);

    QPushButton *plsBtn = new QPushButton("+", this);
        plsBtn->setGeometry(30, 80, 75, 30);
        plsBtn->setFont( QFont("Times", 18, QFont::Bold));
    QPushButton *minBtn = new QPushButton("-", this);
        minBtn->setGeometry(150, 100, 75, 30);
        minBtn->setFont( QFont("Times", 18, QFont::Bold));

    label = new QLabel("x" , this);
    label->setGeometry(130, 40, 75, 30);
    label->setFont( QFont("Times", 18, QFont::Bold));

    connect(plsBtn, &QPushButton::clicked, this, &MainWindow::OnPlus);
    connect(minBtn, &QPushButton::clicked, this, &MainWindow::OnMinus);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::OnPlus(){
    int val = label->text().toInt();
    val++;
    label->setText(QString::number(val));
}

void MainWindow::OnMinus(){
    int val = label->text().toInt();
    val--;
    label->setText(QString::number(val));
}
