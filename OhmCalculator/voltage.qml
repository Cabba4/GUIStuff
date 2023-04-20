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
            id: currentInput
            placeholderText: "Enter Current (A)"
        }

        TextField {
            id: resistanceInput
            placeholderText: "Enter Resistance (Ω)"
        }

        Button {
            text: "Calculate Voltage (V)"
            onClicked: {
                var current = parseFloat(currentInput.text)
                var resistance = parseFloat(resistanceInput.text)

                if (!isNaN(current) && !isNaN(resistance) && resistance !== 0) {
                    var voltage = current * resistance
                    resultLabel.text = "Voltage: " + voltage.toFixed(2) + " V"
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
