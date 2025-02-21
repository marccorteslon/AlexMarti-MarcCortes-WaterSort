#include "Score.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Guarda la puntuacion en un archivo
void saveScore(int score) {
    string name;
    cout << "Introduce tu nombre: ";
    cin >> name;
    ofstream file("scores.wcs", ios::app);
    file << name << " " << score << endl;
    file.close();
}

// Muestra las puntuaciones guardadas
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
