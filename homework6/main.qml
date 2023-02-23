import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
        height: 480
        visible: true
        color: "#ffffff"
        title: qsTr("Hello World")

    Button {
        id: onButton
        x: -5
        y: 7
        visible: true
        text: qsTr("Button")
        layer.smooth: true
        rotation: -170.961
    }

    Button {
        id: offButton
        x: -78
        y: -12
        text: qsTr("Button")
    }
}
