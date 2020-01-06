import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4

RowLayout {
    id: root
    width: parent.width
    property string name: ""
    property int stepTime: 10
    function setName(temp) {name = temp;}
    function setStepTime(temp) {
        stepTime = temp;
    }
    Label {
      id: label
//      Layout.alignment: Qt.AlignLeft
//      anchors.left: parent.left
      text: root.name
      font.pixelSize: 18
//      anchors.horizontalCenter: parent.horizontalCenter
    }
    Text {
//        Layout.leftMargin: 140
        text: qsTr(root.stepTime+"ms")
        font.pixelSize: 22
//        anchors.horizontalCenter: parent.horizontalCenter
    }
    Button {
           Layout.alignment: Qt.AlignRight
           text: qsTr("Delete")
           highlighted: true
           Material.background: Material.Red
           onClicked: {BackEnd.removeGroundMotion(name);}
    }

}
