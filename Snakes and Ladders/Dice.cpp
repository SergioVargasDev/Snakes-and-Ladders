#include "Dice.h"
#include <cstdlib>
#include <ctime>

//? Esta función sirve para generar un número aleatorio entre 1 y 6. 

int Dice::roll() {
    srand(static_cast<unsigned int>(time(0)));  
    return rand() % 6 + 1;  
}
