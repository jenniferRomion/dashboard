function test() {
    console.log("test javascript");
    console.log()
}

var component

function createbis(composant) {
    if (composant === "postit")
    {
        component = Qt.createComponent("Mypostit.qml");
    }
    else
    {
        component = Qt.createComponent("Mycarnet.qml");
    }

    composant = component.createObject(iboard, {"x": 100, "y": 100});
    if (composant === null) {
        console.log("Error creating object");
    }

    else if (component.status === Component.Error) {
        console.log("Error loading component:", component.errorString());
    }

    else
    {
//        iboard.tableauQML.push( composant )
        console.log("")
    }
}


