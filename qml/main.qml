import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Window 2.1

import "script.js" as MyScript

ApplicationWindow {
    id : iboard

    visible : true
    width: 900
    height : 750
    minimumWidth: 600
    minimumHeight: 600
    color : "lightblue"

//    property var tableauQML : []

    property int largeurBouton : 140

    property var locale: Qt.locale()
    property date currentDate: new Date()
    property string dateString


    menuBar: MenuBar {
        Menu {
            title : "File"
            MenuItem {
                text : "New board" ; onTriggered : console.log("new board")
            }
            MenuItem {
                text : "Open board" ; onTriggered : console.log("open board")
            }
            MenuItem {
                text : "Delete board" ; onTriggered : console.log("delete board")
            }
            MenuItem {
                text : "Quit" ; onTriggered: Qt.quit()
            }
        }

        Menu {
            title : "Edit"
            MenuItem {
                text : "Add post-it" ; onTriggered : console.log("add post-it")
            }
            MenuItem {
                text : "Add notepad" ; onTriggered : console.log("add notepad")
            }
            MenuItem {
                text : "Add picture" ; onTriggered : console.log("add picture")
            }
        }
    }


    Row {
        spacing: 50
        x : 10


        /* ******* Menu objets **************** */

        Rectangle {
            id : idmenuobjet
            width: 100 ; height: 700
            y : 10
            color : "white"

            Column {
                spacing : 10

                Rectangle {
                    id : selectPostIt
                    x : 12.5
                    width : 75
                    height: 75
                    radius : 4
                    color: "#aed6f1"

                    Rectangle {
                        color: "#3498db"
                        width: parent.width ; height: 10
                        anchors.top : parent.top
                    }

                    MouseArea {
                        anchors.fill: parent
                        z : 1
                        onClicked: {
                            console.log("ok")
                            MyScript.createbis("postit");
                        }}

                    TextEdit {
                        y : 40
                        width : parent.width
                        horizontalAlignment: TextEdit.AlignHCenter
                        readOnly: true
                        text : "Post-it"
                    }
                }

                Rectangle {
                    id : selectCarnet
                    x : 12.5
                    width: 75
                    height: 75
                    radius : 4
                    antialiasing: true

                    Image {
                        id : background
                        anchors.fill : parent
                        Component.onCompleted: {
                            background.source = "../Images/blocNote.png"
                        }}
                    MouseArea {
                        anchors.fill: parent
                        z : 1
                        onClicked: {
                            console.log("ok")
                            MyScript.createbis("carnet");
                        }}
                }

                Button {
                    height: 20 ; width: 75
                    onClicked: Context.afficheMBloc()
                }
            }
        }




        /* ******** board ********************* */

        Rectangle {
            id : idboard
            width: 700 ; height: 700
            y : 10
            color : "white"

            DropArea{
                anchors.fill : parent
                width : parent.width
                height : parent.height
            }

            TextEdit{
                y : 30
                height: 50
                font.family: "Lucida Handwriting" ; font.pointSize: 12 ; font.italic: true
                anchors.horizontalCenter: idboard.horizontalCenter
                text : dateString = currentDate.toLocaleDateString();
            }
        }
    }








//    Window
//    {
//        id : newwindow
//        visible: true

//        Window2 {

//        }
//    }



} //fin Window
