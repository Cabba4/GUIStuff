import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Extras 1.4
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Window {
    width: 400
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item{
        id: root
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -50
        anchors.horizontalCenterOffset: 0
        property real value: 0

        width: 200
        height: 200

        Image{ //Actual Gauge
            width: 200
            height: 200
            source: "background.png"
        }
        Image{ //Needle
            id: needle
            x: 40
            y: 40
            width: 120
            height: 120

            antialiasing: true
            source: "needle.png"
            transform: Rotation{
                id: needleRotation
                origin.x: needle.width / 2
                origin.y: needle.height / 2

                angle: Math.min(Math.max(0, value*2.6), 360)
                Behavior on angle{
                    SpringAnimation{
                        spring: 1.4
                        damping: .15
                    }
                }
            }
        }
        Slider {
            id: slider1
            x: 0
            y: 250
            from: 0
            value: 180
            to: 360

            onValueChanged: {
                TRANSMITTER.onSliderValueChanged(value)
            }
        }
        Connections{
            id: cppConnection
            target: TRANSMITTER
            ignoreUnknownSignals: true

            function onSliderValue(new_value){
                needleRotation.angle = new_value
                console.log(new_value)
            }
        }
    }
}
