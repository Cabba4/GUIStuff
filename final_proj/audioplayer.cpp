#include "audioplayer.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

audioplayer::audioplayer(QObject* parent) : QObject(parent)
{
}

audioplayer::audioplayer(const QStringList& songList, QObject* parent)
    : QObject(parent)
{
    player = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    m_songList = songList;

    for (const QString& songPath : songList) {
        playlist->addMedia(QUrl::fromLocalFile(songPath));
    }

    qDebug() << "Song list:" << m_songList;

    connect(player, &QMediaPlayer::stateChanged, this, &audioplayer::onPlayStateChanged);
    connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &audioplayer::onSongChanged);
}


void audioplayer::play()
{
    if (player->state() == QMediaPlayer::PausedState) {
        player->play();
    } else if (player->state() == QMediaPlayer::StoppedState) {
        if (!m_songList.empty() && !playlist->isEmpty()) { // check if the song list and playlist are not empty
            playlist->setCurrentIndex(0);
            player->setPlaylist(playlist);
            player->play();
            emit songChanged(m_songList[0]);
            qDebug() << "Playing song: " << m_songList[0];
        } else {
            qDebug() << "Song list or playlist is empty.";
        }
    }
}


void audioplayer::pause()
{
    if (player->state() == QMediaPlayer::PlayingState) {
        player->pause();
    }
}

void audioplayer::onPlayStateChanged(QMediaPlayer::State state)
{
    QString stateString;
    switch (state) {
        case QMediaPlayer::PlayingState:
            stateString = "Playing";
            break;
        case QMediaPlayer::PausedState:
            stateString = "Paused";
            break;
        case QMediaPlayer::StoppedState:
            stateString = "Stopped";
            break;
    }
    emit playStateChanged(stateString);
}

// Slot called whenever the current song in the playlist changes
void audioplayer::onSongChanged(int index)
{
    QString fileName = QMediaContent(playlist->media(index)).request().url().toLocalFile();
    emit songChanged(fileName);
}

QStringList audioplayer::getSongList() const
{
    return m_songList;
}

QMediaPlaylist* audioplayer::getPlaylist() const
{
    return playlist;
}
