#ifndef PLAYERS_H
#define PLAYERS_H
using namespace std;

//? Esta es la clase padre, la cual denominé "Players". Esto debido a que en sí contiene los atributos a utilizar en 
//? la clase MyGame. Estipulé dichos atributos en un área "protected", debido a que en sí los atributos deben de estar en el 
//? ámbito privado; no obstante, como esta clase padre hereda a la clase MyGame, se tienen que poner en un área "protected",ya que 



//? Se crea la clase "Players", la cual en sí es la clase padre.
class Players {
private:

//? Aquí se estipulan concretamente los atributo de esta clase.
    int maxTurns;
    int currentPlayer;
    int playerPositions[2];
    int turn;
//?Aquí se estipulan los métodos de la clase. Donde se implementan funciones void, el constructor, métodos getters y setters en sí.
public:
    Players();
    void setMaxTurns(int _maxTurns);
    void setCurrentPlayer(int _currentPlayer);
    void setPlayerPositions(int position1, int position2);
    void setTurn(int _turn);
    int getMaxTurns();
    int getCurrentPlayer();
    int* getPlayerPositions();
    int getTurn();
    bool checkWinCondition();

};

#endif