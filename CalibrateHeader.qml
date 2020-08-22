import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4


//Rectangle {
//    width: parent.width
//    height: 55
//    color: "white"
//     z: 0

    RowLayout {
       width: parent.width
        id: root
       spacing: 0
       Layout.alignment: Qt.AlignHCenter
       z:10
       property int columnW: 60
       property int rowH: 55
       property int columnW_small: 45
       property int columnW_large: 60

       Item {
           width: root.columnW
           height: root.rowH
           Text {
               text: qsTr("Name")
               font.pointSize: 12
               font.bold: true
               x: (parent.width/2) - (width/2)
               y: (parent.height/2) - (height/2)
           }
       }

       ToolSeparator {
       }

       Item {
           width: root.columnW
           height: root.rowH
           Text {
               text: qsTr("PGA")
               font.pointSize: 12
               font.bold: true
               x: (parent.width/2) - (width/2)
               y: (parent.height/2) - (height/2)
           }
       }

       ToolSeparator {
       }

       Item {
           width: root.columnW
           height: root.rowH
           Text {
               text: qsTr("PGD")
               font.pointSize: 12
               font.bold: true
               x: (parent.width/2) - (width/2)
               y: (parent.height/2) - (height/2)
           }
       }

       ToolSeparator {
       }

       Item {
           width: root.columnW
           height: root.rowH
           Text {
               text: qsTr("")
               font.pointSize: 12
               font.bold: true
               x: (parent.width/2) - (width/2)
               y: (parent.height/2) - (height/2)
           }
       }

    }

//}

