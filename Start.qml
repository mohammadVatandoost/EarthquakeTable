import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import GroundMotionModel 1.0

Pane {
    id: root
    implicitHeight: 280
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
                 text: qsTr("I have centered the device.")
         }

         RowLayout {
             width: parent.width
             Layout.alignment: Qt.AlignHCenter
             spacing: 5
             Text {
                 font.pointSize: 18
                 text: qsTr("Frequency 1 :")
             }
             TextField {
                 id: frequncy1
                 Layout.topMargin: 10
                 Layout.bottomMargin: 10
                 Layout.rightMargin: 40
                 width: 100
                 height: 50
                 font.pointSize: 18
                 text: "0"
             }
             Text {
                 font.pointSize: 18
                 text: qsTr("Frequency 2 :")
             }
             TextField {
                 id: frequncy2
                 Layout.topMargin: 10
                 Layout.bottomMargin: 10
                 width: 100
                 height: 50
                 font.pointSize: 18
                 text: "99"
             }
         }
//         RowLayout {
//             width: parent.width
//             Text {
//                 text: qsTr("Frequency 2 :")
//             }
//             TextEdit {
//                 id: frequncy2
//                 Layout.topMargin: 10
//                 Layout.bottomMargin: 10
//                 width: 200
//                 height: 50
//                 font.pointSize: 22
//                 text: "200"
//             }
//         }

         Button {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Start")
                highlighted: true
                Material.background: Material.Green
                onClicked: {
                    if(BackEnd.setFilter(parseFloat(frequncy1.text), parseFloat(frequncy2.text)) ) {
                        BackEnd.sendFileData(comboTime.currentIndex);
                        checkBox.checked = false;
                    }
                }
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
