import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4


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
          spacing: 15
          ChooseFile {
             id: fileSelect
             Component.onCompleted: {
                 setAuth(false);
             }
          }
//          GroundMotionListView {}
       }

       ColumnLayout {
           width: parent.width/2
           spacing: 15
           Move {}
           Colibrate {
               id: calibrate
               Component.onCompleted: {
                   setAuth(false);
               }
           }
//           ColibrateList {}
       }
   }

    Button {
           text: qsTr("Login")
           highlighted: true
           Material.background: Material.Green
           onClicked: {popup.open()}
           z: 1000
           y: window.height - 100
           x: window.width - 80
    }

    Button {
        id: changePassword
           text: qsTr("change password")
           highlighted: true
           Material.background: Material.Green
           onClicked: {
               changePassPopup.open()
           }
           z: 1000
           y: window.height - 100
           x: window.width - 120 - width
           visible: false
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
 //           closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
            closePolicy: Popup.CloseOnEscape


            ColumnLayout {
                anchors.fill: parent

                Label {
                    id: message
                    text: qsTr("Please Enter your password")
                    font.pixelSize: 20
                    font.bold: true
                    Layout.topMargin: 20
                    Layout.bottomMargin: 20
                    Layout.alignment: Qt.AlignHCenter
                }
                TextInputWithBorder {
                    id: textEdit
//                    anchors.top: paddingTEmp.bottom
                    width: 1000
                    Layout.topMargin: 0
                    Layout.alignment: Qt.AlignHCenter
                    echoMode: TextInput.Password
                    placeholderText: "     Password     "
                    inputMethodHints: Qt.ImhDigitsOnly
        //            inputMethodHints: Qt.ImhNoAutoUppercase | Qt.ImhPreferLowercase | Qt.ImhSensitiveData | Qt.ImhNoPredictiveText
        //            enterKeyAction: EnterKeyAction.Next
                    onAccepted: upperCaseField.focus = true
                }

                Pane {
                    Layout.fillWidth: true

                   RowLayout {
                      width: parent.width
                      Layout.alignment: Qt.AlignJustify
                      Button {
                          text: qsTr("Cancel")
                          highlighted: true
                          Material.background: Material.Red
                          onClicked: {popup.close();}
                          Layout.alignment: Qt.AlignHCenter
                      }
                      Button {

                          text: qsTr("Submit")
                          highlighted: true
                          Material.background: Material.Green
                          onClicked: {
                              if(  BackEnd.verifyPassword(textEdit.text) ) {
                                  fileSelect.setAuth(true);
                                  calibrate.setAuth(true);
//                                  ColibrateItemList.reRenderModel();
                                  GroundMotionList.reRenderModel();
                                  changePassword.visible = true;
                                  popup.close();
                              } else {
                                 message.text = "Password is wrong"
                                 message.color = "red"
                              }


                          }
                          Layout.alignment: Qt.AlignHCenter
                      }

                  }

                }

            }
     }

    Popup {
            id: changePassPopup
            padding: 0
            width: 400
            height: 200
            x: Math.round((parent.width - width) / 2)
            y: 30
            z: 10
            focus: true
 //           closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
            closePolicy: Popup.CloseOnEscape


            ColumnLayout {
                anchors.fill: parent

                Label {
                    id: message2
                    text: qsTr("Please Enter new password")
                    font.pixelSize: 20
                    font.bold: true
                    Layout.topMargin: 20
                    Layout.bottomMargin: 20
                    Layout.alignment: Qt.AlignHCenter
                }
                TextInputWithBorder {
                    id: textEdit2
//                    anchors.top: paddingTEmp.bottom
                    width: 1000
                    Layout.topMargin: 0
                    Layout.alignment: Qt.AlignHCenter
                    echoMode: TextInput.Password
                    placeholderText: "     Password     "
                    inputMethodHints: Qt.ImhDigitsOnly
        //            inputMethodHints: Qt.ImhNoAutoUppercase | Qt.ImhPreferLowercase | Qt.ImhSensitiveData | Qt.ImhNoPredictiveText
        //            enterKeyAction: EnterKeyAction.Next
                    onAccepted: upperCaseField.focus = true
                }

                Pane {
                    Layout.fillWidth: true

                   RowLayout {
                      width: parent.width
                      Layout.alignment: Qt.AlignJustify
                      Button {
                          text: qsTr("Cancel")
                          highlighted: true
                          Material.background: Material.Red
                          onClicked: changePassPopup.close()
                          Layout.alignment: Qt.AlignHCenter
                      }
                      Button {
                          text: qsTr("Submit")
                          highlighted: true
                          Material.background: Material.Green
                          onClicked: {
                              BackEnd.changePassword(textEdit2.text);
                              changePassPopup.close();

                          }
                          Layout.alignment: Qt.AlignHCenter
                      }

                  }

                }

            }
     }


}
