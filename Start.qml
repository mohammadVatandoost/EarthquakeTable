import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4
import GroundMotionModel 1.0

Pane {
    id: root
    implicitHeight: 320
    implicitWidth: parent.width
    Material.elevation: 5
    Layout.alignment: Qt.AlignHCenter
    Layout.topMargin: 21
    property string fileUrl: ""
    ColumnLayout {
        width: parent.width
        spacing: 5
        Text {
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 18
            text: qsTr("Running")
        }

//         ComboBox {
//             id: comboTime
//             Layout.alignment: Qt.AlignHCenter
//             width: 200
//             model: BackEnd.getGroundMotionNames()
//             currentIndex: 0
//             onActivated: BackEnd.setSelectedGroundMotion(index)
//         }

         CheckBox {
                 id: filterCheckBox
                 checked: false
                 text: qsTr("Bandpass the recorded signal")
         }

         RowLayout {
             width: parent.width
             Layout.alignment: Qt.AlignHCenter
             spacing: 5
             visible: filterCheckBox.checked
             Text {
                 font.pointSize: 14
                 text: qsTr("Lower bound")
             }
             TextField {
                 id: frequncy1
                 horizontalAlignment: TextInput.AlignHCenter
                 Layout.topMargin: 10
                 Layout.bottomMargin: 10
                 Layout.rightMargin: 40
                 width: 90
                 height: 50
                 font.pointSize: 18
                 text: "0"
             }
             Text {
                 font.pointSize: 14
                 text: qsTr("Upper bound")
             }
             TextField {
                 id: frequncy2
                 horizontalAlignment: TextInput.AlignHCenter
                 Layout.topMargin: 10
                 Layout.bottomMargin: 10
                 width: 90
                 height: 50
                 font.pointSize: 18
                 text: "99"
             }
         }

         CheckBox {
                 id: checkBox
                 checked: false
                 text: qsTr("I have centered the device")
         }

         Button {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Start")
                highlighted: true
                Material.background: Material.Green
                onClicked: {
                    if(BackEnd.setFilter(parseFloat(frequncy1.text), parseFloat(frequncy2.text), filterCheckBox.checked) ) {
                        BackEnd.sendFileData(0);
                        // comboTime.currentIndex
                        checkBox.checked = false;
                    }
                }
                enabled: checkBox.checked
         }

    }


}
