import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Shapes 1.10
//import ColibrateItemModel 1.0
//import QtQuick.VirtualKeyboard 2.2

ColumnLayout {
    width: parent.width/2
    RowLayout {
        width: parent.width
        Layout.alignment: Qt.AlignHCenter
        spacing: 40
        ColumnLayout {
            width: parent.width/2
            Label {
                Layout.alignment: Qt.AlignHCenter
                text: "Structure"
                topPadding: 10
                bottomPadding: 10
                font.pixelSize: 27
            }
//            ComboBox {
//                id: comboTimesetSelectedColibrate

//                Layout.alignment: Qt.AlignHCenter
//                width: 200
//                model: ColibrateItemModel//BackEnd.getColibratesNames()
//                currentIndex: 0
//                onActivated: BackEnd.setSelectedColibrate(index)
//            }
            DropDownModel {
                Layout.alignment: Qt.AlignHCenter
                id: comboTime
                model: ColibrateItemModel
                textRole: "Name"
                onActivated: BackEnd.setSelectedColibrate(currentIndex)
                Component.onCompleted: {
                    BackEnd.setSelectedColibrate(comboTime.currentIndex);
                }

            }
        }
        ColumnLayout {
            width: parent.width/2
            Label {
                Layout.alignment: Qt.AlignHCenter
                text: "Floor Number"
                topPadding: 10
                bottomPadding: 10
                font.pixelSize: 27
            }
            ComboBox {
//                id: comboTime
                Layout.alignment: Qt.AlignHCenter
                width: 200
                model: ["1", "2", "3"]
                currentIndex: 2
                onActivated: {
                    if(currentIndex === 2) {
                        floor3.visible = true;
                        floor2.visible = true;
                        floor1.visible = true;
                        padding1.visible = true;
                        padding2.visible = true;
                        building.height = 430;
                        floor3.anchors.top = paddingTop.bottom;
                        padding1.anchors.top = floor3.bottom;
                        floor2.anchors.top = padding1.bottom;
                        padding2.anchors.top = floor2.bottom;
                        floor1.anchors.top = padding2.bottom;
                    } else if(currentIndex === 1) {
                        floor3.visible = false;
                        floor2.visible = true;
                        floor1.visible = true;
                        padding1.visible = false;
                        padding2.visible = true;
                        building.height = 325;
                        floor2.anchors.top = paddingTop.bottom;
                        padding2.anchors.top = floor2.bottom;
                        floor1.anchors.top = padding2.bottom;
                    } else if(currentIndex === 0) {
                        padding1.visible = false;
                        padding2.visible = false;
                        floor3.visible = false;
                        floor2.visible = false;
                        floor1.visible = true;
                        building.height = 220;
                        floor1.anchors.top = paddingTop.bottom;
                    }
                }
            }
        }
    }


       Rectangle {
           id:building
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
//       Label {
//           Layout.alignment: Qt.AlignHCenter
//           text: "Structure"
//           topPadding: 10
//           bottomPadding: 10
//           font.pixelSize: 27
//       }
       Row { // The "Row" type lays out its child items in a horizontal line
//           anchors.top: building.bottom
           anchors.top: building.bottom
           Layout.alignment: Qt.AlignHCenter
           width: parent.width/2
           spacing: 20 // Places 20px of space between items

           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
           OripLine{}
       }

       Timer {
           id: refreshTimer
           interval: 500//30 // 60 Hz
           running: true
           repeat: true
           onTriggered: {
               floor0.setSensorValue(BackEnd.getFloorData(0));
               floor1.setSensorValue(BackEnd.getFloorData(1));
               floor2.setSensorValue(BackEnd.getFloorData(2));
               floor3.setSensorValue(BackEnd.getFloorData(3));
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
