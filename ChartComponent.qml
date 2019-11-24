import QtQuick 2.0
import QtQml 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtCharts 2.0
import QtQuick.Controls.Material 2.3

Page {
    id: root
    anchors.fill: parent
    ScrollView {
        id: scrollView
        width: window.width
        height: window.height
        clip: true
        ColumnLayout {
            id: column
            width: window.width
            ChartView {
                title: "Ax1"
                height: parent.width < 420 ? 400 : 550
                width: window.width
                antialiasing: true

                SplineSeries {
                    name: "SplineSeries"
                    XYPoint { x: 0; y: 0.0 }
                    XYPoint { x: 1.1; y: 3.2 }
                    XYPoint { x: 1.9; y: 2.4 }
                    XYPoint { x: 2.1; y: 2.1 }
                    XYPoint { x: 2.9; y: 2.6 }
                    XYPoint { x: 3.4; y: 2.3 }
                    XYPoint { x: 4.1; y: 3.1 }
                }
            }

            ChartView {
                title: "Ax2"
                height: parent.width < 420 ? 400 : 550
                width: window.width
                antialiasing: true

                SplineSeries {
                    name: "SplineSeries"
                    XYPoint { x: 0; y: 0.0 }
                    XYPoint { x: 1.1; y: 3.2 }
                    XYPoint { x: 1.9; y: 2.4 }
                    XYPoint { x: 2.1; y: 2.1 }
                    XYPoint { x: 2.9; y: 2.6 }
                    XYPoint { x: 3.4; y: 2.3 }
                    XYPoint { x: 4.1; y: 3.1 }
                }
            }

            ChartView {
                title: "Ax3"
                height: parent.width < 420 ? 400 : 550
                width: window.width
                antialiasing: true

                SplineSeries {
                    name: "SplineSeries"
                    XYPoint { x: 0; y: 0.0 }
                    XYPoint { x: 1.1; y: 3.2 }
                    XYPoint { x: 1.9; y: 2.4 }
                    XYPoint { x: 2.1; y: 2.1 }
                    XYPoint { x: 2.9; y: 2.6 }
                    XYPoint { x: 3.4; y: 2.3 }
                    XYPoint { x: 4.1; y: 3.1 }
                }
            }

            Rectangle {
                width: parent.width
                height: 80
            }

        }
    }
}
