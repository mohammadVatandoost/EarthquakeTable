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
    implicitHeight: 300
    implicitWidth: parent.width*0.95
    Material.elevation: 5
    Layout.alignment: Qt.AlignHCenter
    Layout.topMargin: 21
    property string fileUrl: ""
    ColumnLayout {
        width: parent.width
        spacing: 15
//        RowLayout {
//            width: parent.width
            Label {
              id: label
              Layout.alignment: Qt.AlignLeft
              anchors.left: parent.left
              text: "Ground Motion"
              font.pixelSize: 18
            }
            TextEdit {
                id: textEdit
//                anchors.top: label.bottom
//                Layout.topMargin: 10
//                Layout.bottomMargin: 10
                width: 250
                height: 50
                font.pointSize: 22
                inputMethodHints: Qt.ImhDigitsOnly
                property string placeholderText: "Name"
                onActiveFocusChanged: BackEnd.openKeyboard()
                Text {
                    text: textEdit.placeholderText
                    color: "#aaa"
                    font.pointSize: 22
                    visible: !textEdit.text && !textEdit.activeFocus // <----------- ;-)
                }
            }
            Text {
                Layout.leftMargin: 80
                font.pixelSize: 22
                text: qsTr(fileUrl)
                visible: fileUrl == "" ? false : true
            }
//        }
         Button {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Choose File")
                highlighted: true
                Material.background: Material.Blue
                onClicked: {fileDialog.open();}
         }
         ComboBox {
             id: comboTime
             Layout.alignment: Qt.AlignHCenter
             property int floorNum: 0
             property var timeSteps: [ "5ms", "10ms", "15ms", "20ms"]
             width: 200
             model: timeSteps
             currentIndex: 1
             onActivated: BackEnd.setTimeStep(timeSteps[currentIndex])
         }
         Button {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Save")
                highlighted: true
                Material.background: Material.Green
                onClicked: {BackEnd.saveGroundMotion(textEdit.text);}
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
