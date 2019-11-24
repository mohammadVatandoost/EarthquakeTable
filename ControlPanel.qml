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
           ColumnLayout {
               Label {
                 Layout.alignment: Qt.AlignHCenter
                 text: "File"
                 font.pixelSize: 22
               }
               Text {
                   Layout.alignment: Qt.AlignHCenter
                   text: qsTr("test.txt")
               }
               Button {
                   Layout.alignment: Qt.AlignHCenter
                   text: qsTr("Choose File")
                   highlighted: true
                   Material.background: Material.Green
               }
               Label {
                 Layout.alignment: Qt.AlignHCenter
                 text: "Motor speed"
                 font.pixelSize: 22
               }
               Text {
                   Layout.alignment: Qt.AlignHCenter
                   text: qsTr("1000rpm")
               }
               Button {
                   Layout.alignment: Qt.AlignHCenter
                   text: qsTr("Colibrate")
                   highlighted: true
                   Material.background: Material.Green
               }
           }
       }
       ColumnLayout {
           width: parent.width/2

//           Rectangle {
//               border.width: 1
//               border.color: "red"
//              ColumnLayout {
                 Label {
                   text: "Ax1"
                   font.pixelSize: 22
                   Layout.alignment: Qt.AlignHCenter
                 }
                 Text {
                     Layout.alignment: Qt.AlignHCenter
                     text: qsTr("12.36")
                 }
                 Label {
                    text: "Ax1"
                    font.pixelSize: 22
                    Layout.alignment: Qt.AlignHCenter
                 }
                 Text {
                    Layout.alignment: Qt.AlignHCenter
                    text: qsTr("12.36")
                 }
                 Label {
                    text: "Ax1"
                    font.pixelSize: 22
                    Layout.alignment: Qt.AlignHCenter
                 }
                 Text {
                    Layout.alignment: Qt.AlignHCenter
                    text: qsTr("12.36")
                 }
              }

//           }
//       }
   }
}
