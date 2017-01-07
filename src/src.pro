QT += core
QT -= gui

CONFIG += c++11

TARGET = src
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    myvector.h \
    mymatrix.h

include(../MyString/MyString.pri)
