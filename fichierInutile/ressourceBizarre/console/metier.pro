TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Board.cpp \
        Piece.cpp \
        Player.cpp \
        Position.cpp \
        main.cpp

HEADERS += \
    Board.h \
    Enumeration.h \
    Game.h \
    Piece.h \
    Player.h \
    Position.h \
    View.h

QMAKE_CXXFLAGS += -Wpedantic -Werror
