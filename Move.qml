import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.VirtualKeyboard 2.2


Pane {
    implicitHeight: 100
    implicitWidth: parent.width
    Material.elevation: 5
    Layout.alignment: Qt.AlignHCenter
    ColumnLayout {
        width: parent.width
        spacing: 5
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
                onClicked: {BackEnd.moveRight()}
            }
            Button {
                Layout.alignment: Qt.AlignHCenter
//                       anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("right")
                highlighted: true
                Material.background: Material.Blue
                onClicked: {BackEnd.moveLeft()}
            }
        }
    }
}
