import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: root
    width: parent.width
    height: 55
    color: "#FaFaFa"
     z: 10
     property string name: "asdsad"
     property int colibrate: 10
     property int pga: 0
     property int pda: 0
     property bool auth: false
     property int columnW: 60
     property int rowH: 60
     function setName(temp) {name = temp;}
     function setColibrate(temp) {colibrate = temp;}
     function setAuth(temp) {root.auth = temp;}

RowLayout {
    spacing: 0
    width: parent.width


    Item {
        width: root.columnW
        height: root.rowH
        Text {
            x: (parent.width/2)-(width/2)
            y: (parent.height/2) - (height/2)
          text: qsTr(root.name)
          font.pixelSize: 18
        }
    }
    ToolSeparator {}
    Item {
        width: root.columnW
        height: root.rowH
        Text {
            x: (parent.width/2)-(width/2)
            y: (parent.height/2) - (height/2)
            text: qsTr(root.pga + " mg")
            font.pixelSize: 18
        }
    }
    ToolSeparator {}
    Item {
        width: root.columnW
        height: root.rowH
        Text {
            x: (parent.width/2)-(width/2)
            y: (parent.height/2) - (height/2)
            text: qsTr(root.pda + " cm")
            font.pixelSize: 18
        }
    }

    ToolSeparator {}

    Item {
        width: root.columnW
        height: root.rowH
        Button {
            x: (parent.width/2)-(width/2)
            y: (parent.height/2) - (height/2)
               text: qsTr("Delete")
               highlighted: true
               Material.background: Material.Red
               onClicked: {BackEnd.removeColibrateItem(name);}
               enabled: root.auth
        }
    }


}

}
