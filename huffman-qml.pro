TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11
CONFIG += console

SOURCES += main.cpp \
    node.cpp \
    tree.cpp \
    printer.cpp \
    binarystuff.cpp \
    fileinfo.cpp \
    hub.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    node.h \
    tree.h \
    fileinfo.h \
    printer.h \
    binarystuff.h \
    hub.h

DISTFILES +=

