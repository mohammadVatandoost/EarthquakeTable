import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.VirtualKeyboard 2.2

RowLayout {
    width: parent.width*0.95
    Layout.alignment: Qt.AlignHCenter
    spacing: 10
    ComboBox {
        id: comboBoxGas
        property var gasTypes: [ "NO", "CO", "SO2", "O2", "BTEX", "VOC" ]
        function getIndex() {
//                              var gasType = SensorsList.getGasTypeValue(root.sensorId)
            var gasType = 1;
            for(var i=0; i< gasTypes.length; i++) {
                if(gasTypes[i] === gasType) {
                    return i;
                }
            }
            return 0;
        }

        width: 200
        model: gasTypes
        currentIndex: getIndex()
//                          onActivated:SensorsList.setGasTypeValue(root.sensorId, gasTypes[currentIndex])
    }
    ComboBox {
        id: comboBoxGas2
        property var gasTypes: [ "NO", "CO", "SO2", "O2", "BTEX", "VOC" ]
        function getIndex() {
//                              var gasType = SensorsList.getGasTypeValue(root.sensorId)
            var gasType = 1;
            for(var i=0; i< gasTypes.length; i++) {
                if(gasTypes[i] === gasType) {
                    return i;
                }
            }
            return 0;
        }

        width: 200
        model: gasTypes
        currentIndex: getIndex()
//                          onActivated:SensorsList.setGasTypeValue(root.sensorId, gasTypes[currentIndex])
    }
    ComboBox {
        id: comboBoxGas3
        property var gasTypes: [ "NO", "CO", "SO2", "O2", "BTEX", "VOC" ]
        function getIndex() {
//                              var gasType = SensorsList.getGasTypeValue(root.sensorId)
            var gasType = 1;
            for(var i=0; i< gasTypes.length; i++) {
                if(gasTypes[i] === gasType) {
                    return i;
                }
            }
            return 0;
        }

        width: 200
        model: gasTypes
        currentIndex: getIndex()
//                          onActivated:SensorsList.setGasTypeValue(root.sensorId, gasTypes[currentIndex])
    }
}
