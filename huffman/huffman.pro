#-------------------------------------------------
#
# Project created by QtCreator 2015-05-09T22:50:30
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = huffman
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    node.cpp \
    tree.cpp \
    compression.cpp \
    auxilia.cpp

HEADERS += \
    node.h \
    tree.h \
    compression.h \
    auxilia.h
