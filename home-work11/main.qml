import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.1
import myModule 1.0
import QtMultimedia 5.0


Window {
    width: 640
    height: 480
    visible: true
    visibility: Window.Windowed
    title: qsTr("Hello World")

    MyTimer{
        id: timer
    }

    SoundEffect{
        id: uwu
        source: ""
        function playSound() {
            timer.playSound(uwu);

        }
    }

    Rectangle{
        id: rectParent
        color: "#CEE5ED"
        x: 210
        y: 130
        border.color: "#26282a"
        border.width: 1
        property alias nmbrText: nmbr.text
        Text {

            id: nmbr
            text: ""
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 0
            anchors.centerIn: parent
            font.pixelSize: 24
            Connections {
                target: timer
                function onTimeChanged(data) {
                    nmbr.text = data
                }
            }

        }
        width: 200
        height: 50
        radius: 20


    }


    Button{
        id: min_btn
        text: qsTr("---")
        x: 170
        y: 260
        background: Rectangle
        {
            implicitWidth: 100
            implicitHeight: 40
            color: min_btn.down ? "#808080" : "#C3B1E1"
            border.color: "#26282a"
            border.width: 1
            radius: 45
        }
        MouseArea {
                       anchors.fill: parent
                       onPressed: {
                           timer.playSound(uwu);
                           timer.backTime();
                           console.log("Button pressed down")
                       }

                       onReleased: {
                           console.log("Button released")
                       }
                   }

    }

    Button{
        id: plus_btn
        text: "+++"
        x: 360
        y: 260
        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 40
            color: plus_btn.down ? "#808080" : "#C3B1E1"
            border.color: "#26282a"
            border.width: 1
            radius: 45
        }
        MouseArea {
                       anchors.fill: parent
                       onPressed: {
                           timer.playSound(uwu);
                           timer.fwdTime();
                           console.log("Button pressed down")
                       }

                       onReleased: {
                           console.log("Button released")
                       }
                   }
    }
}
