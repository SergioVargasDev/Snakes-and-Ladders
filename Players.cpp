#include "Players.h"
#include <iostream>
using namespace std;



//?Aquí se inicializan los atributos por default del constructor predeterminado
Players::Players() {
    maxTurns = 100;  // Establecer el número máximo de turnos
    currentPlayer = 1;  // Establecer el jugador actual
    playerPositions[0] = 1;  // Inicializar la posición del jugador 1
    playerPositions[1] = 1;  // Inicializar la posición del jugador 2
    turn = 1;  // Inicializar el contador de turnos
}


//?A continuación están los metodos setters.
void Players::setMaxTurns(int _maxTurns) {
    maxTurns = _maxTurns;
}

void Players::setCurrentPlayer(int _currentPlayer) {
    currentPlayer = _currentPlayer;
}

void Players::setPlayerPositions(int position1, int position2) {
    playerPositions[0] = position1;
    playerPositions[1] = position2;
}

void Players::setTurn(int _turn) {
    turn = _turn;
}

//?A continuación se encuentran los métodos getters.
int Players::getMaxTurns() {
    return maxTurns;
}

int Players::getCurrentPlayer() {
    return currentPlayer;
}

int* Players::getPlayerPositions() {
    return playerPositions;
}

int Players::getTurn() {
    return turn;
}

//?Esta función lo que realiza es checar concretamente si el jugador ha ganado, por ello se estipula que si la posición 
//?del jugador se encuentra en la casilla 30 o mayor, entrará en la condicional y se mandará un cout de que ganó el jugador. 

bool Players::checkWinCondition() {
    if (playerPositions[currentPlayer - 1] >= 30) {
        cout << "Player " << currentPlayer << " is the winner!!!" << endl;
        return true;
    }
    return false;
}
