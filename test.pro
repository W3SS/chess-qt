#-------------------------------------------------
#
# Project created by QtCreator 2015-08-18T13:06:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamewindow.cpp \
    gameload.cpp

HEADERS  += mainwindow.h \
    gamewindow.h \
    gameload.h

FORMS    += mainwindow.ui \
    gamewindow.ui \
    gameload.ui

RESOURCES += \
    images.qrc
