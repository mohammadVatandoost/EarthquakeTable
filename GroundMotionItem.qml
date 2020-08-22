import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4

RowLayout {
    id: root
    width: parent.width
    spacing: 0
    property int columnW: 55
    property int columnW_small: 45
    property int columnW_large: 60
    property int rowH: 60
    property string name: ""
    property int stepTime: 10
    property bool auth: false
    property string fileName: "dsafafadfa"
    function setName(temp) {name = temp;}
    function setStepTime(temp) {
        stepTime = temp;
    }
    function setAuth(temp) {root.auth = temp;}
    Item {
        width: root.columnW
        height: root.rowH
        Text {
            x: (parent.width/2)-(width/2)
            y: (parent.height/2) - (height/2)
          text: root.name
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
            text: qsTr(root.fileName)
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
            text: qsTr(root.stepTime+"ms")
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
               onClicked: {BackEnd.removeGroundMotion(name);}
               enabled: root.auth
        }
    }


}
