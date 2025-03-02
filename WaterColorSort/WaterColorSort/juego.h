#ifndef JUEGO_H
#define JUEGO_H

#include <vector>

const int TOTAL_AMPOLLES = 6;
const int MAXIM_CAPACITAT = 3;
const char LIQUIDS[] = { 'X', 'O', '#', 'S' };

struct Bottle {
    std::vector<char> contents;
};

extern std::vector<Bottle> ampolles;

void crearBotellas();
void mostrarBotellas();
bool isValidMove(int source, int target);
bool checkGameOver();
void juegaPartida();
int calcularPuntuación();

#endif