QT += core
QT -= gui

CONFIG += c++11

TARGET = MyString
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    MyStringArray.cpp \
    MyString.cpp

HEADERS += \
    MyStringArray.h \
    MyString.h

DISTFILES += \
    MyString.pri
