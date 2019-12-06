import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.VirtualKeyboard 2.2

Pane {
    id: root
    implicitHeight: 100
    implicitWidth: parent.width*0.9
    Layout.alignment: Qt.AlignHCenter
//    anchors.topMargin: 20
    anchors.horizontalCenter: parent.horizontalCenter
    property int sensorId: 0
    property double sensorValue: 11
    function setSensorId(temp) {
        sensorId = temp;
    }

    RowLayout {
//       anchors.topMargin: 20
       width: parent.width
       ColumnLayout {
         width: parent.width*2/3
         Label {
           id: ax1Label
           text: qsTr("Ax"+root.sensorId)
           topPadding: 10
           font.pixelSize: 22
           Layout.alignment: Qt.AlignHCenter
           anchors.horizontalCenter: parent.horizontalCenter
         }
         Text {
            id: ax1
//            anchors.top: ax1Label.bottom
            Layout.alignment: Qt.AlignHCenter
            text: qsTr(root.sensorValue)
            font.pixelSize: 25
            bottomPadding: 10
            anchors.horizontalCenter: parent.horizontalCenter
         }
       }
       SensorComboBox {
         Layout.alignment: Qt.AlignRight
         Component.onCompleted: {
             setSensorId(root.sensorId);
         }
       }
    }
}
