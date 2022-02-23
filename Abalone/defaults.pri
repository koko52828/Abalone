INCLUDEPATH += $$PWD/metier
INCLUDEPATH += $$PWD/console


SRC_DIR = $$PWD

CONFIG -= app_bundle
#CONFIG -= qt
CONFIG += c++17

QMAKE_CXXFLAGS += -Wpedantic -Werror
