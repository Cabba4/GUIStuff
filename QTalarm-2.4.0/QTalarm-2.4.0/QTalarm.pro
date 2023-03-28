#-------------------------------------------------
#
# Project created by QtCreator 2012-09-30T18:05:49
#
#-------------------------------------------------

QT       += core gui multimedia 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtalarm
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    alarm.cpp \
    fileio.cpp \
    snooze.cpp \
    settingdialog.cpp

HEADERS  += mainwindow.h \
    alarm.h \
    fileio.h \
    snooze.h \
    settingdialog.h

FORMS    += mainwindow.ui \
    snooze.ui \
    settingdialog.ui

RESOURCES += \
    Icons.qrc
CONFIG += precompile_header
