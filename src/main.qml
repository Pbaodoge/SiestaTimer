import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import main.data 1.0
Window {
    width: 800
    height: 480
    visible: true
    color: "black"
    title: qsTr("Siesta Clock")

    Data{
        id: data
      }
    Timer {
        id: timer
        interval: 1000
        repeat: true
        running: true

        onTriggered:
        {
            timeText.text = "\nToday is: " + data.datetimer() + "\nTime: " + data.realtimer() + "\n\nMade with ❤️ By Siesta"
        }
    }
           Text {
               id: timeText
               anchors.centerIn: parent
               font.family: "JetBrains Mono"
               font.pointSize: 24
               text: "\nToday is: " + data.datetimer() + "\nTime: " + data.realtimer() + "\n\nMade with ❤️ By Siesta"
               color: "cyan"
               Button {
                   id: exit
                   x: 140
                   y: 250
                   font.family: "JetBrains Mono"
                   font.pointSize: 18
                   text: "  Exit  "
                   onClicked: Qt.exit(0)

               }
           }


}
