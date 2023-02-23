#include "myclass.h"
#include <QDebug>


MyClass::MyClass(QObject *parent):
    QObject(parent)
{
    myValue = -1;
}

void MyClass::setValue(int v)
{
    if (v == myValue)
        return;
    myValue = v;
    emit valueChanged(myValue);
}

void MyClass::increment()
{
    emit valueChanged(++myValue);
}

void MyClass::decrement()
{
    emit valueChanged(--myValue);
}

void MyClass::func_btn_clk(){
    emit sendMess("Ill write to box");
    qDebug() << "Button pressed";
}

