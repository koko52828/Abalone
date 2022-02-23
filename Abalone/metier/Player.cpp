#include "Player.h"

using namespace std;

Player::Player(PlayerColor color) :
    color_ {color}
{
}

PlayerColor Player::getColor_(){
    return this->color_;
}

std::string Player::playerToString(){
    if(this->color_==Black){
        return "BLACK";
    }else{
        return "WHITE";
    }
}
