import QtQuick 2.9
import QtQuick.Window 2.2
import QtQml 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.VirtualKeyboard 2.2

Window {
    id: window
    visible: true
    width: 840
    height: 680
    title: qsTr("Simulation Table")

    TabBar {
        id: bar
        width: parent.width
        TabButton {
            text: qsTr("Control")
            onClicked: {
                console.log("Control")
            }
        }
        TabButton {
            text: qsTr("Setting")
            onClicked: {
                console.log("Control")
            }
        }
        TabButton {
            text: qsTr("Charts")
            onClicked: {
                console.log("Charts")
            }
        }
    }

    StackLayout {
        anchors.top:  bar.bottom
        width: parent.width
        currentIndex: bar.currentIndex
        ControlPanel {
            id: controlTab
        }
        Setting {
            id: settingTab
        }

        ChartComponent {
            id: chartsTab
        }
    }
}
