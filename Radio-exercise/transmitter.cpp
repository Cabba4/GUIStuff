#include "transmitter.h"

TRANSMITTER::TRANSMITTER(QObject *parent):
    QObject(parent)
{

}

void TRANSMITTER::onSliderValueChanged(double value)
{
   emit sliderValue(value);

}

void TRANSMITTER::onRadioButtonClick(double value)
{
    emit radioValue(value);
}

void TRANSMITTER::onArrowClickAdd(double value)
{
    emit arrowValueAdd(value);
}

void TRANSMITTER::onArrowClickMinus(double value)
{
    emit arrowValueMinus(value);
}


