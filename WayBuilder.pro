#-------------------------------------------------
#
# Project created by QtCreator 2015-10-10T10:24:10
#
#-------------------------------------------------

QT       += core
QT       += testlib
QT       -= gui

TARGET = WayBuilder
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    waysmap.cpp \
    inout.cpp \
    tests/findbordercoordinatetest.cpp \
    tests/isobstaclestest.cpp \
    tests/createwaysmaptest.cpp

HEADERS += \
    waysmap.h \
    inout.h \
    tests/findbordercoordinatetest.h \
    tests/isobstaclestest.h \
    tests/createwaysmaptest.h
