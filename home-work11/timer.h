#ifndef TIMER_H
#define TIMER_H
#include "qqml.h"
#include <QObject>
#include <QTimer>
#include <QSoundEffect>

class timer : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit timer(QObject *parent = 0);

signals:
    void timeChanged(QString data);

private:
    QTimer *tmr;
    QTimer *tmrDown;
    QSoundEffect* uwu;
    int m_time;

public slots:
    Q_INVOKABLE void fwdTime();
    Q_INVOKABLE void backTime();
    Q_INVOKABLE void playSound(QSoundEffect* uwu);
};

#endif // TIMER_H
