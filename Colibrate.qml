import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4


Pane {
    id: root
    implicitHeight: 470
    implicitWidth: parent.width*0.95
    Material.elevation: 5
    Layout.topMargin: 0
    Layout.rightMargin: 21
    Layout.alignment: Qt.AlignHCenter
    property bool auth: false
    function setAuth(temp) {root.auth = temp;}
    ColumnLayout {
        width: parent.width
        spacing: 5
        Label {
          Layout.alignment: Qt.AlignHCenter
          text: "Structure Name"
          font.pixelSize: 22
        }
        TextEdit {
            id: textEdit
            Layout.topMargin: 10
            Layout.bottomMargin: 10
            width: 200
            height: 50
            font.pointSize: 22
//            inputMethodHints: Qt.ImhDigitsOnly
            property string placeholderText: "Name"
            onActiveFocusChanged: BackEnd.openKeyboard()
            Text {
                text: textEdit.placeholderText
                color: "#aaa"
                font.pointSize: 25
                visible: !textEdit.text && !textEdit.activeFocus // <----------- ;-)
            }
        }
        Button {
            Layout.alignment: Qt.AlignHCenter
//            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Colibrate")
            highlighted: true
            Material.background: Material.Green
            onClicked: {BackEnd.colibrate()}
            enabled: root.auth
        }
        Label {
          Layout.alignment: Qt.AlignHCenter
          text: "Structures List"
          font.pixelSize: 22
        }
        ColibrateList {}

    }
}
