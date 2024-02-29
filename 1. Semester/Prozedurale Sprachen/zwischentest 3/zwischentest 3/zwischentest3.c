#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    Horror = 1,
    Abenteuer,
    Romantik,
    Sachbuch
} genre;

const char* getGenreString(genre type) { //funktion zum ändern von enum --> int wird zu string
    switch(type) {
        case Horror: return "Horror";
        case Abenteuer: return "Abenteuer";
        case Romantik: return "Romantik";
        case Sachbuch: return "Sachbuch";
        default: return 0;
    }
}

typedef struct book { // erstellt struct von einem Buch
    char title[32];
    genre genre_type;
    int year;
    int amount;
} book;

typedef struct bookNode { //erstellt Knoten für die verkettete Liste von Büchern
    book content;
    struct bookNode *next; //Pointer um die Knoten zu verbinden
} bookNode;

bookNode* createBookNode(char* title, genre genre_type, int year, int amount) { // Funktion erstellt neue Knoten
    bookNode* newBookNode = (bookNode*)malloc(sizeof(bookNode)); //weist Speicher für den neuen Knoten zu
    strcpy(newBookNode->content.title, title);
    newBookNode->content.genre_type = genre_type;
    newBookNode->content.year = year;
    newBookNode->content.amount = amount;
    newBookNode->next = NULL; //next Pointer wird auf NULL gesetzt -> zeigt Ende der Liste an
    return newBookNode; //gibt den Knoten zurück
}

typedef struct borrowNode { // erstellt Knoten für die verkettete Liste für die ausgeliehenen Bücher
    char title[32];
    char name[32];
    struct borrowNode *next;
} borrowNode;

borrowNode* createBorrowNode(char* title, char* name) { // Funktion erstellt neuen Knoten für borrowbook Liste
    borrowNode* newBorrowNode = (borrowNode*)malloc(sizeof(borrowNode)); // speicher wird wieder zugewiesen
    strcpy(newBorrowNode->title, title);
    strcpy(newBorrowNode->name, name);
    newBorrowNode->next = NULL;
    return newBorrowNode; //gibt Knoten für borrowbook Liste zurück
}


void insertBook(bookNode** head); // Funktion zum Hinzufügen eines Buches zur Liste; Adresse des Pointers head muss verändert werden
int getListLengthbook(bookNode* head); // gibt die Länge der verketteten Liste book aus
int getListLengthborrowed(borrowNode* borrowed); // gibt die Länge der verketteten liste borrowbook aus
void printList(bookNode* head); //funktion fürs ausgeben der Daten der Liste book
void printListAusgeliehen(borrowNode* head); //funktion fürs ausgeben der Daten aus der Liste borrowbook
void borrowBook(bookNode* head, borrowNode** borrowed); //funktion fürs ausleihen von Büchern
void returnBook(bookNode** amount, borrowNode** borrowed); //Buch wird wieder zurückgegeben
void bubbleSort(bookNode* arr[], int n); //Sortieralgorithmus zum sortieren des arrays
void printListInOrder(bookNode* head); //Funktion fürs ausgegebn von geordneter Liste nach Erscheinungsjahr
void freeList(bookNode* head); //Funktion um am Ende des Programms den Speicher wieder freizugeben
void freeListborrow(borrowNode* head);//Funktion um am Ende des Programms den Speicher wieder freizugeben


int main()
{
    char auswahl;
    bookNode* head = NULL;
    borrowNode* borrowed = NULL;

    while (1) {
    printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)");
    printf("\nAuswahl: ");
    scanf(" %c", &auswahl);

    if (auswahl == 'x') {
        freeList(head);
        freeListborrow(borrowed);
        break;
    }
    switch(auswahl) { // was gemacht werden soll
        case 'n':
            insertBook(&head);
            break;
        case 'b':
            borrowBook(head, &borrowed);
            break;
        case 'r':
            returnBook(&head, &borrowed);
            break;
        case 'l':
            printList(head);
            break;
        case 's':
            printListInOrder(head);
            break;
        default:
            printf("\nUngueltige Eingabe!");
            break;
    }
    }
    return 0;
}

