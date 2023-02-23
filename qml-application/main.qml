import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 800
    height: 600
    visible: true
    title: qsTr("Hello World")

    Item {
        id: __materialLibrary__
    }

    Button {
        id: button
        text: qsTr("My Button")
        x: 100
        y: 65
        width: 100
        height: 50

        onClicked:
        {
            label.text ="Clicked";
        }
    }

    Label {
        id: label
        text: qsTr("My Text")
    }


}
