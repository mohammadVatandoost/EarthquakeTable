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
    property int  chartNum: 4
    property int tabHeight: 80
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
                id: chartView3
                title: "Floor 3"
                height: window.height-root.tabHeight
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
                    name: "Ax"
                }
                Component.onCompleted:  {
                    BackEnd.setAxisXTime(axisXTime3, 3);
                }
            }

            ChartView {
                id: chartView2
                title: "Floor 2"
                height: window.height-root.tabHeight
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
                    name: "Ax"
                }
                Component.onCompleted:  {
                    BackEnd.setAxisXTime(axisXTime2, 2);
                }
            }

            ChartView {
                id: chartView1
                title: "Floor 1"
                height: window.height-root.tabHeight
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
                    name: "Ax"
                }
                Component.onCompleted:  {
                    BackEnd.setAxisXTime(axisXTime1, 1);
                }
            }

            ChartView {
                id: chartView0
                title: "Floor 0"
                height: window.height-root.tabHeight
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
//                    name: "Ax"
                }
                Component.onCompleted:  {
                    BackEnd.setAxisXTime(axisXTime0, 0);
                }
            }

//            Rectangle {
//                width: parent.width
//                height: 80
//            }

        }
    }

    Timer {
        id: refreshTimer
        interval: 500//30 // 60 Hz
        running: true
        repeat: true
        onTriggered: {
            var tempNum = 0;
            if(BackEnd.getFloorData(0)=== 255255) {
                chartView0.visible = false;
            } else {
                chartView0.visible = true;
                axisXData0.max = BackEnd.getMaxValue(0);
                axisXData0.min = BackEnd.getMinValue(0);
               BackEnd.updateChart(lineSeries0, 0);
                tempNum++;
            }
            if(BackEnd.getFloorData(1)=== 255255) {
                chartView1.visible = false;
            } else {
                chartView1.visible = true;
                axisXData1.max = BackEnd.getMaxValue(1);
                axisXData1.min = BackEnd.getMinValue(1);
               BackEnd.updateChart(lineSeries1, 1);
                tempNum++;
            }

            if(BackEnd.getFloorData(2)=== 255255) {
                chartView2.visible = false;
            } else {
                chartView2.visible = true;
                axisXData2.max = BackEnd.getMaxValue(2);
                axisXData2.min = BackEnd.getMinValue(2);
                 BackEnd.updateChart(lineSeries2, 2);
                tempNum++;
            }

            if(BackEnd.getFloorData(3)=== 255255) {
                chartView3.visible = false;
            } else {
                chartView3.visible = true;
                axisXData3.max = BackEnd.getMaxValue(3);
                axisXData3.min = BackEnd.getMinValue(3);
               BackEnd.updateChart(lineSeries3, 3);
                tempNum++;
            }
            if(tempNum == 0) {tempNum = 1 ;}
//            root.chartNum = tempNum;
            chartView0.implicitHeight = (window.height-root.tabHeight)/tempNum;
            chartView1.implicitHeight = (window.height-root.tabHeight)/tempNum;
            chartView2.implicitHeight = (window.height-root.tabHeight)/tempNum;
            chartView3.implicitHeight = (window.height-root.tabHeight)/tempNum;
            chartView0.implicitWidth = window.width;
            chartView1.implicitWidth = window.width;
            chartView2.implicitWidth = window.width;
            chartView3.implicitWidth = window.width;
        }
    }
}
