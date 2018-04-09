#-------------------------------------------------
#
# Project created by QtCreator 2018-04-04T11:37:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtEan
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
    canvas.cpp \
    equation.cpp

HEADERS += \
        mainwindow.h \
        interval.h \
    canvas.h \
    equation.h

FORMS += \
        mainwindow.ui \
    canvas.ui
unix {
    INCLUDEPATH += /usr/local/Cellar/boost/1.66.0/include/
    INCLUDEPATH += /usr/local/Cellar/mpfr/4.0.1/include/
    INCLUDEPATH += /usr/local/Cellar/gmp/6.1.2_2/include/

    LIBS +=  -L/usr/local/Cellar/boost/1.66.0/lib/ -lboost_thread-mt -lboost_system-mt
    LIBS += -L/usr/local/Cellar/mpfr/4.0.1/lib/ -lmpfr
    LIBS += -L/usr/local/Cellar/gmp/6.1.2_2/lib/ -lgmp
}
