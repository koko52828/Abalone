#include "View.h"
#include "Game.h"

#include "windows.h"
#include "Controller.h"
#include "string"

using namespace std;

View::View(){
}

void View::displayBoard(Game g){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout<<"--------------------------------ABALONE--------------------------------"<<endl;
    string hexaspace= "    ";
    int decalageUp=static_cast<int>(g.getBoard_()[0].size())-1;
    int decalageDown=0;
    for(int i = 0; i < static_cast<int>(g.getBoard_().size()); i++){
        if(decalageUp>0){
            for(int s=0;s<decalageUp;s++){
                cout <<hexaspace;
            }
            decalageUp--;
        }else{
            for(int s=0;s<decalageDown;s++){
                cout <<hexaspace;
            }
            decalageDown++;
        }
        for(int j = 0; j < static_cast<int>(g.getBoard_()[i].size()); j++){
            for(int z =0;z<2;z++){
            }
            if(g.getBoard_()[i][j].getColor_()==PlayerColor::Black){
                SetConsoleTextAttribute(hConsole, 8);
                cout << toStringPiece(g.getBoard_()[i][j]);
                // cout << "["<<i<<","<< j<<"]";
            }else   if(g.getBoard_()[i][j].getColor_()==PlayerColor::White){
                SetConsoleTextAttribute(hConsole, 15);
                cout << toStringPiece(g.getBoard_()[i][j]);
                // cout << "["<<i<<","<< j<<"]";

            }else{
                SetConsoleTextAttribute(hConsole, 12);
                cout << toStringPiece(g.getBoard_()[i][j]);
                // cout << "["<<i<<","<< j<<"]";
            }
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"-----------------------------------------------------------------------"<<endl;
}


void View::displayCurrentPlayer(Player p){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 13);
    cout<<"Current player -{ "<<toStringPlayer(p)<<" }-"<<endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout<<"-----------------------------------------------------------------------"<<endl;
}

Position View::displayEnterPosition(){
    char abapro[]={'I','H','G','F','E','D','C','B','A'};
    int x,y;
    char letter;
    cout << "Pleas enter the position of the piece with a space ---> ";

    cin>>letter>>y;
    x=0;
    while(abapro[x]!=toupper(letter)){
        x++;
    }
    Position pos= {x,y};
    cout<<"-----------------------------------------------------------------------"<<endl;
    return pos;
}

void View::displayWinner(Player player){
    cout<<"The winner is player "<<toStringPlayer(player)<<" ! "<<endl;
}
void View::displayError(Game g,Position begin,Position end){
    std::string msg ="";
    if(!(g.isMyOwnGame(begin))){
        msg="This piece is not yours !!";
    }else if((g.isMyOwnGame(end))){
        msg="You can not move your piece into another of your piece !!";
    }else if(!g.isInsideGame(begin.posPieceToIndice())){
        msg="This piece is not inside the board !!";
    }else{
        msg="You can not move to this position !!";
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    cout<<"This mouvement is not allowed ! -> "+msg<<endl;
    SetConsoleTextAttribute(hConsole, 15);
}

void View::displayGoodMove(){
    cout<<"Your game move is done !"<<endl;
}

string View::toStringPlayer(Player p){
    string toString;
    if(p.getColor_()==PlayerColor::Black){
        toString += "Black";
        return toString;
    }else{
        toString += "White";
        return toString;
    }
}

string View::toStringPiece(Piece p){
    string toString = "(";
    string toStringPos = View::toStringPosition(p.getPos_());

    if(p.getColor_()==PlayerColor::Black){
        toString += "B";
        toString += "->" + toStringPos  + ")";
        return toString;
    }else if(p.getColor_()==PlayerColor::White){
        toString += "W";
        toString += "->" + toStringPos  + ")";
        return toString;
    }else{
        toString += "X";
        toString += "->" + toStringPos + ")";
        return toString;
    }
}

std::string View::toStringPosition(Position p){
    char abapro[]={'I','H','G','F','E','D','C','B','A'};
    std::string toString ="";
    toString=toString+abapro[p.getX_()] + ","
            + std::to_string(p.getY_());
    return toString;
}

void View::update(const nvs::Subject *subject){
    Controller observedController = *(Controller *) subject;
    displayGoodMove();
    displayBoard(observedController.getGame());
    displayCurrentPlayer(observedController.getGame().getOpponent_());
}
