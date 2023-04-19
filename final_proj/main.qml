import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.0

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
            model: ["Song 1", "Song 2", "Song 3", "Song 4", "Song 5"]
            delegate: Text {
                text: modelData
                font.pixelSize: 14
            }
        }

        RowLayout {
            spacing: 10

            Button {
                id: backwardButton
                text: "Backward"
                onClicked: {
                    // TODO: Implement backward functionality
                }
            }

            Button {
                id: playButton
                text: "Play"
                onClicked: {
                       audioPlayer.togglePlay();
                       //playButton.text = audioPlayer.player.state() == QMediaPlayer::PlayingState ? "Pause" : "Play";
                   }
            }

            Button {
                id: pauseButton
                text: "Pause"
                onClicked: {
                    // TODO: Implement pause functionality
                }
            }

            Button {
                id: forwardButton
                text: "Forward"
                onClicked: {
                    // TODO: Implement forward functionality
                }
            }


        }

        Slider {
            id: volumeSlider
            width: parent.width
            from: 0
            to: 100
            value: 50
            onValueChanged: {
                // TODO: Implement volume control functionality
            }
        }
    }
}
