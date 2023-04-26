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
    color: "#779ecb"

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 10
        Text {
            text: "Playlist"
            font.bold: true
            font.pixelSize: 16
        }

        ListView {
            id: musicList
            width: parent.width
            height: 200
            model: audioplayer.songList // Bind to the songList property of your audioplayer instance
            delegate: Text {
                text: modelData
                font.pixelSize: 14
            }
}

        RowLayout {
            spacing: 10

            Button {
                id: backButton
                text: "|◁ "
                font.pointSize: 22
                onClicked: {
                    audioplayer.play();
                }
                width: 55 // set the width to 50 pixels
                height: 55 // set the height to 50 pixels
                implicitWidth: width // set the implicit width to match the width
                implicitHeight: height // set the implicit height to match the height
                background: Rectangle {
                    radius: width / 2 // set the border radius to half the width/height
                    color: "transparent" // make the background transparent
                    border.width: 1 // add a border with a width of 1 pixel
                    border.color: "black" // set the border color to black
                }
            }

            Button {
                id: playButton
                text: "▷"
                font.pointSize: 22
                onClicked: {
                    audioplayer.play();
                }
                width: 55 // set the width to 50 pixels
                height: 55 // set the height to 50 pixels
                implicitWidth: width // set the implicit width to match the width
                implicitHeight: height // set the implicit height to match the height
                background: Rectangle {
                    radius: width / 2 // set the border radius to half the width/height
                    color: "transparent" // make the background transparent
                    border.width: 1 // add a border with a width of 1 pixel
                    border.color: "black" // set the border color to black
                }
            }

            Button {
                id: pauseButton
                text: "II"
                font.pointSize: 22
                onClicked: {
                    audioplayer.pause();
                }
                width: 55 // set the width to 50 pixels
                height: 55 // set the height to 50 pixels
                implicitWidth: width // set the implicit width to match the width
                implicitHeight: height // set the implicit height to match the height
                background: Rectangle {
                    radius: width / 2 // set the border radius to half the width/height
                    color: "transparent" // make the background transparent
                    border.width: 1 // add a border with a width of 1 pixel
                    border.color: "black" // set the border color to black
                }
            }

            Button {
                id: ffButton
                text: "▷|"
                font.pointSize: 22
                onClicked: {
                    audioplayer.play();
                }
                width: 55 // set the width to 50 pixels
                    height: 55 // set the height to 50 pixels
                    implicitWidth: width // set the implicit width to match the width
                    implicitHeight: height // set the implicit height to match the height
                    background: Rectangle {
                        radius: width / 2 // set the border radius to half the width/height
                        color: "transparent" // make the background transparent
                        border.width: 1 // add a border with a width of 1 pixel
                        border.color: "black" // set the border color to black
                    }

            }
        }
    }
}
