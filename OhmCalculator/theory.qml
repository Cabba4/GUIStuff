import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true

    Text {
        id: info
        text: qsTr("Ohm's law states that the current through a conductor
between two point is directly proportional to the
voltage across the two points.Introducing the constant
of proportionality, the resistance, one arrives at
the usual mathematical equation that describes this
relationship:

I=V/R")
        color: "blue"
    }
}
