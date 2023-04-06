import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.15

Window {
    width: 940
    height: 780
    visible: true
    title: qsTr("Hello World")

    Button {
        id: button1
        x: 29
        y: 50
        width: 180
        height: 80
        text: qsTr("Normal Mode")
        background: Rectangle{
            color: "#38B261"
        }
        onClicked: {
            timerNight.stop()
            timerNormal.start()
        }
    }

    Button {
        id: button2
        x: 229
        y: 50
        width: 180
        height: 80
        text: qsTr("Night Mode")
        background: Rectangle{
            color: "#5C5CFF"
        }
        onClicked: {
            timerNormal.stop()
            timerNight.start()
        }
    }

    Rectangle { // Horizontal Road
        x: 40
        y: 390
        width: 860
        height: 40
        border.color: "black"
        border.width: 4
        color: "gray"
    }
    Rectangle { // Vertical Road
        x: 420
        y: 50
        width: 40
        height: 700
        border.color: "black"
        border.width: 4
        color: "gray"
    }

    Rectangle { // Circle1
        id: up_first
        x: 480
        y: 305

        width: 80
        height: 80
        color: "red"
        radius: width / 2
    }
    Rectangle { // Circle2
        id: up_second
        x: 565
        y: 305

        width: 80
        height: 80
        color: "black"
        radius: width / 2
    }
    Rectangle { // Circle3
        id: up_third
        x: 650
        y: 305

        width: 80
        height: 80
        color: "black"
        radius: width / 2
    }
    Rectangle { // Circle4
        id: bottom_first
        x: 480
        y: 440

        width: 80
        height: 80
        color: "black"
        radius: width / 2
    }
    Rectangle { // Circle5
        id: bottom_second
        x: 480
        y: 525

        width: 80
        height: 80
        color: "black"
        radius: width / 2
    }
    Rectangle { // Circle6
        id: bottom_third
        x: 480
        y: 610

        width: 80
        height: 80
        color: "green"
        radius: width / 2
    }

    property var lightColors: ["red", "yellow", "green"]
    property int currentColorIndex: 0
    property int state: 0

    function changeColorNormal() {
        switch (currentColorIndex%3){
            case 0:
                up_second.color = "black"
                up_third.color = "black"
                up_first.color = lightColors[currentColorIndex]
                bottom_second.color = "black"
                bottom_first.color = "black"
                bottom_third.color = lightColors[2-currentColorIndex]
                currentColorIndex = (currentColorIndex + 1) % 3
                break
            case 1:
                up_first.color = "black"
                up_third.color = "black"
                up_second.color = lightColors[currentColorIndex]
                bottom_third.color = "black"
                bottom_first.color = "black"
                bottom_second.color = lightColors[2-currentColorIndex]
                currentColorIndex = (currentColorIndex + 1) % 3
                break
            case 2:
                up_first.color = "black"
                up_second.color = "black"
                up_third.color = lightColors[currentColorIndex]
                bottom_second.color = "black"
                bottom_third.color = "black"
                bottom_first.color = lightColors[2-currentColorIndex]
                currentColorIndex = (currentColorIndex + 1) % 3
                break
            default:
                break
        }
    }

    function changeColorNight(){
        if (state==0){
            up_first.color = "black"
            up_third.color = "black"
            up_second.color = lightColors[1]
            bottom_third.color = "black"
            bottom_first.color = "black"
            bottom_second.color = lightColors[1]
            state = (state + 1) % 2
        }else{
            up_first.color = "black"
            up_third.color = "black"
            up_second.color = "black"
            bottom_third.color = "black"
            bottom_first.color = "black"
            bottom_second.color = "black"
            state = (state + 1) % 2
        }
    }

    Timer {
        id:timerNormal
        interval: 2000
        running: true
        repeat: true
        onTriggered: changeColorNormal()
    }
    Timer {
        id:timerNight
        interval: 2000
        running: true
        repeat: true
        onTriggered: changeColorNight()
    }

}
