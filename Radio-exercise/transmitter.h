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
    void onRadioButtonClick(double value);
    void onArrowClickAdd(double value);
    void onArrowClickMinus(double value);

signals:
    void sliderValue(double value);
    void radioValue(double value);
    void arrowValueAdd(double value);
    void arrowValueMinus(double value);

};

#endif // TRANSMITTER_H
