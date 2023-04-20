import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MenuBar {
        id: menuBar
        width: 640
        Menu {
            title: qsTr("&Calculate")
            Action {
                text: qsTr("&Resistance")
                onTriggered: {
                    var component = Qt.createComponent("resistance.qml")
                    var window = component.createObject(root)
                    if (window !== null && window instanceof Window) {
                        window.show();
                    }
                }
            }
            Action {
                text: qsTr("&Voltage")
                onTriggered: {
                    var component = Qt.createComponent("voltage.qml")
                    var window = component.createObject("root")
                    if (window !== null && window instanceof Window) {
                        window.show();
                    }
                }
            }
            Action {
                text: qsTr("&Current")
                onTriggered: {
                    var component = Qt.createComponent("current.qml")
                    var window = component.createObject("root")
                    if (window !== null && window instanceof Window) {
                        window.show();
                    }
                }
            }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
        Menu {
            title: qsTr("&Info")
            Action {
                text: qsTr("&Theory")
                onTriggered: {
                    var component = Qt.createComponent("theory.qml")
                    var window = component.createObject("root")
                    if (window !== null && window instanceof Window) {
                        window.show();
                    }
                }
            }
            Action {
                text: qsTr("&Formula")
                onTriggered: {
                    var component = Qt.createComponent("formula.qml")
                    var window = component.createObject("root")
                    if (window !== null && window instanceof Window) {
                        window.show();
                    }
                }
            }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
    }
}