void insertBook(bookNode** head) { // Funktion zum Hinzufügen eines Buches zur Liste; Adresse des Pointers head muss verändert werden
    bookNode* newBook = (bookNode*)malloc(sizeof(bookNode)); //speicher wird zugewiesen

    printf("\nGeben Sie den Titel ein: ");
    scanf("%s", newBook->content.title);

    do { //wiederholt solange bis etwas gültiges Eingegeben wird
    printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ");
    scanf("%d", (int*)&newBook->content.genre_type);
    if(newBook->content.genre_type < 1 || newBook->content.genre_type > 4) {
        printf("\nUngueltige Eingabe!");
    }
}
while(newBook->content.genre_type < 1 || newBook->content.genre_type > 4);

    do { //wiederholt solange bis etwas gültiges Eingegeben wird
    printf("\nGeben Sie das Erscheinungsjahr ein: ");
    scanf("%d", &newBook->content.year);
    if(newBook->content.year <= 0) {
        printf("\nUngueltige Eingabe!");
    }
}
while (newBook->content.year <= 0);

    do { //wiederholt solange bis etwas gültiges Eingegeben wird
    printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
    scanf("%d", &newBook->content.amount);
    if(newBook->content.amount <= 0) {
        printf("\nUngueltige Eingabe!");
    }
}
while (newBook->content.amount <= 0);

    newBook->next = *head; //neuer Knoten wird am Angang der Liste eingefügt
    *head = newBook;
}

