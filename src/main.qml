import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import main.data 1.0

Window {
    id: mainwindow
    width: 600
    height: 320
    maximumWidth: 600
    maximumHeight: 320
    visible: true
    color: "white"
    title: qsTr("Siesta Timer By Siesta | " + data.greet())

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
            timeText.text = data.greet() + data.realtimer() + "\nDate: " + data.datetimer()
        }
    }
           Text {
               id: timeText
               anchors.centerIn: parent
               font.family: "JetBrains Mono"
               font.pointSize: 24
               text: data.greet() + data.realtimer() + "\nDate: " + data.datetimer()
               color: "cyan"

               Button {
                   id: exit
                   x: 65
                   y: 150
                   font.family: "JetBrains Mono"
                   font.pointSize: 18
                   text: "   Exit   "
                   onClicked: Qt.exit(0)
               }

           }


}
