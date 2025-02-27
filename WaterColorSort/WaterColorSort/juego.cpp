#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Definición de las funciones

std::vector<Bottle> ampolles(TOTAL_AMPOLLES);
int moviments = 0;

// Inicializa las botellas
    void crearBotellas() {
        std::vector<char> liquidosRepartidos;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < MAXIM_CAPACITAT; j++) {
                liquidosRepartidos.push_back(LIQUIDS[i]);
            }
        }
        std::random_shuffle(liquidosRepartidos.begin(), liquidosRepartidos.end());

        int index = 0;
        for (int i = 0; i < TOTAL_AMPOLLES; i++) {
            for (int j = 0; j < MAXIM_CAPACITAT && index < liquidosRepartidos.size(); j++) {
                ampolles[i].contents.push_back(liquidosRepartidos[index++]);
            }
        }
    }

// Muestra las botellas en la pantalla
void mostraAmpolles() {
    std::cout << "\n Botellas:" << std::endl;
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

// Comprueba si un movimiento es valido
bool isValidMove(int source, int target) {
    if (source < 0 || source >= TOTAL_AMPOLLES || target < 0 || target >= TOTAL_AMPOLLES)
        return false;
    if (source == target || ampolles[source].contents.empty() || ampolles[target].contents.size() >= MAXIM_CAPACITAT)
        return false;
    return true;
}

// Comprueba si el juego ha terminado
bool checkGameOver() {
    // Comprobar si todas las botellas tienen un solo tipo de líquido
    for (Bottle& b : ampolles) {
        if (!b.contents.empty()) {
            char first = b.contents[0];
            if (b.contents.size() != MAXIM_CAPACITAT) {
                return false;
            }
            for (char liquid : b.contents) {
                if (liquid != first) {
                    return false;  // Si hay más de un tipo de líquido en la botella, el juego no ha terminado
                }
            }
        }
    }
    return true;  // Si todas las botellas tienen solo un tipo de líquido, el juego ha terminado
}


// Funcion principal del juego
void juegaPartida() {
    crearBotellas();
    while (!checkGameOver()) {
        mostraAmpolles();
        int source, target;
        std::cout << "[0 Para terminar] Selecciona una botella para llenar: ";
        std::cin >> target;
        if (target == 0) break;
        std::cout << "Selecciona una botella para llenar: ";
        std::cin >> source;
        if (source == 0) break;
        source--, target--;
        if (isValidMove(source, target)) {
            ampolles[target].contents.push_back(ampolles[source].contents.back());
            ampolles[source].contents.pop_back();
            moviments++;
        }
        else {
            std::cout << "Movimiento no valido!" << std::endl;
        }
    }

    // Aquí se comprueba si se ha ganado
    if (checkGameOver()) {
        std::cout << "¡Has ganado!" << std::endl;
    }
    else {
        std::cout << "Has perdido :(!" << std::endl;
    }
}

