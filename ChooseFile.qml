import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.VirtualKeyboard 2.2
import QtQuick.Dialogs 1.0

Pane {
    id: root
    implicitHeight: 180
    implicitWidth: parent.width
    Material.elevation: 5
    Layout.alignment: Qt.AlignHCenter
    property string fileUrl: ""
    ColumnLayout {
        width: parent.width
        spacing: 15
        RowLayout {
            width: parent.width
            Label {
              Layout.alignment: Qt.AlignLeft
              anchors.left: parent.left
              text: "File :"
              font.pixelSize: 18
            }
            Text {
                Layout.leftMargin: 80
                font.pixelSize: 22
                text: qsTr(fileUrl)
            }
        }
         Button {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Choose File")
                highlighted: true
                Material.background: Material.Green
                onClicked: {fileDialog.open();}
         }
         Button {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Start")
                highlighted: true
                Material.background: Material.Green
                onClicked: {BackEnd.runSimulation();}
         }

    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrl)
            var temp = ""+fileDialog.fileUrl;
//            temp.lastIndexOf("/");
//            console.log(temp.slice(temp.lastIndexOf("/")+1, temp.length))
            root.fileUrl = temp.slice(temp.lastIndexOf("/")+1, temp.length)
             BackEnd.readFile(fileDialog.fileUrl);
        }
        onRejected: {
            console.log("Canceled")
        }
//        Component.onCompleted: visible = true
    }
}
