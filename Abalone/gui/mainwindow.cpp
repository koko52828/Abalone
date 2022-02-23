#include "mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>

#include "hexacell.h"
#include "point.hpp"
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

MainWindow::MainWindow(Game & game, QWidget *parent)
    : QMainWindow(parent), game(game)
{
    game.registerObserver(this);
    QGraphicsScene  * scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::lightGray);
    double rad = 50;

    int line = 5;
    int hauteur = -300;
    int right = 0;
    int decalRight=0;



    for(int i = 0; i < 9; i++){
        for(int j = 0; j < line; j++){
            HexaCell * te= new HexaCell(game,{i,j},rad, right, hauteur, nullptr);
            this->listofhexa.push_back(te);
            scene->addItem(te);
            right += 87;
        }
        hauteur +=75;
        right=0;
        if(hauteur > 0){
            line--;
            decalRight+=43;
        } else {
            line++;
            decalRight-=43;
        }
        right+=decalRight;
    }


    QGraphicsView * view = new QGraphicsView(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::TextAntialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    view->update();
    view->setMaximumHeight(1000);
    view->setMaximumWidth(850);

    resize(1200, 800);

    QGraphicsScene  * scene2 = new QGraphicsScene(this);
    scene2->setBackgroundBrush(Qt::lightGray);

    QGraphicsView * view2 = new QGraphicsView(scene2);
    view2->setMaximumHeight(1000);
    view2->setMaximumWidth(350);

    this->playerlabel = new QLabel(tr("current Player : "));
    this->playervalue = new QLabel(QString::fromStdString(game.getCurrent_().playerToString()));
    this->nbrpiece = new QLabel(tr("Number of piece : "));
    this->nbrpiecetext = new QLabel(QString::number(game.nbrOfCurrentPiece(game.getCurrent_())));


    QFont font = this->playerlabel->font();
    font.setPointSize(18);

    this->playerlabel->setFont(font);
    this->playervalue->setFont(font);
    this->nbrpiece->setFont(font);
    this->nbrpiecetext->setFont(font);



    QGridLayout *mainLayout = new QGridLayout;


    mainLayout->addWidget(playerlabel, 0, 0);
    mainLayout->addWidget(playervalue, 0, 1);
    mainLayout->addWidget(nbrpiece, 1, 0);
    mainLayout->addWidget(nbrpiecetext, 1, 1);





    view2->setLayout(mainLayout);

    QWidget * wid = new QWidget();
    QHBoxLayout test {wid};



    test.addWidget(view);
    test.addWidget(view2);
    this->setCentralWidget(wid);
    this->show();
}
void MainWindow::update(const nvs::Subject * subject){
    Game observedGame = *(Game*) subject;
    for(int i = 0; i < (int) listofhexa.size(); i++){
        listofhexa.at(i)->update();
    }
    this->playervalue->setText(QString::fromStdString(observedGame.getCurrent_().playerToString()));
    this->nbrpiecetext->setText(QString::number(observedGame.nbrOfCurrentPiece(observedGame.getCurrent_())));
}




MainWindow::~MainWindow()
{

}

