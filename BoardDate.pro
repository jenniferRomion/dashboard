QT       += core gui widgets qml quick

TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
# CONFIG -= qt

SOURCES += cpp/main.cpp \
    cpp/mycontext.cpp \
    cpp/postit.cpp \
    cpp/bloc.cpp \
    cpp/carnet.cpp

HEADERS += \
    cpp/mycontext.h \
    cpp/postit.h \
    cpp/bloc.h \
    cpp/carnet.h

DISTFILES += \
    qml/main.qml \
    qml/script.js \
    qml/Window2.qml \
    qml/Mypostit.qml \
    qml/Mycarnet.qml \
    Images/punaise.png \
    Images/blocNote.png \
    Images/Delete-icon2.png \
    qml/Calendrier.qml
