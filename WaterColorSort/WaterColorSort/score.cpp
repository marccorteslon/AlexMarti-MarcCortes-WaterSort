#include "Score.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Guarda la puntuació en un fitxer
void saveScore(int score) {
    string name;
    cout << "Introdueix el teu nom: ";
    cin >> name;
    ofstream file("scores.wcs", ios::app);
    file << name << " " << score << endl;
    file.close();
}

// Mostra les puntuacions guardades
void showScores() {
    ifstream file("scores.wcs");
    string name;
    int score;
    while (file >> name >> score) {
        cout << name << ": " << score << endl;
    }
    file.close();
    system("pause");
}
