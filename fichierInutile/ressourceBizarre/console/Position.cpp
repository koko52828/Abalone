#include "Position.h"

Position::Position(int x, int y, int z) :
    x {x},
    y {y},
    z {z}
{
}

int Position::getX(){
    return this->x;
}

int Position::getY(){
    return this->y;
}

int Position::getZ(){
    return this->z;
}
