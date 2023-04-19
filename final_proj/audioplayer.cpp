#include "audioplayer.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>

audioplayer::audioplayer(QObject* parent) : QObject(parent)
{
    player = new QMediaPlayer;
    playlist = new QMediaPlaylist;
    player->setPlaylist(playlist);

    playlist->addMedia(QUrl::fromLocalFile("C:/Uni Stuff/GUI/QT Stuff/final_proj/jjk.mp3"));
    playlist->addMedia(QUrl::fromLocalFile("C:/Uni Stuff/GUI/QT Stuff/final_proj/jjk.mp3"));
    //playlist->addMedia(QUrl("qrc:/music/3.mp3"));
    playlist->setCurrentIndex(0);

    // Connect the player signals to our slots
    connect(player, &QMediaPlayer::stateChanged, this, &audioplayer::onPlayStateChanged);
    connect(playlist, &QMediaPlaylist::currentIndexChanged, this, &audioplayer::onSongChanged);

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
