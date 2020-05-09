#-------------------------------------------------
#
# Project created by QtCreator 2020-02-16T21:15:37
#
#-------------------------------------------------

QT       += core gui charts serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = SCARA_GUI
TEMPLATE = app


SOURCES += main.cpp\
    chart.cpp \
    chartview.cpp \
    chartwindow.cpp \
        mainwindow.cpp \
    robotcontroll.cpp \
    debug.cpp

HEADERS  += \
    chart.hpp \
    chartview.hpp \
    chartwindow.hpp \
    debug.hpp \
    mainwindow.hpp \
    robotcontroll.hpp

FORMS    += mainwindow.ui \
    chartwindow.ui
