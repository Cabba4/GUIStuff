#ifndef ALARM_H
#define ALARM_H

#include <QObject>
#include <QString>
#include <QMediaPlayer>
#include <QTimer>

class Alarm : public QObject
{
    Q_OBJECT
public:
    virtual ~Alarm(){};
    static Alarm & GetInstance()
    {
        static Alarm instance;
        return instance;
    }
    void Start();
    void Stop();
    bool isPlaying();
    bool canResume;

private:
    explicit Alarm(QObject *parent = 0);
    QMediaPlayer * media;
    QString _DefaultPath;

    QTimer *_Pause;

    bool _isPlaying;
    
signals:
    
public slots:
    void RepeatAllTheThings(QMediaPlayer::MediaStatus);
    void Resume();
    void SetVolume(int);
    
};

#endif // ALARM_H
