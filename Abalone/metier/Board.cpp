#include <iostream>
#include "Board.h"

using namespace std;

Board::Board()
{
    //Pas sur mais peut-être l'appelé autre part.
    initialize();
}

std::vector<std::vector<Piece>>& Board::getBoard_(){
    return this->pieces_;
}

size_t Board::getX_(){
    return this->x_;
}

size_t Board::getY_(){
    return this->y_;
}

void Board::initialize(){
    this->pieces_.resize(9);
    int size = 5;
    for(size_t i = 0; i < pieces_.size(); i++){
        this->pieces_[i].resize(static_cast<size_t>(size));
        if(i < pieces_.size()/2){
            size++;
        } else {
            size--;
        }
    }

    int baseX = 0;
    int baseY = 4;
    for(int i = 0; i < static_cast<int>(this->pieces_.size()); i++){
        int y = baseY;
        for(int j = 0; j < static_cast<int>(this->pieces_[i].size()); j++){
            Position pos {baseX,y};
            this->pieces_[i][j].setPosition(pos);
            y++;
        }
        if(i < static_cast<int>(this->pieces_.size()/2)){
            baseY--;
        }
        baseX++;
    }
}

Piece Board::getPiece_(Position position){
    Piece * p = &this->pieces_[position.getX_()][position.getY_()];
    return *p;
}

bool Board::isInside(Position pos){
    if(pos.getX_()>=0
            &&pos.getY_()>=0
            &&pos.getX_()<=(int)this->pieces_.size()-1
            &&pos.getY_()<=(int)this->pieces_.size()-1){
        for(int i=0;i<(int)this->pieces_.size();i++){
            for(int j=0;j<(int)this->pieces_[i].size();j++){


                if(pos.equals(this->getBoard_()[i][j].getPos_())){
                    return true;
                }if(pos.equals({i,j})){
                        return true;
            }
            }
        }

    }return false;
}

void Board::push(Piece & p,Position pos){
    this->pieces_[pos.getX_()][pos.getY_()].setColor(p.getColor_());
}

bool Board::isFree(Position position){
    return  this->getPiece_(position).getColor_()==PlayerColor::Empty ;
}

bool Board::isMyOwn(Position position, PlayerColor color){
    return this->getPiece_(position).getColor_()==color;
}

void Board::setPieceColor(PlayerColor color,Position pos){
    this->pieces_[pos.getX_()][pos.getY_()].setColor(color);
}
