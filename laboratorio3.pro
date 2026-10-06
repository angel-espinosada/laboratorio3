TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        encriptar.cpp \
        lz78.cpp \
        main.cpp \
        rle.cpp

HEADERS += \
    encriptar.h \
    lz78.h \
    rle.h
