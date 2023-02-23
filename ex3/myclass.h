#ifndef MYCLASS_H
#define MYCLASS_H
#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
public:

    explicit MyClass(QObject *parent = 0);

signals:
    void valueChanged(int value);
    void sendMess(const QString &txt_box_str);

public slots:
    void setValue(int v);
    void increment();
    void decrement();
    void func_btn_clk();

private:
    int myValue;
};
#endif // MYCLASS_H
