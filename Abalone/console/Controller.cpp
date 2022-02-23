#include "Controller.h"


using namespace std;

Controller::Controller() : game(Game()),view(){
    game.registerObserver(this);
    this->registerObserver(&view);
}

void Controller::startGame(){
    this->game.initialize();
    view.displayBoard(game);
    view.displayCurrentPlayer(game.getCurrent_());
    while(!this->game.isOver()){
        //v.displayBoard(game);
        //v.displayCurrentPlayer(game);
        Position begin = view.displayEnterPosition();
        Position end = view.displayEnterPosition();
        if(game.canPlay(begin,end)){
            game.play(begin,end);
            //game.swapPlayer();
            //v.diplayGoodMove();
        }else{
            view.displayError(this->game,begin,end);
        }

    }view.displayWinner(game.getCurrent_());

}

void Controller::update(const nvs::Subject * subject){
    if(subject != &this->game) return;
    notifyObservers();
}

Game Controller::getGame(){
    return this->game;
}
