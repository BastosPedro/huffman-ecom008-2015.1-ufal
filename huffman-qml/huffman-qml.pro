TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    auxilia.cpp \
    node.cpp \
    tree.cpp \
    encode.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    auxilia.h \
    node.h \
    tree.h \
    encode.h

