include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibmetier \

SOURCES += \
        BoardTest.cpp \
        GameTest.cpp \
        PositionTest.cpp \
        main.cpp

HEADERS += \
    catch.hpp
