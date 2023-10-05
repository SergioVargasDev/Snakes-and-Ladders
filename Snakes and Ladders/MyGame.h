#ifndef MYGAME_H
#define MYGAME_H
using namespace std;

#include "Players.h"
#include "Dice.h"

//? Aquí se estipula la clase hija, MyGame. Donde se concerta asimismo que esta clase hereda de Players y Dice.
class MyGame: public Players, Dice{
public:
//?Aquí se estipulan los métodos de la clase MyGame.
    void start();
    void printTurnInfo(int turn, int currentPlayer, int roll, char tileType, int finalPosition, int currentPosition);
    void processTurn(Players& players);
    char getTileType(int position);

    
};

#endif  // MYGAME_H
