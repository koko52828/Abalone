#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game{};
    game.initialize();
    MainWindow w{game};
    w.show();
    return a.exec();
}
