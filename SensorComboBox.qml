import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4

ComboBox {
    id: root
    property int sensorId: 0
    property var sensorTypes: [ "off", "Floor1", "Floor2", "Floor3"]
    function getIndex() {
        var sensorType = SensorsList.getSensorInfo(root.sensorId);
        for(var i=0; i< sensorTypes.length; i++) {
            if(sensorTypes[i] === sensorType) {
                return i;
            }
        }
        return 0;
    }
    function setSensorId(temp) {
        sensorId = temp;
    }
    width: 200
    model: sensorTypes
    currentIndex: getIndex()
    onActivated: SensorsList.setSensorInfo(root.sensorId, sensorTypes[currentIndex])
}
