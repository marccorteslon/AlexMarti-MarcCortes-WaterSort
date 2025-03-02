#include <iostream>
#include "juego.h"
#include "score.h"

int main() {
    int option;
    do {
        std::cout << "Nueva Partida [1]\nVer Puntuaciones [2]\nSalir [3]\n";
        std::cin >> option;
        if (option == 1) juegaPartida();
        else if (option == 2) showScores();
    } while (option != 3);
    return 0;
}
