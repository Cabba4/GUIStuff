#ifndef MYAPP_H
#define MYAPP_H
#include <QObject>
class myapp : public QObject
{
    //class app

    Q_OBJECT

public:
    //myapp();
    explicit myapp(QObject *parent = 0);

signals:
    void sendMess(const QString &txt_box_str);

public slots:
    void func_btn_clk();
};

#endif //MYAPP.h


