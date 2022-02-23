#include "Game.h"

using namespace std;
Game::Game() :
    current_{PlayerColor::Black},
    opponent_{PlayerColor::White},
    board_{}, begin_(0,0), end_(0,0), selectedCase_{0}
{
}

Player Game::getCurrent_(){
    return this->current_;
}

Player Game::getOpponent_(){
    return this->opponent_;
}

Position Game::getBegin_(){
    return this->begin_;
}

Position Game::getEnd_(){
    return this->end_;
}

int Game::getSelectedCase_(){
    return this->selectedCase_;
}

void Game::setBegin_(Position newBegin){
    this->begin_ = newBegin;
}

void Game::setEnd_(Position newEnd){
    this->end_ = newEnd;
}

void Game::setSelectedCase_(int newSlectedCase){
    this->selectedCase_ = newSlectedCase;
}

std::vector<std::vector<Piece>> Game::getBoard_(){
    return this->board_.getBoard_();
}

void Game::initialize(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < static_cast<int>(this->board_.getBoard_()[i].size()); j++){
            this->board_.getBoard_()[i][j].setColor(PlayerColor::White);
        }
    }
    for(int i = 7; i < 9; i++){
        for(int j = 0; j < static_cast<int>(this->board_.getBoard_()[i].size()); j++){
            this->board_.getBoard_()[i][j].setColor(PlayerColor::Black);
        }
    }
    for(int i = 2; i < 5; i++){
        this->board_.getBoard_()[2][i].setColor(PlayerColor::White);
    }

    for(int i = 2; i < 5; i++){
        this->board_.getBoard_()[6][i].setColor(PlayerColor::Black);
    }


}

void Game::swapPlayer(){
    Player temp = this->current_;
    this->current_ = this->opponent_;
    this->opponent_ = temp;
}

bool Game::isOver(){
    if(nbrOfCurrentPiece(this->current_) <= 8 || nbrOfCurrentPiece(this->opponent_) <= 8){
        return true;
    }else{
        return false;
    }
}

int Game::nbrOfCurrentPiece(Player player){
    int count = 0;
    for(int x = 0; x < static_cast<int>(this->board_.getBoard_().size()); x++){
        for(int y = 0; y < static_cast<int>(this->board_.getBoard_()[x].size()); y++){
            Position pos {x,y};
            if(this->board_.getPiece_(pos).getColor_() == player.getColor_()){
                count ++;
            }
        }
    }
    return count;
}



Direction Game::goodDirection(Position pos, Position fin){
    Direction t=Direction::LEFT;
    for(int i=0;i<6;i++){
        Direction test=static_cast<Direction>(i);
        Position nextToNext=pos.next(test);
        if(nextToNext.equals(fin)){
            t=test;
        }else{
            while(this->board_.isInside(nextToNext)){
                nextToNext=nextToNext.next(test);
                if(nextToNext.equals(fin)){
                    t=test;
                }
            }
        }
    }
    return t;

}

bool Game::sumito(Position begin, Direction dir){
    int current = 0;
    int opponent = 0;
    while(this->board_.isInside(begin.posPieceToIndice())&&!this->board_.isFree(begin.posPieceToIndice())){
        std::cout<<"test"<<std::endl;
        if(this->board_.getPiece_(begin.posPieceToIndice()).getColor_()
                == this->current_.getColor_()){
            current++;
        } else if(this->board_.getPiece_(begin.posPieceToIndice()).getColor_()
                  == this->opponent_.getColor_()){
            opponent++;
        }
        if(board_.isInside(begin.posPieceToIndice().next(dir))){
            if(opponent>0&&this->board_.getPiece_(begin.posPieceToIndice()).getColor_()
                    ==this->current_.getColor_()){
                return false;
            }
        }
        begin = begin.next(dir);
    }
    return  current>opponent&&opponent!=0;
}



bool Game::canPlay(Position pos, Position end){
    std::cout << "Position begin : " <<pos.getX_() << "," << pos.getY_() <<std::endl;
    std::cout << "Position end : " <<end.getX_() << "," << end.getY_() <<std::endl;
    Direction dir=goodDirection(pos,end);
    bool can=false;
    int nbrpiece=1;
    if(this->board_.isFree(end.posPieceToIndice())){
        if(pos.next(dir).posPieceToIndice().equals(end.posPieceToIndice())
                &&this->board_.isMyOwn(pos.posPieceToIndice(),this->getCurrent_().getColor_())
                &&!this->board_.isMyOwn(end.posPieceToIndice(),this->getCurrent_().getColor_())){
            can =true;
        }else{
            Position nextnext=pos.next(dir);
            while(this->board_.isInside(nextnext)
                  &&this->board_.isMyOwn(nextnext.posPieceToIndice(),this->getCurrent_().getColor_())){
                nbrpiece++;
                nextnext=nextnext.next(dir);
                if(nextnext.equals(end)){
                    can =true;
                }
            }
        }
    }else if(sumito(pos,dir)){
        can= true;
    }
    return can&&nbrpiece<=3;
}

void Game::play(Position begin, Position end){
    Direction dir=goodDirection(begin,end);
    Position nextnext=begin.next(dir);

    bool findfree=true;

    this->board_.setPieceColor(PlayerColor::Empty,begin.posPieceToIndice());
    while(this->board_.isInside(nextnext.posPieceToIndice())&&findfree){

        if(this->board_.isFree(end.posPieceToIndice())){

            this->board_.setPieceColor(this->getCurrent_().getColor_(),end.posPieceToIndice());
            findfree=false;

        }else{
            this->board_.setPieceColor(this->getCurrent_().getColor_(),end.posPieceToIndice());
            if(this->board_.isFree(nextnext.posPieceToIndice())){
                this->board_.setPieceColor(this->getOpponent_().getColor_(),nextnext.posPieceToIndice());
                findfree=false;

            }
        }
        nextnext=nextnext.next(dir);
    }
    swapPlayer();
    notifyObservers();
}


bool Game::isInsideGame(Position pos){
    return this->board_.isFree(pos);
}

bool Game::isMyOwnGame(Position pos){
    return this->board_.isMyOwn(pos,this->getCurrent_().getColor_());
}


