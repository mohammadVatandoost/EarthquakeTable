import QtQuick 2.9
import QtQuick.Window 2.2
import QtQml 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import QtQuick.Controls.Material 2.3
import QtQuick.Dialogs 1.2
import QtQuick.FreeVirtualKeyboard 1.0

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

    InputPanel {
        id: inputPanel
        z: 1000
        y: window.height
        anchors.left: parent.left
        anchors.right: parent.right
        states: State {
            name: "visible"
            when: Qt.inputMethod.visible
            PropertyChanges {
                target: inputPanel
                y: window.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 150
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }

    Popup {
            id: popup
            padding: 10
            width: 400
            height: 200
            x: Math.round((parent.width - width) / 2)
            y: Math.round((parent.height - height) / 2)
            modal: true
            focus: true
            closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        ColumnLayout {
            anchors.horizontalCenter: parent.horizontalCenter
            implicitWidth: 400
            implicitHeight: 200
            spacing: 20
            Label {
              text: qsTr("Error")
              color: "red"
              font.pixelSize: 27
//              anchors.horizontalCenter: parent.horizontalCenter
            }
            Text {
//                anchors.horizontalCenter: parent.horizontalCenter
                id: errorMessage
                text: "Hello blue sky!"
                font.pixelSize: 22
            }
            Button {
                Layout.alignment: Qt.AlignHCenter
//                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Close")
                highlighted: true
                Material.background: Material.Red
                onClicked: {popup.close();}
            }
        }
    }

    Timer {
            interval: 1000; running: true; repeat: true
            onTriggered: {
                if(BackEnd.getErrorMessage() === "") {

                } else {
                 popup.open();
                }


            }
     }
}
