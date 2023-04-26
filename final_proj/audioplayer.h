    #ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>

// REMOVE A BUNCH OF FUNCTIONS FOR CLEANER CODE. FIRST MAKE PLAY PAUSE WORK THEN THE PLAYLIST CAN HAPPEN.

class audioplayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList songList READ getSongList NOTIFY songListChanged)

public:
    explicit audioplayer(QObject* parent = 0);
    explicit audioplayer(const QStringList& songList, QObject* parent = 0);
    void play();
    void pause();
    //void togglePlay();
    //void setSong(const QString& songName);
    QStringList getSongList() const;
    QMediaPlaylist* getPlaylist() const;

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
