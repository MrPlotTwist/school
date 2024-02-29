#include <iostream>
#include <cstdlib>
#include <ctime>
#include "world.h"


// Konstruktor
world::world() {
    // Initialisieren Sie die Attribute, wenn gewünscht
    charreihe = 0;
    charzeile = 0;
}


// Setter
void world::setstartposition() {
    charreihe = 0;
    charzeile = 0;
}

//setter
void world::setfield() { //Werte vom ganzen Array werden gesetzt

    srand(time(0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < cols; ++j) {
                int rng = rand() % 10 + 1; // Zufällige Zahl zwischen 1 und 10 generieren

            // Abhängig von der zufälligen Zahl das entsprechende Zeichen für das Feld setzen
            if (rng <= 4) {
                field[i][j] = '0'; // Leeres Feld
                int emptyposition;
            } else if (rng >= 5 && rng <= 8) {
                field[i][j] = 'X'; // Gefahrenfeld (z.B. mit 'X' markiert)
                int dangerposition;
            } else if (rng == 9) {
                field[i][j] = 'W'; // Brunnenfeld (z.B. mit 'W' markiert)
                int wellposition;
            } else {
                field[i][j] = 'R'; // Reliktfeld (z.B. mit 'R' markiert)
                int reliktposition;
            }
            }
        }
}

void world::spielfeld(int charreihe, int charzeile, int prevcharrow, int prevcharcols) { //Spielfeld wird mitsamt allen Werten ausgegeben
    // Zuerst das vorherige Feld auf '0' setzen
    field[prevcharrow][prevcharcols] = '0';

    // Dann das aktuelle Feld auf 'H' setzen
    field[charreihe][charzeile] = 'H';

    // Das Spielfeld ausgeben
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < cols; ++j) {
            std::cout << field[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


//getter
int world::getcharrow() const {
    return charreihe;
}

int world::getcharcols() const {
    return charzeile;
}

int world::getprevcharcols() const {
    return prevcharzeile;
}

int world::getprevcharrow() const {
    return prevcharreihe;
}

int world::getrow() const {
    return row;
}

int world::getcols() const {
    return cols;
}

