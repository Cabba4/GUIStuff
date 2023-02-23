#include "myapp.h"
#include <QDebug>

myapp::myapp(QObject *parent):
    QObject(parent)
{

}

void myapp::func_btn_clk(){
    emit sendMess("Ill write to box");
    qDebug() << "Button pressed";
}
