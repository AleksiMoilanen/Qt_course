import QtQuick 2.8
import QtQuick.Controls 2.3

Item {
    id: item1

    property var scalingVar: 40
    property var sensorID: -1
    property var timerInterval: -1

    width: 800
    height: 480

    Rectangle {
        id: background
        color: "#ffffff"
        radius: 25
        anchors.fill: parent
        border.width: 1
    }

    Text {
        id: sensorNameText
        x: 153
        width: 666
        height: 99
        text: backEnd.getSensorName(sensorID)
        anchors.top: parent.top
        anchors.topMargin: 49
        anchors.horizontalCenter: parent.horizontalCenter
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 60
    }

    Text {
        id: sensorValueText
        x: 157
        width: 385
        height: 158
        text: qsTr("100")
        font.underline: false
        font.bold: false
        anchors.top: timerIntervalText.bottom
        anchors.topMargin: 5
        anchors.horizontalCenter: timerIntervalText.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 50
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: timerIntervalText
        y: 155
        width: 297
        height: 39
        text: "Reading interval: " + timerInterval + " ms"
        anchors.horizontalCenter: sensorNameText.horizontalCenter
        anchors.left: text1.right
        anchors.leftMargin: 10
        anchors.topMargin: 0
        anchors.top: sensorNameText.bottom
        font.pixelSize: 18
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignTop
    }

    Timer {
        interval: timerInterval
        running: true;
        repeat: true
        onTriggered: backEnd.getSensorValue(parent, sensorID)
    }

    function updateSensorValue(value){
        sensorValueText.text = value
    }
}
