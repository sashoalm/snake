#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T09:01:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    widget.cpp \
    field.cpp \
    snake.cpp

HEADERS  += mainwindow.h \
    widget.h \
    field.h \
    snake.h

FORMS    += mainwindow.ui
