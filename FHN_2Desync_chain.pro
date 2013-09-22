#-------------------------------------------------
#
# Project created by QtCreator 2013-09-20T22:09:56
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = FHN_2Desync_chain
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    fitzhugh_nagumo.cpp \
    DESolver.cpp \
    NetworkSolver.cpp


HEADERS += \
    DESolver.h \
    DynamicalSystem.h \
    fitzhugh_nagumo.h \
    NetworkSolver.h

