import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: txt_box
        text: "Start Text"
        anchors.verticalCenterOffset: -170
        anchors.horizontalCenterOffset: -204
        anchors.centerIn: parent
    }

    Button {
        id: button
        text: qsTr("My Button")
        anchors.verticalCenterOffset: -118
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: -192
        onClicked:
        {
            myapp.func_btn_clk();
        }

    }

    Connections {
        target:myapp
        ignoreUnknownSignals: true
        function onSendMess(text_box_str)
        {
            txt_box.text = text_box_str
        }
    }
}
