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
        default: return "Unbekanntes Genre";
    }
}

typedef struct {
    char title[32];
    genre genre_type;
    int year;
    int amount;
} book;

// Knoten für die verkettete Liste der Bücher
typedef struct bookNode {
    book content;
    struct bookNode *next;
} bookNode;

// Knoten für die verkettete Liste der ausgeliehenen Bücher
typedef struct borrowNode {
    char title[32];
    char name[32];
    struct borrowNode *next;
} borrowNode;

// Funktionen zum Erstellen neuer Knoten
bookNode* createBookNode(char* title, genre genre_type, int year, int amount) {
    bookNode* newBookNode = (bookNode*)malloc(sizeof(bookNode));
    strcpy(newBookNode->content.title, title);
    newBookNode->content.genre_type = genre_type;
    newBookNode->content.year = year;
    newBookNode->content.amount = amount;
    newBookNode->next = NULL;
    return newBookNode;
}

borrowNode* createBorrowNode(char* title, char* name) {
    borrowNode* newBorrowNode = (borrowNode*)malloc(sizeof(borrowNode));
    strcpy(newBorrowNode->title, title);
    strcpy(newBorrowNode->name, name);
    newBorrowNode->next = NULL;
    return newBorrowNode;
}

// Funktion zum Hinzufügen eines Buches zur Liste
void insertBook(bookNode** head) {
    // Erstellen Sie einen neuen Knoten für das Buch
    bookNode* newBook = (bookNode*)malloc(sizeof(bookNode));

    if (newBook == NULL) {
        printf("\nSpeicher konnte nicht zugewiesen werden!");
        return;
    }

    printf("\nGeben Sie den Titel ein: ");
    scanf("%s", newBook->content.title);

    do {
    printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ");
    scanf("%d", (int*)&newBook->content.genre_type);
    if(newBook->content.genre_type < 1 || newBook->content.genre_type > 4) {
        printf("\nUngueltige Eingabe!");
    }
} while(newBook->content.genre_type < 1 || newBook->content.genre_type > 4);

    do {
    printf("\nGeben Sie das Erscheinungsjahr ein: ");
    scanf("%d", &newBook->content.year);
    if(newBook->content.year <= 0) {
        printf("\nUngueltige Eingabe!");
    }
}   while (newBook->content.year <= 0);

    do {
    printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
    scanf("%d", &newBook->content.amount);
    if(newBook->content.amount <= 0) {
        printf("\nUngueltige Eingabe!");
    }
} while (newBook->content.amount <= 0);

    // Fügen Sie den neuen Knoten am Anfang der Liste ein
    newBook->next = *head;
    *head = newBook;
}

