import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.VirtualKeyboard 2.2

Page {
    id: root
    width: window.width
    Grid {
        columns: 2
        width: parent.width
        spacing: 2
        topPadding: 10
        rightPadding: 10
        leftPadding: 10

       ColumnLayout {
           width: parent.width/2
               ChooseFile {}
               Label {
                 Layout.alignment: Qt.AlignHCenter
                 text: "Motor speed"
                 font.pixelSize: 22
                 anchors.horizontalCenter: parent.horizontalCenter
               }
               Text {
                   Layout.alignment: Qt.AlignHCenter
                   text: qsTr("1000rpm")
                   anchors.horizontalCenter: parent.horizontalCenter
               }
               Button {
                   Layout.alignment: Qt.AlignHCenter
                   anchors.horizontalCenter: parent.horizontalCenter
                   text: qsTr("Colibrate")
                   highlighted: true
                   Material.background: Material.Green
               }
               Label {
                 Layout.alignment: Qt.AlignHCenter
                 text: "Positioning Something"
                 font.pixelSize: 22
                 anchors.horizontalCenter: parent.horizontalCenter
               }
               RowLayout {
                   Layout.alignment: Qt.AlignHCenter
                   Button {
                       Layout.alignment: Qt.AlignHCenter
//                       anchors.horizontalCenter: parent.horizontalCenter
                       text: qsTr("left")
                       highlighted: true
                       Material.background: Material.Blue
                   }
                   Button {
                       Layout.alignment: Qt.AlignHCenter
//                       anchors.horizontalCenter: parent.horizontalCenter
                       text: qsTr("right")
                       highlighted: true
                       Material.background: Material.Blue
                   }
               }
       }
       ColumnLayout {
           width: parent.width/2

//           Rectangle {
//               border.width: 1
//               border.color: "red"
//              ColumnLayout {
              Rectangle {
                 width: 0.8*parent.width
                 height: 250
                 border.color: "black"
                 border.width: 5
                 Layout.alignment: Qt.AlignHCenter
                 Material.elevation: 6

//                 Rectangle {
//                     id: padding3
//                     height: 5
//                     width: parent.width
//                     anchors.topMargin: 100
                 //                     color: "red"
//                 }
                 Label {
                   id: ax1Label
                   text: "Ax1"
                   topPadding: 10
                   font.pixelSize: 22
                   Layout.alignment: Qt.AlignHCenter
                   anchors.horizontalCenter: parent.horizontalCenter
                 }
                 Text {
                     id: ax1
                     anchors.top: ax1Label.bottom
                     Layout.alignment: Qt.AlignHCenter
                     text: qsTr("12.36")
                     font.pixelSize: 25
                     bottomPadding: 10
                     anchors.horizontalCenter: parent.horizontalCenter
                 }
                 Rectangle {
                     id: padding1
                     anchors.top: ax1.bottom
                     height: 5
                     width: parent.width
                     color: "black"
                 }
                 Label {
                    id: ax2Label
                    anchors.top: padding1.bottom
                    text: "Ax2"
                    font.pixelSize: 22
                    topPadding: 10
                    Layout.alignment: Qt.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                 }
                 Text {
                    id: ax2
                    anchors.top: ax2Label.bottom
                    Layout.alignment: Qt.AlignHCenter
                    text: qsTr("12.36")
                    font.pixelSize: 25
                    bottomPadding: 10
                    anchors.horizontalCenter: parent.horizontalCenter
                 }
                 Rectangle {
                     id: padding2
                     anchors.top: ax2.bottom
                     height: 5
                     width: parent.width
                     color: "black"
                 }
                 Label {
                    id: ax3Label
                    anchors.top: padding2.bottom
                    topPadding: 10
                    text: "Ax3"
                    font.pixelSize: 22
                    Layout.alignment: Qt.AlignHCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                 }
                 Text {
                    id: ax3
                    anchors.top: ax3Label.bottom
                    Layout.alignment: Qt.AlignHCenter
                    text: qsTr("12.36")
                    font.pixelSize: 25
                    anchors.horizontalCenter: parent.horizontalCenter
                 }
              }

              Pane {
                  id: comboBoxes
                  implicitHeight: 100
                  implicitWidth: parent.width*0.9
                  Material.elevation: 6

                  RowLayout {
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
                  }
              }

       }

   }
}
