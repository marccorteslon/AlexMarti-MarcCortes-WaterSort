#include <iostream>
#include "Juego.h"
#include "Score.h"

int main() {
    int option;
    do {
        std::cout << "1. Nova partida\n2. Veure puntuacions\n3. Sortir\n";
        std::cin >> option;
        if (option == 1) juegaPartida();
        else if (option == 2) showScores();
    } while (option != 3);
    return 0;
}
