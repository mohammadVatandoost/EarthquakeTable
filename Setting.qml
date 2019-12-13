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

       ColibrateList {}
       ColumnLayout {

           Button {
               Layout.alignment: Qt.AlignHCenter
               anchors.horizontalCenter: parent.horizontalCenter
               text: qsTr("Colibrate")
               highlighted: true
               Material.background: Material.Green
               onClicked: {BackEnd.colibrate()}
           }
       }
   }
}
