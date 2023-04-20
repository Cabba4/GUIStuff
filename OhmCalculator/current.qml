import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.15

Window {
    id: root
    width: 640
    height: 480
    visible: true

    Column {
        spacing: 10
        anchors.centerIn: parent

        TextField {
            id: voltageInput
            placeholderText: "Enter Voltage (V)"
        }

        TextField {
            id: resistanceInput
            placeholderText: "Enter Resistance (Ω)"
        }

        Button {
            text: "Calculate Current (A)"
            onClicked: {
                var voltage = parseFloat(voltageInput.text)
                var resistance = parseFloat(resistanceInput.text)

                if (!isNaN(voltage) && !isNaN(resistance) && resistance !== 0) {
                    var current = voltage / resistance
                    resultLabel.text = "Current: " + current.toFixed(2) + " A"
                } else {
                    resultLabel.text = "Invalid input. Please enter valid values."
                }
            }
        }

        Label {
            id: resultLabel
            text: ""
        }
    }

}
