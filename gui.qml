import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2


Window {
    function mm(value){
        return value*Screen.pixelDensity;
    }

    id: mainwindow
    visible: true
    width: mm(150)
    height: mm(100)
    color: "black"
    RowLayout{
        anchors.fill: parent
        anchors.margins: 5
        spacing: 1
        Rectangle{
            id:border
            color: "gray"
            radius: 2
            anchors.fill: parent
            anchors.margins: parent
            Rectangle{
                id: main
                color: "white"
                radius: 2
                anchors.fill: parent
                anchors.margins: 10
                Text{
                    id: author
                    text: "by pedro bastos"
                    anchors.bottom:parent.bottom
                }
                Text{
                    id: version
                    text: "version 0.5"
                    anchors.bottom:parent.bottom
                    anchors.right: parent.right
                }
                Image{
                    id: logo
                    source: "qrc:/assets/giraffe.png"
                    sourceSize.width: mm(20)
                    sourceSize.height: mm(20)
                    fillMode: Image.PreserveAspectFit
                    anchors.bottom:parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                ColumnLayout{
                    anchors.centerIn: parent

                    FileDialog{
                        id:browserI
                        folder:shortcuts.home
                        title: "Choose your file."
                        onAccepted: {
                            input.text = (browserI.fileUrl); input.text = input.text.replace("file://", "")
                            browserI.close
                        }
                        onRejected: {
                            browserI.close
                        }
                    }
                    FileDialog{
                        id:browserO
                        folder:shortcuts.home
                        //selectFolder: true
                        title: "Choose your target."
                        onAccepted: {
                            output.text = (browserO.fileUrl); output.text = output.text.replace("file://", "")
                            browserO.close
                        }
                        onRejected: {
                            browserO.close
                        }
                    }
                    Text{
                        id: title
                        text: "Huffman"
                        anchors.horizontalCenter: parent.horizontalCenter
                        font{
                            bold: true
                            pixelSize: 35
                        }
                    }
                    TextField{
                        id:input
                        implicitWidth: buttons.width
                        placeholderText: "Input"
                    }
                    TextField{
                        id:output
                        implicitWidth: buttons.width
                        placeholderText: "Output"
                    }
                    RowLayout{
                        id: buttons
                        Button{
                            id: compress
                            text: "Compress"
                            onClicked: {
                                _huffman.cCommand(input.text, output.txt)
                            }
                        }
                        Button{
                            id: decompress
                            text: "Decompress"
                        }
                        Button{
                            id: openbrowserI
                            text: "Browse Input"
                            onClicked: {
                                browserI.open()
                            }
                        }
                        Button{
                            id: openbrowserO
                            text: "Browse Output"
                            onClicked: {
                                browserO.open()
                            }
                        }
                    }

                }

             }
            }
        }
    }
