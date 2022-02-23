#include "Player.h"

Player::Player(PlayerColor color) :
    color {color}
{
}

PlayerColor Player::getColor(){
    return this->color;
}
