#include <iostream>
#include "character.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "world.h"


using namespace std;


int main() {

    //world class
    world myworld;
    myworld.setfield();

    //character class
    character hero;
    hero.setcharacter();

    //spielfeld
    int row = myworld.getrow();
    int cols = myworld.getcharcols();
    char field[row][cols];

    //position von character
    int charrow = myworld.getcharrow();
    int charcols = myworld.getcharcols();
    //vorherige position von character
    int prevcharrow = charrow;
    int prevcharcols = charcols;


    myworld.spielfeld(charrow, charcols, prevcharrow, prevcharcols); // erstes Spielfeld wird aufgerufen
    cout << endl;
    //system("cls");


    while(true) {

        int input = _getch(); // Pfeiltasteneingabe erkennen

        if(input == 'x') {
            break;
        }

        switch (input) {
            case 72: // Pfeiltaste nach oben
                // Bewegungslogik nach oben
                if (charrow > 0) {
                    system("cls");
                    //previous positions werden geupdatet
                    prevcharrow = charrow;
                    prevcharcols = charcols;
                    charrow -= 1; //neue Position wird gesetzt
                    myworld.spielfeld(charrow, charcols, prevcharrow, prevcharcols); //neue position wird aufgerufen, alte mit 0 ersetzt

                }
                break;
            case 80: // Pfeiltaste nach unten
                // Bewegungslogik nach unten
                if (charrow < 4) {
                        system("cls");
                    //previous positions werden geupdatet
                    prevcharrow = charrow;
                    prevcharcols = charcols;
                    charrow += 1; //neue Position wird gesetzt
                    myworld.spielfeld(charrow, charcols, prevcharrow, prevcharcols); //neue position wird aufgerufen, alte mit 0 ersetzt

                }
                break;
            case 75: // Pfeiltaste nach links
                // Bewegungslogik nach links
                if (charcols > 0) {
                        system("cls");
                    //previous positions werden geupdatet
                    prevcharrow = charrow;
                    prevcharcols = charcols;
                    charcols -= 1; //neue Position wird gesetzt
                    myworld.spielfeld(charrow, charcols, prevcharrow, prevcharcols); //neue position wird aufgerufen, alte mit 0 ersetzt

                }
                break;
            case 77: // Pfeiltaste nach rechts
                // Bewegungslogik nach rechts
                if (charcols < 4) {
                        system("cls");
                    //previous positions werden geupdatet
                    prevcharrow = charrow;
                    prevcharcols = charcols;
                    charcols += 1; //neue Position wird gesetzt
                    myworld.spielfeld(charrow, charcols, prevcharrow, prevcharcols); //neue position wird aufgerufen, alte mit 0 ersetzt

                }
                break;
            default:
                // Ungültige Eingabe
                break;
        }

    }

    return 0;
}
