#include "MyGame.h"
#include <iostream>


void MyGame::start() {
    //?Aquí priemraemnte se estipula el objeto players de la clase Players
    Players players;
    //?Ahora se inicializan los atributos heredados de la clase Players. 
    //=Donde se concertan los métodos setters heredados de la clase Players.
    players.setMaxTurns(100);
    players.setCurrentPlayer(1);
    players.setPlayerPositions(1, 1);
    players.setTurn(1);
    
//?Se establece un for loop mediante los métodos getters estipulando que si el turno es menor al 
//?máximo de turnos, entonces entrará en el loop.
    for (int i = 0; players.getTurn() <= players.getMaxTurns(); i++) {
        cout << "Press C to continue the next turn, or E to end the game: " << endl;
        //?Se estipula la variable option de carácter char, debido a que está nomás contendrá C o E. 
        char option;
        cin >> option;
        //?Se estuipula un while donde mientras que la opción no sea C o E, entonces se reiterará el cin. 
        while (option != 'C' && option != 'E') {
            cout << "Invalid option. Please press C to continue the next turn or E to end the game." << endl;
            cin >> option;
        }

        //?Ya que entré al loop se estipula de que si la opción es C.

        if (option == 'C') {
             //?Aquí se llama al método processTurn argumentando el objeto de players. 
            processTurn(players);
            //?Aquí ahora se llama el método checkWinCondition, donde si cumple se hará un break. 
            if (players.checkWinCondition()) {
                break;
            }

            //?Aquí ahora mediante el objeto players se estipula un setter argumentando el valor del turno más uno.
            players.setTurn(players.getTurn() + 1);
            //?Aquí se estipula que el jugador currente ahora será el otro.
            players.setCurrentPlayer((players.getCurrentPlayer() % 2) + 1);
            //?Aquí ahora se estipula que si la opción es E, se cancelará el juego en sí.
        } else if (option == 'E') {
            cout << "Thanks for playing!!!" << endl;
            break;
        } else {
            cout << "Invalid option. Please press C to continue the next turn or E to end the game." << endl;
        }
    }


//?Aquí se establece que si el turno es mayor a la cantidad máxima de turnos, se establecera un game over. 
    if (players.getTurn() > players.getMaxTurns()) {
        cout << "The maximum number of turns has been reached..." << endl;
    }

    cout << "-- GAME OVER --" << endl;
}


//?Esta función void lo que realiza es imprimir los 6 elementos de la lista. 

void MyGame::printTurnInfo(int turn, int currentPlayer, int roll, char tileType, int finalPosition, int currentPosition) {
    cout << turn << " " << currentPlayer << " " << currentPosition << " " << roll << " " << tileType << " " << finalPosition << endl; 
}

//?Esta es la función madre, donde se estipulan nuevas variables mediante el uso de los objetos crerados.
void MyGame::processTurn(Players& players) {
    Dice dice;
    int roll = dice.roll();
    int* playerPositions = players.getPlayerPositions();
    int currentPlayer = players.getCurrentPlayer();
    int currentPosition = playerPositions[currentPlayer - 1];
    int newPosition = currentPosition + roll;
    char tileType = getTileType(newPosition);

//?Aquí se concreta que si el tyleType es L; es decir, ladder, entonces la posición nueva será con un agregado de 3.
    if (tileType == 'L') {
        newPosition += 3;

//?Aquí se concreta que si el tyleType es S; es decir, Snake, entonces la posición nueva será con una disminución de 3.

    } else if (tileType == 'S') {
        newPosition -= 3;
    }
     
     //?Ahora aquí lo que se realiza es que si la posición es menor a 30, entonces el atributo de playerPositions será igual 
     //? al de new position.
    if (newPosition <= 30) {
        playerPositions[currentPlayer - 1] = newPosition;
    }

    //?Ahora aquí se manda a llamar la función de prinntTurnInfo con los argumentos pertinentes.
    
    printTurnInfo(players.getTurn(), currentPlayer, roll, tileType, playerPositions[currentPlayer - 1], currentPosition);
}

//?Esta función sirve para saber en qué tipo de casilla estás. Yo elegí las estpuladas en las condiciones, donde si dicho se cumple entonces
//?esa casilla se le adjudicará un cierto elemento de tipo char y se utilizará en la condici{on de processTurn para la condicional de la casilla. 
char MyGame::getTileType(int position) {
    if (position == 5 || position == 15 || position == 20) {
        return 'L'; // Escalera
    } else if (position == 6 || position == 16 || position == 21) {
        return 'S'; // Serpiente
    }
    
    return 'N'; // Normal
}
