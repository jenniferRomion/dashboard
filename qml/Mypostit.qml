import QtQuick 2.0
import QtQuick.Controls 1.4
import postit 1.0


Rectangle{
    id : rec
    width: root.width
    height: root.height
    color : root.color
    rotation: root.rotation
    radius : root.radius
    antialiasing: true

    onXChanged : root.setXValue(x)
    onYChanged : root.setYValue(y)

    TextEdit {
        id : txt
        width: parent.width
        anchors.top : bordure.bottom
        z : 3

        text : root.message
        onTextChanged: root.setMessage(txt.text)
    }

    MouseArea{
        anchors.fill : parent
        drag.target: parent
    }

    Rectangle {
        id : bordure
        width : parent.width
        anchors.top: parent.top
        height: 25
        color : "#3498db"
        antialiasing: true

        Button {
            height: parent.height
            width: 25
            anchors.left: parent.left
            iconSource: "../Images/Delete-icon2.png"
            antialiasing: true

            onClicked: {
                console.log("destroy");
                rec.destroy()
                root.destroy();
            }}


        Image {
            id : punaise
            anchors.top: parent.top
            anchors.right: parent.right
            source : "../Images/punaise.png"
            height: 40
            width: 40
        }}

    Postit {
        id : root
        Component.onCompleted: {
            setHeight(150);
            setWidth(150);
            setColor("#aed6f1");
            setRotation(-5)
            setRadius(5);
            setMessage("hello");

//            Context.addBloc(this);
        }
    }
}
