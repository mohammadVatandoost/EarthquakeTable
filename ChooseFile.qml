import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.0

Pane {
    id: root
    implicitHeight: 610
    implicitWidth: parent.width*0.95
    Material.elevation: 5
    Layout.alignment: Qt.AlignHCenter
    Layout.topMargin: 21
    property string fileName: ""
    property bool auth: false
    function setAuth(temp) {root.auth = temp;}
    ColumnLayout {
        width: parent.width
        spacing: 15
//        RowLayout {
//            width: parent.width
            Label {
              id: label
              Layout.alignment: Qt.AlignHCenter
//              anchors.left: parent.left
              text: "Ground Motions"
              font.pixelSize: 18
            }
            TextEdit {
                id: textEdit
//                anchors.top: label.bottom
//                Layout.topMargin: 10
//                Layout.bottomMargin: 10
                width: 250
                height: 40
                font.pointSize: 18
//                inputMethodHints: Qt.ImhDigitsOnly
                property string placeholderText: "Name"
//                onActiveFocusChanged: BackEnd.openKeyboard()
                Text {
                    text: textEdit.placeholderText
                    color: "#aaa"
                    font.pointSize: 18
                    visible: !textEdit.text && !textEdit.activeFocus // <----------- ;-)
                }
            }

            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                Text {
                    Layout.rightMargin: 80
                    font.pixelSize: 22
                    text: qsTr(root.fileName)
                    visible: root.fileName == "" ? false : true
                }
                Button {
                       Layout.alignment: Qt.AlignHCenter
                       text: qsTr("Choose File")
                       highlighted: true
                       Material.background: Material.Blue
                       onClicked: {
//                           if(FileItemsModel.isUSBDrive()) {
//                               FileItemsModel.refreshDirectory();
//                               fileDialogPopup.open();
//                           } else {
//                               notify.open();
//                               notify.message = "No USB Drive Connected";
//                               notify.trigerTime();
//                           }

                           fileDialog.open();
                       }
                       enabled: root.auth
                }
            }


//        }

         RowLayout {
             Layout.alignment: Qt.AlignHCenter
             spacing: 10
             Text {
                 font.pixelSize: 18
                 text: qsTr("Time step")
             }
             ComboBox {
                 id: comboTime
                 Layout.alignment: Qt.AlignHCenter
                 property int floorNum: 0
                 property var timeSteps: [ "5 ms", "10 ms", "15 ms", "20 ms"]
                 width: 200
                 model: timeSteps
                 currentIndex: 1
                 onActivated: BackEnd.setTimeStep(timeSteps[currentIndex])
             }
         }


         Button {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Add")
                highlighted: true
                Material.background: Material.Green
                onClicked: {
                   if( BackEnd.saveGroundMotion(textEdit.text) === 1 ) {
                       popup.open();
                   }else {console.log("******Dile is wrong");}
                }
                enabled: root.auth
         }
         Label {
           Layout.alignment: Qt.AlignHCenter
           text: "Ground Motion List"
           font.pixelSize: 22
         }
         GroundMotionListView {}
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
            root.fileName = temp.slice(temp.lastIndexOf("/")+1, temp.length)
             BackEnd.readFile(fileDialog.fileUrl, root.fileName );
        }
        onRejected: {
            console.log("Canceled")
        }
//        Component.onCompleted: visible = true
    }

    Popup {
            id: popup
            padding: 0
            width: 400
            height: 200
            x: Math.round((parent.width - width) / 2)
            y: 30
            z: 10
            focus: true
            closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
//            closePolicy: Popup.CloseOnEscape


            ColumnLayout {
                anchors.fill: parent

                Label {
                    id: message
                    text: qsTr("Width for running your File is too long")
                    font.pixelSize: 18
                    font.bold: true
                    Layout.topMargin: 20
                    Layout.bottomMargin: 20
                    Layout.alignment: Qt.AlignHCenter
                }
            }
    }

    Popup {
            id: fileDialogPopup
            padding: 0
            width: 600
            height: 400
            x: Math.round((parent.width - width) / 2)
            y: 30
            z: 10
            focus: true
            closePolicy: Popup.CloseOnEscape
            ColumnLayout {
                anchors.fill: parent
                ListView {
                    width: 500;
                    height: 250
                    Layout.alignment: Qt.AlignHCenter
                    property bool auth: false
                    function setAuth(temp) {root.auth = temp;}
                    model: FileItemsModel
                    delegate: FileItem {
                        name: model.Name
                        isDirectory: model.isDirectory
                        path: model.Path
                        onSelected: {
//                            root.slideNum = JobModel.setTemporaryJob("file://"+filePath);
//                            name_form.inputText = JobModel.getFileName();
//                            sliderVolumePosition.enabled = true;
//                            previewImg.source = JobModel.getFrameImage(1);
//                            BackEnd.readFile(fileDialog.fileUrl);
                            root.fileName = name;
                            BackEnd.readFile(path);
                            fileDialogPopup.close();
                        }
                    }
                    ScrollBar.vertical: ScrollBar {}
                }
                RowLayout {
                    width: parent.width
                    Layout.alignment: Qt.AlignHCenter
                    spacing: 25
                    Button {
                        Layout.alignment: Qt.AlignHCenter
                        text: qsTr("Close")
                        highlighted: true
                        Material.background: Material.Red
                        onClicked: {
                            fileDialogPopup.close();
                        }
                    }
                    Button {
                        Layout.alignment: Qt.AlignHCenter
                        text: qsTr("Back")
                        highlighted: true
                        Material.background: Material.Blue
                        onClicked: {
                             FileItemsModel.backDirectory();
                        }
                    }
                }


            }
    }
}
