import QtQuick 2.5
import QtQuick.Controls 2.0

ApplicationWindow {
    visible: true
    width: 250
    height: 50
    title: qsTr("Transfer Server")

    Label {
        id: portLabel
        height: 30
        text: qsTr("Port: ")
        font.pixelSize: 18
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 10
            leftMargin: 10
        }
    }

    TextField {
        id: portNumber
        height: 30
        width: 70
        font.pixelSize: 18
        validator: IntValidator {
            bottom: 0
            top: 65535
        }
        anchors {
            top: parent.top
            left: portLabel.right
            topMargin: 10
        }
    }

    Button {
        id: listetButton
        text: qsTr("Listen")
        height: 30
        font.pixelSize: 18
        anchors {
            top: parent.top
            right: parent.right
            topMargin: 10
            rightMargin: 10
        }
    }
}
