import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import GroundMotionModel 1.0

Pane {
    id: root
    implicitHeight: 180
    implicitWidth: parent.width
    Material.elevation: 5
    Layout.alignment: Qt.AlignHCenter
    Layout.topMargin: 21
    property string fileUrl: ""
    ColumnLayout {
        width: parent.width
        spacing: 10
         ComboBox {
             id: comboTime
             Layout.alignment: Qt.AlignHCenter
             width: 200
//             model: timeSteps
//             model: GroundMotionModel {
//                 list: GroundMotionList
//             }
//             currentIndex: 1
             model: BackEnd.getGroundMotionNames()
             currentIndex: 0
             onActivated: BackEnd.setSelectedGroundMotion(index)
//             delegate: ItemDelegate {
//                text: index + 1
//             }
//             displayText: currentIndex + 1
//             onActivated: BackEnd.setTimeStep(timeSteps[currentIndex])
         }
         CheckBox {
                 id: checkBox
                 checked: false
                 text: qsTr("I have set initial position.")
         }

         Button {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Start")
                highlighted: true
                Material.background: Material.Green
                onClicked: {BackEnd.sendFileData(comboTime.currentIndex);}
                enabled: checkBox.checked
         }

    }
    Timer {
        id: refreshTimer
        interval: 1500//30 // 60 Hz
        running: true
        repeat: true
        onTriggered: {
            comboTime.model = BackEnd.getGroundMotionNames();
        }
    }

}
