#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxappointments 10
#define maxlength 50

struct appointment {int time; int duration; char type[maxlength];};
void printAppointments(struct appointment * schedule, int length);
void printInformation(struct appointment * schedule, int length);
struct appointment createAppointment();
void addAppointment(struct appointment * schedule, int * length);
void deleteAppointment(struct appointment * schedule, int * length);

int main()
{
    int curr = 0;
    struct appointment schedule[maxappointments];
    char choice;

    while(1) {
        printf("\nNeuen Termin (n), Termin loeschen (d), Termine auflisten (l), Informationen ausgeben (i), Programm beenden (x)");
        printf("\nAuswahl: ");
        scanf(" %c", &choice);
        if (choice == 'x') {
            break;
        }

        switch(choice) {
        case 'n':
            addAppointment(schedule, &curr);
            break;
        case 'd':
            deleteAppointment(schedule, &curr);
            break;
        case 'l':
            printAppointments(schedule, curr);
            break;
        case 'i':
            printInformation(schedule, curr);
            break;
        default:
            printf("\nUngueltige Eingabe!");
            break;
        }
    }
    return 0;
}

void printAppointments(struct appointment * schedule, int length) { // Eine Liste mit Infos über eingetragene Termine.
    for(int i = 0; i < length; i++) {
        printf("\n%d: %s: %d Uhr, Dauer %dh", i + 1, schedule[i].type, schedule[i].time, schedule[i].duration);
    }
}

void printInformation(struct appointment * schedule, int length) { // Infos über Termine
    int ftermine = 0, btermine = 0, ptermine = 0, gesamtzeit = 0, kollision = 0;
    for(int i = 0; i < length; i++) {
        if (strcmp(schedule[i].type, "Freunde") == 0) {
            ++ftermine;
        }
        else if (strcmp(schedule[i].type, "Geschaeftlich") == 0) {
            ++btermine;
            gesamtzeit += schedule[i].duration;
        }
        else if (strcmp(schedule[i].type, "Pause") == 0) {
            ++ptermine;
        }}
    for(int i = 0; i < length; i++) {
        if(i > 0 && schedule[i-1].time + schedule[i-1].duration != schedule[i].time) {
            if(schedule[i-1].time + schedule[i-1].duration > schedule[i].time) {
                printf("\nEntweder Termin %d oder Termin %d sollte abgesagt werden.", i, i + 1);
                kollision = 1;
                break;
            }
        }
    }
    if(!kollision) {
        printf("\nDer Kalender hat keine Kollisionen!");
        if (gesamtzeit > 8) {
            printf("\nDer Arbeitsanteil ist mit %dh zu lang, achten Sie auf Ihre Work-Life-Balance!", gesamtzeit);
        }
    }
    printf("\nSie haben %d Geschaeftstermin(e), %d Termin(e) mit Freunden und %d Pause(n) in Ihrem Kalender.", btermine, ftermine, ptermine);
}

struct appointment createAppointment() {
    struct appointment newappointment;
    int time, duration;
    char type;
    printf("\nGib einen Typen ein: Freunde (f), Geschaeftlich (b), Pause (p): ");
    scanf(" %c", &type);

    if (type != 'f' && type != 'b' && type != 'p') { //liest ein ob ungültige Eingabe eingegeben wurde
        printf("\nUngueltige Eingabe!");
        return createAppointment();
    }
    do { //schleife, welche solange Ungültige Eingabe! ausgibt, bis etwas richtiges eingeben wurde
        printf("\nGib eine Uhrzeit ein (8-21): ");
        scanf("%d", &time);

        if (time < 8 || time > 21) {
            printf("\nUngueltige Eingabe!");
        }
    } while (time < 8 || time > 21);

    do { //schleife, welche solange Ungültige Eingabe! ausgibt, bis etwas richtiges eingeben wurde
    printf("\nGib eine Dauer ein (1-%d): ", 22 - time);
    scanf("%d", &duration);

        if (duration <= 0 || duration > 22 - time) {
            printf("\nUngueltige Eingabe!");
        }
    } while (duration <= 0 || duration > 22 - time);

    if (type == 'f' && (time >= 8 || time <= 21) && (duration > 0 || duration > 22 - time)) { //wenn "f" eingegebn wird, werden die zugehörigen Daten hinzugefügt
        struct appointment *newAppointment = malloc(sizeof(struct appointment) + 50 * sizeof(char)); //reserviert speicher
        strcpy(newAppointment->type, "Freunde");
        strcpy(newappointment.type, "Freunde");
        newappointment.time = time;
        newappointment.duration = duration;
    }
    else if (type == 'b' && (time >= 8 || time <= 21) && (duration > 0 || duration > 22 - time)) { //wenn "b" eingegebn wird, werden die zugehörigen Daten hinzugefügt
        struct appointment *newAppointment = malloc(sizeof(struct appointment) + 50 * sizeof(char)); //reserviert speicher
        strcpy(newAppointment->type, "Geschaeftlich");
        strcpy(newappointment.type, "Geschaeftlich");
        newappointment.time = time;
        newappointment.duration = duration;
    }
    else if (type == 'p' && (time >= 8 || time <= 21) && (duration > 0 || duration > 22 - time)) { //wenn "p" eingegebn wird, werden die zugehörigen Daten hinzugefügt
        struct appointment *newAppointment = malloc(sizeof(struct appointment) + 50 * sizeof(char)); //reserviert speicher
        strcpy(newAppointment->type, "Pause");
        strcpy(newappointment.type, "Pause");
        newappointment.time = time;
        newappointment.duration = duration;
    }
    return newappointment; // gibt die eingegeben Werte wieder
}

void addAppointment(struct appointment * schedule, int * length) { // fkt fügt neuen Termin hinzu
    if (*length >= maxappointments) { //überprüft ob mehr als 10 Termine im Kalender eingetragen sind.
        printf("\nDer Kalender ist voll!");
        return;
    }

    struct appointment newappointment = createAppointment(); //fügt der struct newappointment die Werte der Funktion createAppointment() hinzu

    int i;
    for (i = 0; i < *length; i++) { // for schleife findet richtige position des Termins
        if (schedule[i].time > newappointment.time || (schedule[i].time == newappointment.time && schedule[i].duration > newappointment.duration)) {
            break;
        }
    }
    for (int k = *length; k > i; k--) { //for schleife verschiebt restliche Termine nach rechts
        schedule[k] = schedule[k - 1];
    }
    schedule[i] = newappointment; // fügt neuen Termin an der Stelle i ein
    (*length)++; //erhöht die Länge des Kalenders um 1
}

void deleteAppointment(struct appointment * schedule, int * length) { //löscht Termin und verschiebt die restlichen Termine in die Korrekte Reihenfolge
    if (*length == 0) {
        printf("\nDer Kalender ist leer!");
        return;
    }

    printAppointments(schedule, *length); //führt die funktion printAppointments aus

    printf("\nWelchen dieser Termine moechten Sie loeschen? (1-%d): ", *length);

    int anzahl;
    do { //schleife gibt solange Ungültige Eingabe! aus bis etwas richtiges eingegeben wird.
        scanf("%d", &anzahl);
        if (anzahl < 1 || anzahl > *length) {
            printf("Ungueltige Eingabe!");
        }
    } while (anzahl < 1 || anzahl > *length);

    for (int i = anzahl - 1; i < *length - 1; i++) { //for schleife verschiebt Termine nach links
        schedule[i] = schedule[i + 1];
    }
    (*length)--; //verringert anzahl der termine wieder.

    printf("\nTermin %d wurde geloescht!", anzahl);
}
