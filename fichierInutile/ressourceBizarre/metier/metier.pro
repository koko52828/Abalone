TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    Board.h \
    Enumeration.h \
    Game.h \
    Piece.h \
    Player.h \
    Position.h

QMAKE_CXXFLAGS += -Wpedantic -Werror
