/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 2.15
import QtQuick.Controls 2.15
import RadioExercise 1.0
import QtQuick.Studio.Components 1.0

Rectangle {
    id: rectangle
    width: Constants.width
    height: Constants.height

    color: "#303446"
    Rectangle{
        x: 8
        y: 29
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
         value: 0.5
     }

     RadioButton {
         id: offButtonId
         x: 375
         y: 29
         text: qsTr("OFF")
     }

     RadioButton {
         id: ch1Id
         x: 375
         y: 78
         text: qsTr("CH 1")
     }

     RadioButton {
         id: ch2Id
         x: 375
         y: 132
         text: qsTr("CH 2")
     }

     RadioButton {
         id: radioButton3
         x: 375
         y: 186
         text: qsTr("CH 3")
     }

     Button {
         id: button
         x: 48
         y: 256
         width: 97
         height: 57
         font.pointSize: 38
         text: qsTr("←")
     }

     Button {
         id: button1
         x: 173
         y: 256
         width: 98
         height: 57
         font.pointSize: 38
         text: qsTr("→")
     }



     states: [
         State {
             name: "clicked"
             when: button.checked
         }
     ]
}
