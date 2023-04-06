#include "transmitter.h"

TRANSMITTER::TRANSMITTER(QObject *parent):
    QObject(parent)
{

}

void TRANSMITTER::onSliderValueChanged(double value)
{
   emit sliderValue(value);

}
