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
    property int pga: 0
    property int pda: 0
    property bool auth: false
    function setName(temp) {name = temp;}
    function setColibrate(temp) {colibrate = temp;}
    function setAuth(temp) {root.auth = temp;}

    Item {
        width: 100
        Label {
          id: label
          text: qsTr(name)
          font.pixelSize: 18
        }
    }
    Item {
        width: 100
        Text {
            text: qsTr(pga + " mg")
            font.pixelSize: 22
        }
    }
    Item {
        width: 100
        Text {
            text: qsTr(pda + " cm")
            font.pixelSize: 22
        }
    }

    Button {
           Layout.alignment: Qt.AlignRight
           Layout.topMargin: parent.height/2
           text: qsTr("Delete")
           highlighted: true
           Material.background: Material.Red
           onClicked: {BackEnd.removeColibrateItem(name);}
           enabled: root.auth
    }

}
