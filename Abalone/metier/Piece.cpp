#include "Piece.h"

using namespace std;
Piece::Piece(PlayerColor color, Position pos) :
    color_ {color},
    pos_ {pos}
{
}

PlayerColor Piece::getColor_(){
    return this->color_;
}

void Piece::setColor(PlayerColor  color){
    this->color_ = color;
}

void Piece::setPosition(Position pos){
    this->pos_=pos;
}

Position Piece::getPos_(){
    return this->pos_;
}


