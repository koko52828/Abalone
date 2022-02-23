#include "hexacell.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>

#include <iostream>
#include <cmath>

#include "point.hpp"
#include "View.h"
#include "mainwindow.h"
#include "QMessageBox"

#include "QPushButton"

#include <QApplication>
#include <QProcess>
using namespace std;
double const HexaCell::zValMax = 10000;//arbitrary

HexaCell::HexaCell(Game & game,Position pos, double rad, double dx, double dy, QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent),
      rad(rad), dx(dx), dy(dy),
      mouseover(false), selected(false), moved(false),
      game_(game),pos_(pos)
{


    this->setAcceptHoverEvents(true);
    zval = zValue();

    static const double piOver6 = atan(1) * 4 / 6;

    QPolygonF polygon;
    auto&& corners = orbit({dx, dy}, 6, rad, piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);

}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void HexaCell::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    if(selected)
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::magenta);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else if(mouseover)
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::green);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else if(game_.getBoard_()[pos_.getX_()][pos_.getY_()].getColor_() == PlayerColor::Black){
        QPen pen(Qt::darkGray, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::black);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else if(game_.getBoard_()[pos_.getX_()][pos_.getY_()].getColor_() == PlayerColor::White){
        QPen pen(Qt::black, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::white);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::darkGray);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    this->selected = false;
    painter->drawPolygon(polygon());
}

void HexaCell::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

    if(game_.isOver()){
        QMessageBox win;

        win.setText("The winner is : " + (QString::fromStdString(game_.getOpponent_().playerToString())));
        QPushButton * replay= new QPushButton("REPLAY");
        win.addButton(replay,QMessageBox::AcceptRole);
        QPushButton * quit= new QPushButton("QUIT");
        win.addButton(quit,QMessageBox::RejectRole);
        int ret = win.exec();
        switch(ret){
        case QMessageBox::RejectRole:
            exit(0);
            break;
        case QMessageBox::AcceptRole:
            qApp->quit();
            QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
            break;

        }

    }
    mouseover = true;
    update();
}

void HexaCell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = false;
    update();
}

void HexaCell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{

    if(!game_.isOver()){
        if(game_.getSelectedCase_() == 0){
            game_.setBegin_(this->pos_);
            game_.setSelectedCase_(game_.getSelectedCase_()+1);
        } else if(game_.getSelectedCase_() ==  1){
            game_.setEnd_(this->pos_);
            if(game_.canPlay(game_.getBegin_().posIndiceToPiece(),
                             game_.getEnd_().posIndiceToPiece())){
                game_.play(game_.getBegin_().posIndiceToPiece(),
                           game_.getEnd_().posIndiceToPiece());
            }
            game_.setSelectedCase_(0);
        }

    }
    moved = false;
    selected = !selected;
    update();
    QGraphicsItem::mousePressEvent(event);

}

void HexaCell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

void HexaCell::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    moved = true;
}

void HexaCell::wheelEvent(QGraphicsSceneWheelEvent *event)
{

    QGraphicsItem::wheelEvent(event);
}

Position HexaCell::getPos_(){
    return this->pos_;
}



#pragma GCC diagnostic pop

