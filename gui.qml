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
                    id: title
                    text: "HUFFMAN"
                    anchors.horizontalCenter: parent.horizontalCenter
                    font{
                        bold: true
                        pixelSize: 35
                    }
                }
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
                        id:browser
                        folder:shortcuts.home
                        title: "Choose your file."
                        onAccepted: {
                            path.text = (browser.fileUrl)
                            browser.close
                        }
                        onRejected: {
                            browser.close
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
                        }
                        Button{
                            id: decompress
                            text: "Decompress"
                        }
                        Button{
                            id: openbrowserC
                            text: "Browse Input"
                            onClicked: {
                                browser.open()
                            }
                        }
                        Button{
                            id: openbrowserD
                            text: "Browse Output"
                            onClicked: {
                                browser.open()
                            }
                        }
                    }

                }

             }
            }
        }
    }
