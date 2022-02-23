#ifndef HEXACELL_H
#define HEXACELL_H

#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <string>
#include <QPointF>

#include "Game.h"
#include "Position.h"


class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;

class HexaCell  : public QGraphicsPolygonItem
{
    static const double zValMax; //z-val of selected items
    double zval; //z-val at instanciation

protected:
    double rad, dx, dy;//hexagon radius, coordinate (x,y) of center
    bool mouseover, selected, moved;//mouse interaction booleans

private:
    Game & game_;
    Position pos_;


public:
    HexaCell(Game & game,Position pos,double rad = 100,
             double dx = 0,
             double dy = 0,
             QGraphicsItem * parent = 0);

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    inline QPointF coord(double x, double y) const;

    inline void setLocation(double x, double y);

    /*!
         * \brief getPos_ give the position of a hexacell
         * \return his position
         */
    Position getPos_();

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void wheelEvent(QGraphicsSceneWheelEvent * event);
};

#endif // HEXACELL_H
