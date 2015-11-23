import QtQuick 2.5
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Window {
    visible: true
    id: mainwin
    width: 300
    height: 500

    LinearGradient{
        id: linearGradient1
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.left: parent.left
        start:Qt.point(0,0);
        end:Qt.point(0,300)
        gradient: Gradient{
            GradientStop {position: 0.0; color: "white"}
            GradientStop {position: 1.0; color: "lightsteelblue"}
        }
    }
    Text{
        visible:true
        id:title
        anchors.horizontalCenter: mainwin
        text:qsTr("HUFFMAN")
        color: "cadetblue"
        font{
            bold:true
            pixelSize: 30
        }
    }
    ColumnLayout{
        visible:true
        id:maincol
        anchors.centerIn: parent
        //anchors.verticalCenterOffset: -27
        //anchors.horizontalCenterOffset: -26
        Button{
            visible:true
            id: selButton
            text:"Choose file:"
            onClicked:{
                selector.open()
            }
        }

        FileDialog{
            visible: false
            id: selector
            title: "File:"
            folder: shortcuts.home
            onAccepted: {
                console.log("You chose: " + FileDialog.fileUrl)
            }
            onRejected: {
                console.log("Canceled")
            }
        }

    }
}


