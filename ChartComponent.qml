import QtQuick 2.0
import QtQml 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtCharts 2.0
import QtQuick.Controls.Material 2.3

Page {
    id: root
    property var line1
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
                height: window.height/3
                width: window.width
                antialiasing: true
                DateTimeAxis {
                    id: axisXTime0
                    format: "mm:ss"
                    tickCount: 10
                }
                ValueAxis {
                    id: axisXData0
                    min: 0
                    max: 1000
                }
                LineSeries {
                    id: lineSeries0
                    axisX: axisXTime0
                    axisY: axisXData0
                    name: "Sensor 1"
                }
                Component.onCompleted:  {
                    BackEnd.setAxisXTime(axisXTime0, 0);
                }
            }

            ChartView {
                title: "Ax1"
                height: window.height/3
                width: window.width
                antialiasing: true
                DateTimeAxis {
                    id: axisXTime1
                    format: "mm:ss"
                    tickCount: 10
                }
                ValueAxis {
                    id: axisXData1
                    min: 0
                    max: 1000
                }
                LineSeries {
                    id: lineSeries1
                    axisX: axisXTime1
                    axisY: axisXData1
                    name: "Sensor 1"
                }
                Component.onCompleted:  {
                    BackEnd.setAxisXTime(axisXTime1, 1);
                }
            }

            ChartView {
                title: "Ax2"
                height: window.height/3
                width: window.width
                antialiasing: true
                DateTimeAxis {
                    id: axisXTime2
                    format: "mm:ss"
                    tickCount: 10
                }
                ValueAxis {
                    id: axisXData2
                    min: 0
                    max: 1000
                }
                LineSeries {
                    id: lineSeries2
                    axisX: axisXTime2
                    axisY: axisXData2
                    name: "Sensor 3"
                }
                Component.onCompleted:  {
                    BackEnd.setAxisXTime(axisXTime2, 2);
                }
            }

            ChartView {
                title: "Ax4"
                height: window.height/3
                width: window.width
                antialiasing: true
                DateTimeAxis {
                    id: axisXTime3
                    format: "mm:ss"
                    tickCount: 10
                }
                ValueAxis {
                    id: axisXData3
                    min: 0
                    max: 1000
                }
                LineSeries {
                    id: lineSeries3
                    axisX: axisXTime3
                    axisY: axisXData3
                    name: "Sensor 4"
                }
                Component.onCompleted:  {
                    BackEnd.setAxisXTime(axisXTime3, 3);
                }
            }

            Rectangle {
                width: parent.width
                height: 80
            }

        }
    }

    Timer {
        id: refreshTimer
        interval: 500//30 // 60 Hz
        running: true
        repeat: true
        onTriggered: {
            BackEnd.updateChart(lineSeries0, 0);
            BackEnd.updateChart(lineSeries1, 1);
            BackEnd.updateChart(lineSeries2, 2);
            BackEnd.updateChart(lineSeries3, 3);
        }
    }
}
