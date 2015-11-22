import QtQuick 2.5
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0

Window {
    visible: true
    id: mainwin
    width: 600
    height: 300

    LinearGradient{
        anchors.fill : parent
        start:Qt.point(0,0);
        end:Qt.point(0,300)
        gradient: Gradient{
        GradientStop {position: 0.0; color: "white"}
        GradientStop {position: 1.0; color: "lightsteelblue"}
        }
    }
    Text{
        id:title
        text:qsTr("HUFFMAN")
        font{
            bold:true
            pixelSize: 30
        }
    }
    Image{
        //x:
    }
}