int getListLengthbook(bookNode* head) { // gibt die Länge der verketteten Liste book aus
    int count = 0;
    bookNode* current = head;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

int getListLengthborrowed(borrowNode* borrowed) { // gibt die Länge der verketteten liste borrowbook aus
    int count = 0;
    borrowNode* current = borrowed;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

void printList(bookNode* head) { //funktion fürs ausgeben der Daten der Liste book
    bookNode* temp = head; //temp ist temporärer pointer
    int count = 1;
    while (temp != NULL) { //Alle Daten der Liste werden ausgegeben
        printf("\n%d: %s, %s (%d)", count, temp->content.title, getGenreString(temp->content.genre_type), temp->content.year); //gibt daten der Liste aus
        temp = temp->next;
        ++count;
    }
    printf("\n");
}

void printListAusgeliehen(borrowNode* head) { //funktion fürs ausgeben der Daten aus der Liste borrowbook
    borrowNode* temp = head;
    int count = 1;
    while (temp != NULL) {
        printf("\n%d: %s geliehen von %s", count, temp->title, temp->name);
        temp = temp->next;
        ++count;
    }
    printf("\n");
}

void borrowBook(bookNode* head, borrowNode** borrowed) { //funktion fürs ausleihen von Büchern

    int length = getListLengthbook(head); //länge von book Liste

    if (head == NULL) { //überprüft ob überhaupt Daten in der Liste vorhanden sind
        printf("\n\nEs sind keine Buecher im Inventar vorhanden.");
        return;
    }
    printList(head); //Liste von book wird ausgegeben

    int choice;
    bookNode* temp;
    do {
        printf("\nWelchen Titel moechten Sie leihen? (1-%d): ", length);
        scanf("%d", &choice);

        temp = head; //am anfang der Liste wird gestartet
        if (choice < 1) {
            printf("\nUngueltige Eingabe!");
        }
        for (int i = 1; i < choice; i++) { //geht die ganze Liste durch
            if (temp == NULL) {
                printf("\nUngueltige Eingabe!");
                break;
            }
            temp = temp->next;
        }
    } while(temp == NULL || choice < 1);

    char name[32];
    printf("\nGeben Sie Ihren Namen ein: ");
    scanf("%s", name);

    if (temp->content.amount < 1) { //überprüft ob das Buch noch vorhanden ist
        printf("\nBereits alle Exemplare ausgeliehen!");
        return; //springt aus der funktion raus
    }

    borrowNode* curr = *borrowed; //überprüft ob der selbe Nutzer das Buch schon ausgeliehen hat
        while (curr != NULL) {
            if (strcmp(curr->name, name) == 0 && strcmp(curr->title, temp->content.title) == 0) {
                printf("\nSie haben diesen Titel bereits ausgeliehen!");
                return;
            }
            curr = curr->next;
        }
    borrowNode* newBorrow = createBorrowNode(temp->content.title, name); //hier wird das ausgeliehene Buch der Liste der ausgeliehen Büchern hinzugefügt
    newBorrow->next = *borrowed;
    *borrowed = newBorrow;

    temp->content.amount--; //die Anzahl an Büchern, die noch ausgeliehen werden können verringert sich um 1
}

void returnBook(bookNode** head, borrowNode** borrowed) { //Buch wird wieder zurückgegeben

    int length = getListLengthborrowed(*borrowed); //gibt die Länge der Liste von ausgeborgten Büchern wieder

    if (*borrowed == NULL) { //überprüft ob überhaupt Daten in der Liste vorhanden sind
        printf("\n\nEs sind keine Titel ausgeliehen!");
        return;
    }
    printListAusgeliehen(*borrowed); //zeigt die Bücher der Liste von ausgeborgten Büchern an

    int choice;
    printf("\nWelchen Titel moechten Sie retournieren? (1-%d): ", length);
    scanf("%d", &choice);

    //überprüft ob die Eingabe korrekt ist
    borrowNode* temp = *borrowed; //temporärer Pointer wird gesetzt
    borrowNode* priv = NULL;
    bookNode* anzahl = *head;
    char* title = temp->title;
    for (int i = 1; i < choice; i++) {
        if (temp == NULL) {
            printf("\nUngueltige Eingabe!");
            return;
        }
        priv = temp;
        temp = temp->next;
    }
    if (priv == NULL) { //entfernt das Buch aus der Liste von ausgeborgten Büchern
        *borrowed = (*borrowed)->next;
    }
    else {
        priv->next = temp->next;
    }
    while (anzahl != NULL) {
        if (strcmp(anzahl->content.title, title) == 0) {
            anzahl->content.amount++;
            break;
        }
        anzahl = anzahl->next;
    }
    free(temp); //speicher wird freigegeben
}


void bubbleSort(bookNode* arr[], int n) { //Sortieralgorithmus zum sortieren des arrays
    int i, j;
    bookNode* temp;

        for (i = 0; i < n-1; i++) {
            for (j = 0; j < n-i-1; j++) {
                if (arr[j]->content.year > arr[j+1]->content.year) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
}

void printListInOrder(bookNode* head) { //Funktion fürs ausgegebn von geordneter Liste nach Erscheinungsjahr
    //Länge von Liste wird ausgegeben
    int count = 0;
    int num = 1;
    bookNode* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    // Array wird erstellt und Pointer von Buchliste hineingespeichert
    bookNode** array = malloc(count * sizeof(bookNode*)); //array ist Pointer auf die Pointer der Liste
    current = head; //current ist temporärer Pointer
    for (int i = 0; i < count; i++) {
        array[i] = current;
        current = current->next;
    }
    bubbleSort(array, count); //sortiert die elemente des arrays
    for (int i = 0; i < count; i++) { //Array wird ausgegeben
        printf("\n%d: %s, %s (%d)", num, array[i]->content.title, getGenreString(array[i]->content.genre_type), array[i]->content.year);
        ++num;
    }
    printf("\n");
    free(array); //speicher wird wieder freigegeben
}

void freeList(bookNode* head) { //Funktion um am Ende des Programms den Speicher wieder freizugeben
    bookNode* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void freeListborrow(borrowNode* head) { //Funktion um am Ende des Programms den Speicher wieder freizugeben
    borrowNode* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
