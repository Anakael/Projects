#-------------------------------------------------
#
# Project created by QtCreator 2017-04-26T22:51:08
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Work
TEMPLATE = app

QTPLUGIN += QSQLMYSQL

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES     += qdarkstyle/style.qrc

SOURCES += main.cpp\
        mainwindow.cpp \
    addnewrequest.cpp \
    request.cpp \
    consumer.cpp \
    admin.cpp \
    authentication.cpp \
    material.cpp \
    mysqlqueries.cpp

HEADERS  += mainwindow.h \
    addnewrequest.h \
    request.h \
    consumer.h \
    admin.h \
    authentication.h \
    material.h \
    mysqlqueries.h

FORMS    += mainwindow.ui \
    addnewrequest.ui \
    authentication.ui


