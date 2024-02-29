#include <stdio.h>
#include <stdlib.h>

typedef struct positionant {
    int position;
    char richtung;
} positionant;

char direction(char* richtung, int* position, char array[]);

int main()
{
    char array[100];
    int turns, startposition1, startposition2, finalposition;
    printf("Number of turns: ");
    scanf("%d", &turns);
    printf("Start position: ");
    scanf("%d", &startposition1);
    scanf(" %d", &startposition2);
    positionant *ant_ptr = malloc(sizeof(struct positionant));
    ant_ptr->richtung = 'W'; //richtung in die die ameise schaut; Kann folgende richtungen haben: Norden N, Osten O, Süden S, Westen W


    finalposition = startposition1 + (startposition2 * 10); //startposition ist richtig
    ant_ptr->position = finalposition; //erste position geht zeilenmäßig, zweite position geht reihe nach unten
    //printf("%d", ant_ptr->position);
    //printf("%c", array[startposition1]);
    for (int i = 0; i < 100; i++) { //array mit 10 mal 10 '.' quadrat
        array[i] = '.';
        //if (i % 10 == 0) {
            //printf("\n");
        //}
        //printf("%c", array[i]);
        //printf("%c", array[i]);
        //printf("%c", array[i]); //probe ob quadrat richtig ausgegeben wird
    }
    for (int j = 0; j < turns; j++) {
        direction(&(ant_ptr->richtung), &(ant_ptr->position), array);
        if (array[ant_ptr->position] == 'x') { //x für tod auf weißem feld
            break;
        }
        else if (array[ant_ptr->position] == 'y') { //y für tod auf schwarzem feld
            break;
        }
    }
        if (array[ant_ptr->position] == 'x') { //x für tod auf weißem feld
            array[ant_ptr->position] = '#';
        }
        else if (array[ant_ptr->position] == 'y') { //y für tod auf schwarzem feld
            array[ant_ptr->position] = '.';
        }
        else if (array[ant_ptr->position] == '.') {
            array[ant_ptr->position] = 'a';
        }
        else if (array[ant_ptr->position] == '#') {
            array[ant_ptr->position] = 'A';
        }
    for (int i = 0; i < 100; i++) { //array mit 10 mal 10 '.' quadrat
        if (i % 10 == 0 && i > 1) {
            printf("\n");
        }
        printf("%c", array[i]);
        //printf("%c", array[i]); //probe ob quadrat richtig ausgegeben wird
    }

    //printf("%c", ant_ptr->richtung);
    free(ant_ptr);
    return 0;
}

char direction(char* richtung, int* position, char array[]) { //funktion muss noch ordentlich ausgearbeitet werden
    //printf("hi");
    //printf("das ist die richtung %c", *richtung);
    //printf("das ist die position %d", *position);
    switch(*richtung) { //switchcase fürs berechnen von richtung der ameise

    case 'W': if (array[*position] == '.') {
                array[*position] = '#';
                if (*position < 10) {
                    array[*position] = 'x';
                    break;
                }
                *richtung = 'N'; //case für wann die ameise stirbt
                *position = *position - 10;
                break;
              }
              if (array[*position] == '#') {
                array[*position] = '.';
                if (*position > 90) {
                    array[*position] = 'y';
                    break;
                }
                *richtung = 'S';
                *position = *position + 10;
                break;
              }
            break;
    case 'N': if (array[*position] == '.') {
                array[*position] = '#';
                if (*position % 10 == 9) {
                    array[*position] = 'x';
                    break;
                }
                *richtung = 'O';
                *position = *position + 1;
                break;
              }
              if (array[*position] == '#') {
                array[*position] = '.';
                if (*position % 10 == 0) {
                    array[*position] = 'y';
                    break;
                }
                *richtung = 'W';
                *position = *position - 1;
                break;
              }
            break;
    case 'O': if (array[*position] == '.') {
                array[*position] = '#';
                if (*position > 90) {
                    array[*position] = 'x';
                    break;
                }
                *richtung = 'S';
                *position = *position + 10;
                break;
              }
              if (array[*position] == '#') {
                array[*position] = '.';
                *richtung = 'N';
                if (*position < 10) {
                    array[*position] = 'y';
                    break;
                }
                *position = *position - 10;
                break;
              }
            break;
    case 'S': if (array[*position] == '.') {
                array[*position] = '#';
                if (*position % 10 == 0) {
                    array[*position] = 'x';
                    break;
                }
                *richtung = 'W';
                *position = *position - 1;
                break;
              }
              if (array[*position] == '#') {
                array[*position] = '.';
                if (*position % 10 == 9) {
                    array[*position] = 'y';
                    break;
                }
                *richtung = 'O';
                *position = *position + 1;
                break;
              }
            break;
    default: printf("hat nicht geklappt");
            break;
    }
    return *richtung;
}
