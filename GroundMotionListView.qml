import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import GroundMotionModel 1.0

//Pane {
//    implicitHeight: 300
//    implicitWidth: parent.width*0.95
//    Material.elevation: 5
//    Layout.topMargin: 0
//    Layout.rightMargin: 21
//    Layout.alignment: Qt.AlignHCenter
//    ColumnLayout {
//        width: parent.width
//        spacing: 5
ListView {
    width: parent.width*0.95;
    height: 250
    Layout.alignment: Qt.AlignHCenter
    property bool auth: false
    function setAuth(temp) {root.auth = temp;}
    model: GroundMotionModel {
             list: GroundMotionList
    }

    delegate: GroundMotionItem {
        Component.onCompleted: {
            setName(model.name);
            setStepTime(model.timeStep);
            setAuth(root.auth);
//            console.log("GroundMotionItem :");
//            console.log(model.timeStep);
        }
    }

    ScrollBar.vertical: ScrollBar {}
}
//}
//}

//Pane {
//    id: root
//    implicitHeight: 400
//    implicitWidth: parent.width*0.95
//    Material.elevation: 5
//    Layout.alignment: Qt.AlignHCenter
//    Layout.topMargin: 21
//    property string fileUrl: ""
//    ColumnLayout {
//        height: 200
//        width: parent.width*0.95
//        ListView {
//            Layout.fillWidth: true
//            Layout.fillHeight: true
//            Layout.topMargin: 5

//            clip: true
//            id: listView
//            spacing: 10
//            model: GroundMotionModel {
//                list: GroundMotionList
//            }

//            delegate: GroundMotionItem {
//                Component.onCompleted: {
//                    console.log("GroundMotionItem *******************")
//                    setName(model.name)
//                    setStepTime(model.timeStep)
//                }
//            }

////            ScrollBar.vertical: ScrollBar {}
//        }
//    }
////}
