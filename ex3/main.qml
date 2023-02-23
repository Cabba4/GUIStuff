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
        text: "0"
        anchors.verticalCenterOffset: -170
        anchors.horizontalCenterOffset: -204
        anchors.centerIn: parent
        Connections {
            target: counter
            onValueChanged:{
                txt_box.text = value;
            }
        }
    }

    Button {
        id: button1
        x: 250
        y: 200
        width: 100
        height: 100
        text: qsTr("-")
        onClicked:
        {
            counter.decrement();
        }

    }

    Button {
        id: button2
        x: 140
        y: 200
        width: 100
        height: 100
        text: qsTr("My Button")
        onClicked:
        {
            myclass.func_btn_clk();
        }

    }

    Button {
        id: button3
        x: 30
        y: 200
        width: 100
        height: 100
        text: qsTr("+")
        onClicked:
        {
            myclass.increment();
        }

    }

    Connections {
        target:myclass
        ignoreUnknownSignals: true
        function onSendMess(text_box_str)
        {
            txt_box.text = text_box_str
        }

    }

}
