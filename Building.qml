import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.VirtualKeyboard 2.2

ColumnLayout {
    width: parent.width/2
    Label {
        Layout.alignment: Qt.AlignHCenter
        text: "Structure"
        topPadding: 10
        bottomPadding: 10
        font.pixelSize: 27
    }
       Rectangle {
          width: 0.8*parent.width
          height: 430
          border.color: "black"
          border.width: 5
          Layout.alignment: Qt.AlignHCenter
          Material.elevation: 6

          Rectangle {
              id: paddingTop
              anchors.top: parent.top
              height: 5
              width: parent.width
              color: "black"
          }
          Floor {
              id: floor3
              anchors.top: paddingTop.bottom
              Component.onCompleted: {
                  setSensorId(0);
                  setFloorNum(3);
              }
          }
          Rectangle {
              id: padding1
              anchors.top: floor3.bottom
              height: 5
              width: parent.width
              color: "black"
          }
          Floor {
              id: floor2
              anchors.top: padding1.bottom
              Component.onCompleted: {
                  setFloorNum(2);
              }
          }
          Rectangle {
              id: padding2
              anchors.top: floor2.bottom
              height: 5
              width: parent.width
              color: "black"
          }
          Floor {
              id: floor1
              anchors.top: padding2.bottom
              Component.onCompleted: {
                  setFloorNum(1);
              }
          }
          Rectangle {
              id: padding3
              anchors.top: floor1.bottom
              height: 5
              width: parent.width
              color: "black"
          }
          Floor {
              id: floor0
              anchors.top: padding3.bottom
              Component.onCompleted: {
                  setFloorNum(0);
              }
          }
       }

       Timer {
           id: refreshTimer
           interval: 500//30 // 60 Hz
           running: true
           repeat: true
           onTriggered: {
               floor0.sensorValue =  SensorsList.getSensorData(0);
               floor1.sensorValue =  SensorsList.getSensorData(1);
               floor2.sensorValue =  SensorsList.getSensorData(2);
               floor3.sensorValue =  SensorsList.getSensorData(3);
           }
       }
//       SetSensorFloor {}
//       Button {
//              Layout.alignment: Qt.AlignHCenter
//              text: qsTr("Set Sensor")
////                anchors.horizontalCenter: parent.horizontalCenter
//              highlighted: true
//              Material.background: Material.Green
//              onClicked: {BackEnd.setSensorInfo();}
//       }
}
