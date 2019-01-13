#-------------------------------------------------
#
# Project created by QtCreator 2018-05-24T02:50:43
#
#-------------------------------------------------
# added sql
QT       += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HashSaltPassword
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
        main.cpp \
        mainwindow.cpp \
    databaseManager.cpp \
    login.cpp \
    loginManager.cpp \
    loginWindow.cpp \
    addLogin.cpp \
    deleteLogin.cpp \
    forgotUsername.cpp \
    forgotPassword.cpp \
    randomString.cpp

HEADERS += \
        mainwindow.h \
    constants.h \
    databaseManager.h \
    login.h \
    loginManager.h \
    loginWindow.h \
    addLogin.h \
    deleteLogin.h \
    forgotUsername.h \
    forgotPassword.h \
    randomString.h

FORMS += \
        mainwindow.ui \
    loginWindow.ui \
    addLogin.ui \
    deleteLogin.ui \
    forgotUsername.ui \
    forgotPassword.ui

RESOURCES +=
