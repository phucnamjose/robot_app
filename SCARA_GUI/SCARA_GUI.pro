#-------------------------------------------------
#
# Project created by QtCreator 2020-02-16T21:15:37
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SCARA_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    robotcontroll.cpp \
    debug.cpp

HEADERS  += \
    debug.hpp \
    mainwindow.hpp \
    robotcontroll.hpp

FORMS    += mainwindow.ui
