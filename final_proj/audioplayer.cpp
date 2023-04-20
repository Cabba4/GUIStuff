#include "audioplayer.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

audioplayer::audioplayer(QObject* parent) : QObject(parent)
{
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    player->setPlaylist(playlist);

    QString path1 = ":/condition_one.ogg";
    qDebug() << path1;
    QFile file(path1);
    if (file.exists()) {
        qDebug() << "File exists at path" << path1;
    } else {
        qDebug() << "File not found at path" << path1;
    }

    playlist->addMedia(QUrl::fromLocalFile(path1));
    //playlist->addMedia(QUrl::fromLocalFile(path2));
    playlist->setCurrentIndex(0);

    // Update the song list
    m_songList << "jjk" << "some_other_song";
    emit songListChanged();

    // Connect the player signals to our slots
    connect(player, &QMediaPlayer::stateChanged, this, &audioplayer::onPlayStateChanged);
    connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &audioplayer::onSongChanged);


    if (playlist->isEmpty()) {
        qDebug() << "Playlist is empty";
    } else {
        qDebug() << "Playlist is not empty";
    }

    // Set the playlist on the player
    player->setPlaylist(playlist);
}

void audioplayer::play()
{
    player->play();
}

void audioplayer::pause()
{
    player->pause();
}

void audioplayer::togglePlay()
{
    if (player->state() == QMediaPlayer::PlayingState) {
        player->pause();
    } else {
        player->play();
    }
}

void audioplayer::setSong(const QString& songName)
{
    int index = playlist->mediaCount();
    for (int i = 0; i < playlist->mediaCount(); ++i) {
        QUrl url = playlist->media(i).request().url().toLocalFile();;
        if (url.fileName() == songName) {
            index = i;
            break;
        }
    }

    if (index < playlist->mediaCount()) {
        playlist->setCurrentIndex(index);
        emit songChanged(songName);
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
