#include "MyGame.h"

//?Main del programa
int main() {
    //?Se estipula un objeto "juego" pertinente a la clase hija "MyGame"
    MyGame juego;
    //?Se inicializa el juego mediante insertar el objeto con su respectiva función para generar la clase.
    juego.start();
    return 0;
}