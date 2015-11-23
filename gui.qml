import QtQuick 2.5
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Window {
    function mm(value){
        return value*Screen.pixelDensity;
    }

    id: mainwindow
    visible: true
    width: mm(200)
    height: mm(200)

    LinearGradient{
        id: linearGradient
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.left: parent.left
        start:Qt.point(0,0);
        end:Qt.point(0,200)
        gradient: Gradient{
            GradientStop {position: 0.0; color: "white"}
            GradientStop {position: 1.0; color: "lightsteelblue"}
        }
    }
    Row{
        Rectangle{
            id:menu
            width: mainwindow.width
            height: mainwindow.height*0.195
            Column{
                spacing: 10
                anchors.centerIn: parent
                Button{
                    text: "Compress"
                    onClicked: {
                        _huffman.cCommand(choose.path, choose.out)
                    }

                }
                Button{
                    text: "Decompress"
                    onClicked:{
                        _huffman.dCommand(chose.path, choose.out)
                    }
                }
            }
        }

    }

}
