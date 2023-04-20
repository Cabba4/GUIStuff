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
            id: currentInput
            placeholderText: "Enter Current (A)"
        }

        Button {
            text: "Calculate Resistance (Ω)"
            onClicked: {
                var voltage = parseFloat(voltageInput.text)
                var current = parseFloat(currentInput.text)

                if (!isNaN(voltage) && !isNaN(current) && current !== 0) {
                    var resistance = voltage / current
                    resultLabel.text = "Resistance: " + resistance.toFixed(2) + " Ω"
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
