include(../defaults.pri)

TEMPLATE = app
CONFIG += console

LIBS += -L../lib -llibmetier \

SOURCES += \
        Controller.cpp \
        View.cpp \
        main.cpp

HEADERS += \
    Controller.h \
    View.h
