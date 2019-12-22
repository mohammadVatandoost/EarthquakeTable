import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Controls.Styles 1.4

Pane {
    id: root
    implicitHeight: 150
    implicitWidth: parent.width
    Material.elevation: 5
    Layout.alignment: Qt.AlignHCenter
    Layout.topMargin: 21
    property string fileUrl: ""
    ColumnLayout {
        width: parent.width
        spacing: 15
         ComboBox {
             id: comboTime
             Layout.alignment: Qt.AlignHCenter
             property int floorNum: 0
             property var timeSteps: [ "5ms", "10ms", "15ms", "20ms"]
             width: 200
             model: timeSteps
             currentIndex: 1
             onActivated: BackEnd.setTimeStep(timeSteps[currentIndex])
         }
         Button {
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("Start")
                highlighted: true
                Material.background: Material.Green
                onClicked: {BackEnd.runSimulation();}
         }

    }


}
