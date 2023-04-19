import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.11

Window {
    width: 700
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "#303446"
    Rectangle{
            x: 8
            y: 29
            id: rectangle
            height: 150
            width: 300
            radius: 35
            color: "#232634"
            Text {
                 id: radioFreqId
                 height: 64
                 text: qsTr("95.4")
                 color: "#c6d0f5"
                 font.pointSize: 38
                 anchors.horizontalCenterOffset: 0
                 font.family: Constants.font.family
                 anchors.topMargin: -154
                 anchors.horizontalCenter: parent.horizontalCenter
                 anchors.verticalCenter: parent.verticalCenter
                 SequentialAnimation {
                     id: animation

                     ColorAnimation {
                         id: colorAnimation1
                         target: rectangle
                         property: "color"
                         to: "#2294c6"
                         from: Constants.backgroundColor
                     }

                     ColorAnimation {
                         id: colorAnimation2
                         target: rectangle
                         property: "color"
                         to: Constants.backgroundColor
                         from: "#2294c6"
                     }
                 }
             }
        }


         Slider {
             id: sliderId
             x: 14
             y: 174
             width: 286
             height: 76
             from: 87.5
             value: 0.1
             to: 108.0
             stepSize: 0.1
             onValueChanged: {
                 console.log("slider")
                 TRANSMITTER.onSliderValueChanged(value)
             }
         }

         RadioButton {
             id: offButtonId
             x: 375
             y: 29
             text: "OFF"
             onClicked: {
                    console.log("OFF")
                    TRANSMITTER.onRadioButtonClick("")
                 }
         }

         RadioButton {
             id: ch1Id
             x: 375
             y: 78
             text: qsTr("CH 1")
             onClicked: {
                    console.log("CH1")
                    TRANSMITTER.onRadioButtonClick(95.7)
                 }
         }

         RadioButton {
             id: ch2Id
             x: 375
             y: 132
             text: qsTr("CH 2")
             onClicked: {
                    console.log("CH2")
                    TRANSMITTER.onRadioButtonClick(99.0)
                 }
         }

         RadioButton {
             id: radioButton3
             x: 375
             y: 186
             text: qsTr("CH 3")
             onClicked: {
                    console.log("CH3")
                    TRANSMITTER.onRadioButtonClick(104.2)
                 }
         }

         Button {
             id: button
             x: 48
             y: 256
             width: 97
             height: 57
             font.pointSize: 38
             text: qsTr("←")
             onClicked: {
                    console.log("Back Arrow")
                    TRANSMITTER.onArrowClickMinus(0.5)
                 }
         }

         Button {
             id: button1
             x: 173
             y: 256
             width: 98
             height: 57
             font.pointSize: 38
             text: qsTr("→")
             onClicked: {
                    console.log("Add Arrow")
                    TRANSMITTER.onArrowClickAdd(0.5)
                 }
         }

         Connections{
             id: cppConnection
             target: TRANSMITTER
             ignoreUnknownSignals: true

             function onSliderValue(new_value){
                 radioFreqId.text = new_value
             }

             function onRadioValue(new_value){
                 radioFreqId.text = new_value
             }

             function onArrowValueAdd(new_value){
                 radioFreqId.text = (parseFloat(radioFreqId.text) + new_value).toFixed(1)
             }

             function onArrowValueMinus(new_value){
                  radioFreqId.text = (parseFloat(radioFreqId.text) - new_value).toFixed(1)
             }

         }

}
