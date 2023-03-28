#include "fileio.h"
#include "schedulemodel.h"
#include "schedules.h"
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QString>
#include <QDateTime>
#include <QTime>
#include <QList>
#include <QDebug>

FileIO::FileIO(QObject *parent) :
    QObject(parent)
{

}

bool FileIO::ExtractAudio()
{
    if(QFile::copy(":/new/sounds/alarm.ogg", QDir::tempPath()+"/QTalarm.ogg"))
    {
        return true;
    }
    return false;
}

bool FileIO::DelExtracted()
{
    return QFile::remove(QDir::tempPath()+"/QTalarm.ogg");
}

//static lazy loaded methods


int FileIO::LoadVolume()
{
    QSettings settings;
    return settings.value("Volume").toInt();
}

void FileIO::SaveVolume(int vol)
{
    QSettings settings;
    settings.setValue("Volume",vol);
}

bool FileIO::LoadWindowShow()
{
    QSettings settings;
    if(!settings.contains("ShowWindowDefault"))
    {
        return true;
    }
    return settings.value("ShowWindowDefault").toBool();
}


void FileIO::SaveWindowShow(bool showWindow)
{
    QSettings settings;
    settings.setValue("ShowWindowDefault",showWindow);
}


bool FileIO::isMilTime()
{
    QSettings settings;
    return settings.value("isMilTime").toBool();
}

bool FileIO::LoadisMono()
{
    QSettings settings;
    return settings.value("isMono").toBool();
}

void FileIO::SaveisMono(bool isMono)
{
    QSettings settings;
    settings.setValue("isMono",isMono);
}

void FileIO::SaveisMilTime(bool isMilTime)
{
    QSettings settings;
    settings.setValue("isMilTime",isMilTime);
}


bool FileIO::LoadWarnOnPm()
{
    QSettings settings;
    return settings.value("WarnOnPm").toBool();
}

bool FileIO::LoadSeenSolveText()
{
    QSettings settings;
    return settings.value("SeenSolvedText").toBool();
}

void FileIO::SaveWarnOnPm(bool warn)
{
    QSettings settings;
    settings.setValue("WarnOnPm",warn);
}

void FileIO::SaveSeenSolveText()
{
    QSettings settings;
    settings.setValue("SeenSolvedText",true);
}
