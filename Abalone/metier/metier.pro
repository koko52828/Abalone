include(../defaults.pri)

TEMPLATE = lib
TARGET = libmetier
DESTDIR = ../lib

SOURCES += \
    Board.cpp \
    Game.cpp \
    Piece.cpp \
    Player.cpp \
    Position.cpp \
    subject.cpp

HEADERS += \
    Board.h \
    Enumeration.h \
    Game.h \
    Piece.h \
    Player.h \
    Position.h \
    observer.h \
    subject.h
