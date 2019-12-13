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
    implicitWidth: parent.width
    Material.elevation: 5
    Layout.alignment: Qt.AlignHCenter
    property string motorSpeed: "0 rpm"
        RowLayout {
            width: parent.width
            Label {
              id: label
              Layout.alignment: Qt.AlignLeft
              anchors.left: parent.left
              text: "Motor speed : "
              font.pixelSize: 18
              anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
                Layout.leftMargin: 140
                text: qsTr(motorSpeend)
                font.pixelSize: 22
                anchors.horizontalCenter: parent.horizontalCenter
            }

        }
}
