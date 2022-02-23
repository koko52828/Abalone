#include "Piece.h"

Piece::Piece(PlayerColor color, Position pos) :
    color {color},
    pos {pos}
{
}

PlayerColor Piece::getColor(){
    return this->color;
}

void Piece::setColor(PlayerColor color){
    this->color = color;
}
