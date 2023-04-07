#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <QObject>

class TRANSMITTER : public QObject
{
    Q_OBJECT

public:
    explicit TRANSMITTER(QObject *parent =0);

public slots:
    void onSliderValueChanged(double value);

signals:
    void sliderValue(double value);

};



#endif // TRANSMITTER_H
