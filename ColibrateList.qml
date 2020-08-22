import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
//import ColibrateItemModel 1.0

ListView {
    width: parent.width*0.95;
    height: 230
//    implicitHeight: 230
    clip: true
    Layout.alignment: Qt.AlignHCenter
    property bool auth: false
    function setAuth(temp) {root.auth = temp;}
    header: CalibrateHeader {
    }
    model: ColibrateItemModel

    delegate: ColibrateItem {
        name: model.Name
        colibrate: model.colibrate
        auth: root.auth
        pda: model.pda
        pga: model.pga

    }
    ScrollBar.vertical: ScrollBar {}
}



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
//            model: ColibrateItemModel {
//                list: ColibrateItemList
//            }

//            delegate: ColibrateItem {
//                Component.onCompleted: {
//                    console.log("ColibrateItem *******************")
////                    setName(model.name)
////                    setColibrate(model.colibrate)
//                }
//            }

//            ScrollBar.vertical: ScrollBar {}
//        }
//    }
//}
