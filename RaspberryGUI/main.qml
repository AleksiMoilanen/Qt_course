import QtQuick 2.8
import QtQuick.Controls 2.3
import Qt.labs.calendar 1.0

ApplicationWindow {
    id: applicationWindow

    property var scalingVar: 20

    visible: true
    width: 1920
    height: 1080
    title: qsTr("Raspberry shit")

    Grid {
        id: grid
        anchors.right: parent.right
        anchors.rightMargin: 148
        anchors.left: parent.left
        anchors.leftMargin: 148
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 20
        spacing: 25
        rows: 2
        columns: 2

        SensorElement{
            objectName: backEnd.getSensorName(0)
            sensorID: 0
            timerInterval: backEnd.getSensorReadInterval(0)
        }

        SensorElement{
            objectName: backEnd.getSensorName(1)
            sensorID: 1
            timerInterval: backEnd.getSensorReadInterval(1)
        }

        SensorElement{
            objectName: backEnd.getSensorName(2)
            sensorID: 2
            timerInterval: backEnd.getSensorReadInterval(2)
        }
    }
}
