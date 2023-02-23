#include "timer.h"
#include <QTimer>
#include <QDebug>
#include <QSoundEffect>

timer::timer(QObject *parent): QObject(parent)
{


    m_time = 0;
    tmr = new QTimer(this);
    tmrDown =  new QTimer(this);
    connect(tmr, &QTimer::timeout, this, &timer::fwdTime);
    connect(tmrDown, &QTimer::timeout, this, &timer::backTime);


}


void timer::playSound(QSoundEffect* uwu){
    uwu -> setSource(QUrl::fromLocalFile("://sounds/button-1.wav"));
    uwu -> play();
}

void timer::backTime(){
    tmr -> stop();
    tmrDown -> start(1000);
    m_time--;
    qDebug() << "Timer " << m_time;
    emit timeChanged(QString::number(m_time));
}


void timer::fwdTime()
{
    tmrDown -> stop();
    tmr ->start(1000);
    m_time ++;
    qDebug() << "Timer " << m_time;
    emit timeChanged(QString::number(m_time));
}
