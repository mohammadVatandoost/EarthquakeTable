import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4

//Rectangle {
//    width: 100
//    height: 100
//    color: "red"
//    border.color: "black"
//    border.width: 5
//    radius: 10
//}

RowLayout {
    id: root
    width: parent.width
    property string name: "asdsad"
    property int colibrate: 10
    property bool auth: false
    function setName(temp) {name = temp;}
    function setColibrate(temp) {colibrate = temp;}
    function setAuth(temp) {root.auth = temp;}

    Label {
      id: label
//      Layout.alignment: Qt.AlignLeft
//      anchors.left: parent.left
      text: qsTr(name)
      font.pixelSize: 18
//      anchors.horizontalCenter: parent.horizontalCenter
    }
    Text {
//        Layout.leftMargin: 140
        text: qsTr(colibrate + "")
        font.pixelSize: 22
//        anchors.horizontalCenter: parent.horizontalCenter
    }
    Button {
           Layout.alignment: Qt.AlignRight
           text: qsTr("Delete")
           highlighted: true
           Material.background: Material.Red
           onClicked: {BackEnd.removeColibrateItem(name);}
           enabled: root.auth
    }

}
