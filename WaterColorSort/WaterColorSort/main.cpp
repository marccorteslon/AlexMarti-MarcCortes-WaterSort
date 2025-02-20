#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>


using namespace std;

const int NUM_BOTTLES = 6;
const int MAX_CAPACITY = 3;
const char LIQUIDS[] = { 'X', 'O', '#', 'S' };

struct Bottle {
    vector<char> contents;
};

vector<Bottle> bottles(NUM_BOTTLES);
int moves = 0;

void initializeBottles() {
    srand(time(0));
    for (int i = 0; i < NUM_BOTTLES; i++) {
        bottles[i].contents.push_back(LIQUIDS[rand() % 4]);
        bottles[i].contents.push_back(LIQUIDS[rand() % 4]);
    }
    int extra1 = rand() % NUM_BOTTLES;
    int extra2;
    do {
        extra2 = rand() % NUM_BOTTLES;
    } while (extra1 == extra2);
    bottles[extra1].contents.push_back(LIQUIDS[rand() % 4]);
    bottles[extra2].contents.push_back(LIQUIDS[rand() % 4]);
}

void displayBottles() {
    for (int i = 0; i < NUM_BOTTLES; i++) {
        cout << i + 1 << ": ";
        for (char liquid : bottles[i].contents) {
            cout << liquid << " ";
        }
        cout << endl;
    }
}

bool isValidMove(int source, int target) {
    if (source < 0 || source >= NUM_BOTTLES || target < 0 || target >= NUM_BOTTLES)
        return false;
    if (source == target || bottles[source].contents.empty() || bottles[target].contents.size() >= MAX_CAPACITY)
        return false;
    return true;
}

bool checkGameOver() {
    vector<char> uniqueLiquids;
    for (Bottle& b : bottles) {
        if (!b.contents.empty()) {
            char first = b.contents[0];
            for (char liquid : b.contents) {
                if (liquid != first) return false;
            }
            uniqueLiquids.push_back(first);
        }
    }
    return uniqueLiquids.size() <= 1 || moves >= 10;
}

void saveScore(int score) {
    string name;
    cout << "Introdueix el teu nom: ";
    cin >> name;
    ofstream file("scores.wcs", ios::app | ios::binary);
    file << name << " " << score << endl;
    file.close();
}

void playGame() {
    initializeBottles();
    while (!checkGameOver()) {
        displayBottles();
        int source, target;
        cout << "Selecciobna una botella para vaciar: "; cin >> source;
        cout << "Selecciona una botella para llenar: "; cin >> target;
        source--, target--;
        if (isValidMove(source, target)) {
            bottles[target].contents.push_back(bottles[source].contents.back());
            bottles[source].contents.pop_back();
            moves++;
        }
        else {
            cout << "Moviment no vàlid!" << endl;
        }
    }
    cout << "Game Over!" << endl;
    saveScore(30 * NUM_BOTTLES);
}

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

int main() {
    int option;
    do {
        cout << "1. Nova partida\n2. Veure puntuacions\n3. Sortir\n";
        cin >> option;
        if (option == 1) playGame();
        else if (option == 2) showScores();
    } while (option != 3);
    return 0;
}