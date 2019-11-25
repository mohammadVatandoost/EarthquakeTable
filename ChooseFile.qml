import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.VirtualKeyboard 2.2


Pane {
    id: comboBoxes
    implicitHeight: 100
    implicitWidth: parent.width*0.95
    Material.elevation: 5
    Layout.alignment: Qt.AlignHCenter
    RowLayout {
        width: parent.width
        spacing: 5
        ColumnLayout {
            width: parent.width/2
            Layout.alignment: Qt.AlignHCenter
            Label {
              Layout.alignment: Qt.AlignHCenter
              anchors.horizontalCenter: parent.horizontalCenter
              text: "File"
              font.pixelSize: 22
            }
            Text {
                Layout.alignment: Qt.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("test.txt")
            }
        }
        ColumnLayout {
            width: parent.width/2
            Rectangle {
                width: parent.width
                color: "red"
                height: 70
            }

//            Button {
//                Layout.alignment: Qt.AlignRight
//                text: qsTr("Choose File")
////                anchors.horizontalCenter: parent.horizontalCenter
//                highlighted: true
//                Material.background: Material.Green
//            }
        }
    }
}
