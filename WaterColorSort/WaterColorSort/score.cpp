#include "score.h"
#include "Juego.h"
#include <iostream>
#include <fstream>
#include <string>

//Calcula la puntuación en función de lo que hagas en la partida
int calcularPuntuación() {
    int puntuacion = 0;

    for (const Bottle& b : ampolles) {
        if (b.contents.empty()) {
            puntuacion += 50;
        }
        else if (b.contents.size() == MAXIM_CAPACITAT) {
            char first = b.contents[0];
            bool completa = true;

            for (char liquid : b.contents) {
                if (liquid != first) {
                    completa = false;
                    break;
                }
            }
            if (completa) {
                puntuacion += 30;
            }
        }
    }
    return puntuacion;

}

// Guarda la puntuacion en un archivo
void saveScore(int score, const std::string &name) {
    std::ofstream scoreFile("scores.wcs", std::ios::app);
    if (scoreFile.is_open()) {
        scoreFile << name << ": " << score << "\n";
        scoreFile.close();
    }
    else {
        std::cout << "Error de lectura" << std::endl;
    }
}

// Muestra las puntuaciones guardadas
void showScores() {
    std::ifstream scoreFile("scores.wcs");
    std::string line;
    if (scoreFile.is_open()) {
        while (getline(scoreFile, line)) {
            std::cout << line << std::endl;
        }
        scoreFile.close();
    }
    else {
        std::cout << "Error al leer las puntuaciones" << std::endl;
    }
}
