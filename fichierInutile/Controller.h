#ifndef CONTROLLER_H
#define CONTROLLER_H


#include "Game.h"
#include "View.h"




class Controller{

private :
    Game game;
    View view;


public:
    Controller();
    void initialize();
    void startGame();
};




#endif // CONTROLLER_H
