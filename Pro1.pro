#-------------------------------------------------
#
# Project created by QtCreator 2020-05-30T12:15:11
#
#-------------------------------------------------

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pro1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        addstudentwindw.cpp \
        connection.cpp \
        filebrowser.cpp \
        inqurewindow.cpp \
        loginaccount.cpp \
        main.cpp \
        mainwindow.cpp \
        maplocation.cpp \
        student.cpp \
        studentqt.cpp \
        uerinformwindow.cpp \
        user.cpp

HEADERS += \
        addstudentwindw.h \
        connection.h \
        filebrowser.h \
        inqurewindow.h \
        loginaccount.h \
        mainwindow.h \
        maplocation.h \
        sqliteOperat.h \
        student.h \
        studentqt.h \
        uerinformwindow.h \
        user.h

FORMS += \
        addstudentwindw.ui \
        filebrowser.ui \
        inqurewindow.ui \
        mainwindow.ui \
        uerinformwindow.ui

RESOURCES += \
    Resource.qrc
