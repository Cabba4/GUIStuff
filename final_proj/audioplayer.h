#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class audioplayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList songList READ getSongList NOTIFY songListChanged)

public:
    explicit audioplayer(QObject* parent = nullptr);
    void play();
    void pause();
    void togglePlay();
    void setSong(const QString& songName);
    QStringList getSongList() const;

signals:
    void playStateChanged(const QString& stateString);
    void songChanged(const QString& songName);
    void songListChanged();

private slots:
    void onPlayStateChanged(QMediaPlayer::State state);
    void onSongChanged(int index);

private:
    QMediaPlayer* player;
    QMediaPlaylist* playlist;
    QStringList m_songList;
};

#endif // AUDIOPLAYER_H
