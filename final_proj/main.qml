import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.0

// SOMEHOW HAVE TO IMPORT audioPlayer here so that buttons can work.

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Audio Player")
    color: "#779ECB"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: "Music List"
            font.bold: true
            font.pixelSize: 16
        }

        ListView {
            id: musicList
            width: parent.width
            height: 200
            model: audioPlayer.songList // Bind to the songList property of your audioplayer instance
            delegate: Text {
                text: modelData
                font.pixelSize: 14
            }
        }

        RowLayout {
            spacing: 10

            Button {
                id: playButton
                text: "Play"
                onClicked: {
                    audioPlayer.play();
                }
            }

            Button {
                id: pauseButton
                text: "Pause"
                onClicked: {
                    audioPlayer.pause();
                }
            }

        }
    }
}
