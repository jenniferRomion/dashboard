import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

Rectangle {
    width: 230
    height: 230

    Calendar {
        id: calendar
        anchors.centerIn: parent
        width: 200
        height: 200

        style: CalendarStyle {

            dayDelegate: Item {
                Rectangle {
                    id: rect
                    anchors.fill: parent

                    Label {
                        id: dayDelegateText
                        text: styleData.date.getDate()
                        anchors.centerIn: parent
                        horizontalAlignment: Text.AlignRight
                        font.pixelSize: Math.min(parent.height/2, parent.width/2)
                        color: styleData.selected ? "blue" : "black"
                        font.bold: styleData.selected
                        font.family: "comic sans MS"
                    }
                    MouseArea {
                        anchors.fill: parent
                        Rectangle {
                            anchors.fill: parent
                            color: "transparent"
                            border.color: "lightblue"
                        }
                    }
                }
            }
        }
    }
}
