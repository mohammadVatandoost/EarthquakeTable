import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4

Pane {
    id: root
    implicitHeight: 100
    implicitWidth: parent.width*0.9
    Layout.alignment: Qt.AlignHCenter
//    anchors.topMargin: 20
    anchors.horizontalCenter: parent.horizontalCenter
    property int sensorId: 0
    property int floorNum: 0
    property double sensorValue: 11
    function setSensorId(temp) {
        sensorId = temp;
    }

    function setFloorNum(temp) {
        floorNum = temp;
    }
    function setSensorValue(temp) {
       if(temp === 255255) {
           ax1.text = "-";
       } else if(temp === 32767) {
           ax1.text = "DC";
       } else {
           ax1.text = temp;
       }
    }

    RowLayout {
//       anchors.topMargin: 20
       width: parent.width
       ColumnLayout {
         width: parent.width*2/3
         Label {
           id: ax1Label
           text: qsTr("Floor "+root.floorNum)
           topPadding: 10
           font.pixelSize: 22
           Layout.alignment: Qt.AlignHCenter
           anchors.horizontalCenter: parent.horizontalCenter
         }
         Text {
            id: ax1
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("-")
            font.pixelSize: 25
            bottomPadding: 10
            anchors.horizontalCenter: parent.horizontalCenter
         }
       }
       SensorComboBox {
         Layout.alignment: Qt.AlignRight
         Component.onCompleted: {
             setFloorNum(root.floorNum);
         }
       }
    }
}
