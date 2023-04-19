#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class audioplayer : public QObject
{
    Q_OBJECT

public:
    explicit audioplayer(QObject* parent = nullptr);
    void play();
    void pause();
    void togglePlay();
    void setSong(const QString& songName);

signals:
    void playStateChanged(const QString& stateString);
    void songChanged(const QString& songName);

private slots:
    void onPlayStateChanged(QMediaPlayer::State state);
    void onSongChanged(int index);

private:
    QMediaPlayer* player;
    QMediaPlaylist* playlist;
};

#endif // AUDIOPLAYER_H
