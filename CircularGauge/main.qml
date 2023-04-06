import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Extras 1.4
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4


Window {
    width: 640
    height: 480
    visible: true


    CircularGauge {
        id: circular_gauge1
        x: 300
        y: 107
        width: 300
        minimumValue: 0
        maximumValue: 5
        value: 1
        tickmarksVisible: true


        style: CircularGaugeStyle {
           labelStepSize: 0.5

           tickmarkLabel:  Text {
               font.pixelSize: Math.max(6, outerRadius * 0.1)
               text: styleData.value
               color: styleData.value >= 3 ? "#228B22" : "#0000FF"
               antialiasing: true
           }

           tickmark: Rectangle {
               visible: styleData.value < 5 || styleData.value % 1 == 0
               implicitWidth: outerRadius * 0.02
               antialiasing: true
               implicitHeight: outerRadius * 0.06
               color: styleData.value >= 3 ? "#228B22" : "#0000FF"
           }
        }

        Text {
            id: indexText
            text: circular_gauge1.value.toFixed(1)
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            color: "black"
            font.pixelSize: 30
        }
    }

    Gauge {
        id: gauge1
        x: 100
        y: 107
        minimumValue: 0
        value: 1
        maximumValue: 5
        tickmarkStepSize: 0.5

        style: GaugeStyle{

            valueBar: Rectangle{
               implicitWidth: 16
               color: gauge1.value >= 3 ? "#228B22" : "#0000FF"
            }
        }
    }

    Slider {
        id: slider1
        x: 100
        y: 350
        from: 0
        value: 1
        to: 5
        onValueChanged: {
            circular_gauge1.value = slider1.value
            gauge1.value = slider1.value
        }
    }
}
