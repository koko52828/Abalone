#include "Position.h"
#include "Game.h"

Position::Position(int x, int y) :
    x_ {x},
    y_ {y}
{
}

int Position::getX_(){
    return this->x_;
}

int Position::getY_(){
    return this->y_;
}

Position Position::operator+(Position pos){
    int x =this->x_+pos.getX_();
    int y=this->y_+pos.getY_();
    return {x,y};
}

Position Position::next(Direction direction){
    Position position = {this->x_, this->y_};
    return position + positionOfDirection(direction);
}

bool Position::equals(Position pos){
    return this->x_==pos.getX_()&&this->y_==pos.getY_();

}


Position Position::posPieceToIndice(){
    int correspondance=0;
    if(this->x_<4){
        correspondance=-4;
        int i=0;
        while(i!=this->x_){
            i++;
            correspondance++;
        }
    }
    return Position{this->x_,this->y_+correspondance};
}


Position Position::posIndiceToPiece(){
    int correspondance=0;
    if(this->x_<4){
        correspondance=4;
        int i=0;
        while(i!=this->x_){
            i++;
            correspondance--;
        }
    }
    return Position{this->x_,this->y_+correspondance};

}

Position Position::positionOfDirection(Direction direction){
    switch(direction){
    case Direction::LEFT :
        return {0,-1};

    case Direction::RIGHT:
        return {0,1};

    case Direction::DOWNLEFT:
        return {1,-1};

    case Direction::DOWNRIGHT:
        return {1,0};

    case Direction::UPLEFT:
        return {-1,0};

    case Direction::UPRIGHT:
        return {-1,1};
    }
    return {0,0};
}




