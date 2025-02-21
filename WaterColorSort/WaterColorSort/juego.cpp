#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Definición de las funciones

std::vector<Bottle> ampolles(TOTAL_AMPOLLES);
int moviments = 0;

// Inicializa las ampolles con líquids aleatoris
void inicialitzaAmpolles() {
    srand(time(0));
    for (int i = 0; i < TOTAL_AMPOLLES; i++) {
        ampolles[i].contents.push_back(LIQUIDS[rand() % 4]);
        ampolles[i].contents.push_back(LIQUIDS[rand() % 4]);
    }
    int extra1 = rand() % TOTAL_AMPOLLES;
    int extra2;
    do {
        extra2 = rand() % TOTAL_AMPOLLES;
    } while (extra1 == extra2);
    ampolles[extra1].contents.push_back(LIQUIDS[rand() % 4]);
    ampolles[extra2].contents.push_back(LIQUIDS[rand() % 4]);
}

// Mostra les ampolles en format contenidor
void mostraAmpolles() {
    std::cout << "\n Ampolles:" << std::endl;
    for (int j = 0; j < TOTAL_AMPOLLES; j++) {
        std::cout << "Y   Y ";
    }
    std::cout << std::endl;
    for (int i = MAXIM_CAPACITAT - 1; i >= 0; i--) {
        for (int j = 0; j < TOTAL_AMPOLLES; j++) {
            if (ampolles[j].contents.size() > i) {
                std::cout << "| " << ampolles[j].contents[i] << " | ";
            }
            else {
                std::cout << "|   | ";
            }
        }
        std::cout << std::endl;
    }
    for (int j = 0; j < TOTAL_AMPOLLES; j++) {
        std::cout << "' ' ' ";
    }
    std::cout << std::endl;
    for (int j = 0; j < TOTAL_AMPOLLES; j++) {
        std::cout << "  " << j + 1 << "   ";
    }
    std::cout << std::endl;
}

// Comprova si un moviment és vàlid
bool isValidMove(int source, int target) {
    if (source < 0 || source >= TOTAL_AMPOLLES || target < 0 || target >= TOTAL_AMPOLLES)
        return false;
    if (source == target || ampolles[source].contents.empty() || ampolles[target].contents.size() >= MAXIM_CAPACITAT)
        return false;
    return true;
}

// Comprova si el joc ha acabat
bool checkGameOver() {
    std::vector<char> uniqueLiquids;
    for (Bottle& b : ampolles) {
        if (!b.contents.empty()) {
            char first = b.contents[0];
            for (char liquid : b.contents) {
                if (liquid != first) return false;
            }
            uniqueLiquids.push_back(first);
        }
    }
    return uniqueLiquids.size() <= 1 || moviments >= 10;
}

// Funció principal del joc
void juegaPartida() {
    inicialitzaAmpolles();
    while (!checkGameOver()) {
        mostraAmpolles();
        int source, target;
        std::cout << "(0 per acabar) Selecciona una ampolla per omplir: ";
        std::cin >> target;
        if (target == 0) break;
        std::cout << "Selecciona una ampolla per buidar: ";
        std::cin >> source;
        if (source == 0) break;
        source--, target--;
        if (isValidMove(source, target)) {
            ampolles[target].contents.push_back(ampolles[source].contents.back());
            ampolles[source].contents.pop_back();
            moviments++;
        }
        else {
            std::cout << "Moviment no vàlid!" << std::endl;
        }
    }
    std::cout << "Has perdido :(!" << std::endl;
}
