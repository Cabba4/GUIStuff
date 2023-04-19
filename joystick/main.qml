import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.0

Window {
    width: 1640
    height: 1080
    visible: true
    property int speed: 10
    title: qsTr("Hello World")
    color: "black"
    Image{
        id: bg
        source: "bg.jpg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    Item{
        x: 500
        y:500

        id: helicopter
        height: 450
        width:400
        Image{
            id: heliImg
            source: "hehe.png"
            anchors.fill: parent
            height: 300
            fillMode: Image.PreserveAspectFit
        }

        Behavior on x {
            PropertyAnimation {
                duration: speed
            }
        }

        Behavior on y {
            PropertyAnimation {
                duration: speed
            }
        }

        NumberAnimation {
            id: heliRotation
            target: helicopter
            property: "rotation"
            duration: 1000
            from: 0
            to: 360
            easing.type: Easing.InOutQuad
        }
    }

    Button{
        text: ">>>"
        width: 50
        x: 1385
        y: 760

        onClicked: {
            helicopter.x = helicopter.x + 70
        }
    }

    Button{
        id: upbtn
        width: 50
        text: "<<<"
        x: 1330
        y: 710
        transform: Rotation{
            origin.x: upbtn.width / 2
            origin.y: upbtn.height / 2
            angle: 90
        }

        onClicked: {
            helicopter.y = helicopter.y - 70
        }
    }

    Button{
        width: 50
        id: downbtn
        text: ">>>"
        x: 1330
        y: 810
        transform: Rotation{
            origin.x: upbtn.width / 2
            origin.y: upbtn.height / 2
            angle: 90
        }

        onClicked: {
            helicopter.y = helicopter.y + 70
        }
    }

    Button{
        width:50
        text: "<<<"
        x: 1275
        y: 760
        onClicked: {
            helicopter.x = helicopter.x - 70
        }
    }

    Button{
        text: "Rot"
        width: 50
        x: 1330
        y: 760
        onClicked: {
            heliRotation.running = true
        }
    }

      Rectangle{
            width: 175
            height: 175
            id: joystick
            x: 1500
            y: 690
            z: 3
            radius: joystick.width / 2
            color: "white"
            border.color: "black"
            border.width: 1

            Rectangle {
                id: center
                width: 20
                height: 20
                x: joystick.width / 2 - 10
                y: joystick.width / 2 - 10
                color: "red"
                z: 6
                radius: center.width / 2

                Drag.active: dragArea.drag.active
                Drag.hotSpot.x: 10
                Drag.hotSpot.y: 10

                function update() {
                    console.log(x + " " + y)
                    speed = 5000-28*x;
                }

                onXChanged: update()
                onYChanged: update()


                MouseArea {
                    id: dragArea
                    anchors.fill: parent
                    drag.target: parent

                }
            }

            Rectangle {
                id: centershadow
                anchors.centerIn: parent
                width: 10
                height: 10
                color: "gray"
                z: 4
                radius: centershadow.width / 2


            }

        }



}
