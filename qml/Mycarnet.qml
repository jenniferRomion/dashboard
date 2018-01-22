import QtQuick 2.0
import QtQuick.Controls 1.4
import carnet 1.0

Rectangle {
    id : rec
    width: root.width
    height: root.height
    radius : root.radius
    antialiasing: true

    onXChanged : root.setXValue(x)
    onYChanged : root.setYValue(y)


    Button {
        height: 25
        width: 25
        z : 3
        anchors.right: parent.right
        anchors.top: parent.top
        iconSource: "../Images/Delete-icon2.png"
        antialiasing: true

            onClicked: {
                console.log("destroy");
                Context.deleteMBloc(this);
                rec.destroy()
                root.destroy();
            }}


    TextEdit {
        id : txt
        width: parent.width - 50
        height: parent.height - 80
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        z : 3

        text : root.message
        onTextChanged: root.setMessage(txt.text)
    }

    MouseArea {
        id: mypostimousearea
        anchors.fill: parent
        drag.target: parent
    }

    Image {
        id : background
        anchors.fill : parent
        Component.onCompleted: {
            background.source = "../Images/blocNote.png"
        }}

    Carnet {
        id : root
        Component.onCompleted: {
            setHeight(356);
            setWidth(249);
            setRadius(5);
            setMessage("TO DO")

//            Context.addBloc(this);

        } }

}
