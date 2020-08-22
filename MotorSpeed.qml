import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4


Pane {
    id: root
    implicitHeight: 250

    implicitWidth: parent.width
    Material.elevation: 5
    Layout.alignment: Qt.AlignHCenter
    property string motorSpeed: "0 rpm"

        ColumnLayout {
            width: parent.width
            spacing: 25

            Label {
              id: label
              Layout.alignment: Qt.AlignHCenter
              text: "Motor Frequency"
              font.pixelSize: 22
              topPadding: 30
//              anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr(root.motorSpeed)
                font.pixelSize: 27
//                anchors.horizontalCenter: parent.horizontalCenter
                bottomPadding: 20
            }

            Button {
                   Layout.alignment: Qt.AlignHCenter
                   text: qsTr("Store Sensor Data Manually")
                   highlighted: true
                   Material.background: Material.Green
                   onClicked: {
                       BackEnd.storeSensorData();
                   }
//                   enabled: root.auth
            }

        }

    Timer {
        id: refreshTimer
        interval: 500
        running: true
        repeat: true
        onTriggered: {
          root.motorSpeed = BackEnd.getMotorSpeed();
        }
    }
}