int getListLength(bookNode* head) {
    int count = 0;
    bookNode* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int getListLengthborrowed(borrowNode* borrowed) { // diese liste will ich noch implementieren !!! stand: 9.12.2023 17:02
    int count = 0;
    borrowNode* current = borrowed;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void printList(bookNode* head) {
    bookNode* temp = head;
    int count = 1;

    // Durchlaufen Sie die Liste und geben Sie die Daten jedes Knotens aus
    while (temp != NULL) {
        printf("\n%d: %s, %s (%d)", count, temp->content.title, getGenreString(temp->content.genre_type), temp->content.year);
        //printf("%d: %s\n", count, getGenreString(temp->content.genre_type));
        //printf("%d: %d\n", count, temp->content.year);
        //printf("%d: %d\n", count, temp->content.amount);

        temp = temp->next;
        ++count;
    }
    printf("\n");
}

void printListAusgeliehen(borrowNode* head) {
    borrowNode* temp = head;
    int count = 1;

    // Durchlaufen Sie die Liste und geben Sie die Daten jedes Knotens aus
    while (temp != NULL) {
        printf("\n%d: %s geliehen von %s", count, temp->title, temp->name);
        //printf("%d: %s\n", count, getGenreString(temp->content.genre_type));
        //printf("%d: %d\n", count, temp->content.year);
        //printf("%d: %d\n", count, temp->content.amount);
        temp = temp->next;
        ++count;
    }
    printf("\n");
}

void borrowBook(bookNode* head, borrowNode** borrowed) {

    int length = getListLength(head);

    if (head == NULL) {
        printf("\n\nEs sind keine Buecher im Inventar vorhanden.");
        return;
    }
    printList(head);

int choice;
bookNode* temp;

do {
    printf("\nWelchen Titel moechten Sie leihen? (1-%d): ", length);
    scanf("%d", &choice);

    // Überprüfen Sie, ob die Wahl gültig ist
    temp = head;
    if (choice < 1) {
        printf("\nUngueltige Eingabe!");
    }
    for (int i = 1; i < choice; i++) {
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

    // Überprüfen Sie, ob das Buch verfügbar ist
    if (temp->content.amount < 1) {
        printf("\nBereits alle Exemplare ausgeliehen!");
        return;
    }

    // Überprüfen Sie, ob der Benutzer das Buch bereits ausgeliehen hat
    borrowNode* curr = *borrowed;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0 && strcmp(curr->title, temp->content.title) == 0) {
            printf("\nSie haben diesen Titel bereits ausgeliehen!");
            return;
        }
        curr = curr->next;
    }

    // Fügen Sie das Buch zur Liste der ausgeliehenen Bücher hinzu
    borrowNode* newBorrow = createBorrowNode(temp->content.title, name);
    newBorrow->next = *borrowed;
    *borrowed = newBorrow;

    // Aktualisieren Sie die Anzahl der verfügbaren Bücher
    temp->content.amount--;
}

void returnBook(borrowNode** borrowed) {

    int length = getListLengthborrowed(*borrowed);

    if (*borrowed == NULL) {
        printf("\n\nEs sind keine Titel ausgeliehen!");
        return;
    }

    // Zeigen Sie die ausgeliehenen Bücher in der Liste an
    printListAusgeliehen(*borrowed);

    int choice;
    printf("\nWelchen Titel moechten Sie retournieren? (1-%d): ", length);
    scanf("%d", &choice);

    // Überprüfen Sie, ob die Wahl gültig ist
    borrowNode* temp = *borrowed;
    borrowNode* prev = NULL;
    for (int i = 1; i < choice; i++) {
        if (temp == NULL) {
            printf("\nUngueltige Eingabe!");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    // Entfernen Sie das Buch aus der Liste der ausgeliehenen Bücher
    if (prev == NULL) {
        *borrowed = (*borrowed)->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void bubbleSort(bookNode* arr[], int n) {
    int i, j;
    bookNode* temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j]->content.year > arr[j+1]->content.year) {
                // Tauschen Sie die Elemente, wenn das vorherige Element größer ist
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printListInOrder(bookNode* head) {
    // Zählen Sie die Elemente in der Liste
    int count = 0;
    int num = 1;
    bookNode* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    // Erstellen Sie ein Array und kopieren Sie die Elemente
    bookNode** array = malloc(count * sizeof(bookNode*));
    current = head;
    for (int i = 0; i < count; i++) {
        array[i] = current;
        current = current->next;
    }
    bubbleSort(array, count); //sortiert die elemente des arrays
    // Drucken Sie das Array aus
    for (int i = 0; i < count; i++) {
        printf("\n%d: %s, %s (%d)", num, array[i]->content.title, getGenreString(array[i]->content.genre_type), array[i]->content.year);
        //printf("\n%d: %s, %s (%d)", num, array[i]->name, array[i]->getGenreString(temp->content.genre_type), array[i]->year);
        ++num;
    }
    printf("\n");
    free(array);
}

void freeList(bookNode* head) {
    bookNode* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void freeListborrow(borrowNode* head) {
    borrowNode* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

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
            insertBook(&head); //fkt funktioniert
            break;
        case 'b':
            borrowBook(head, &borrowed); //fkt funktioniert
            break;
        case 'r':
            returnBook(&borrowed); //fkt funktioniert
            break;
        case 'l':
            printList(head); //fkt funktioniert
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
