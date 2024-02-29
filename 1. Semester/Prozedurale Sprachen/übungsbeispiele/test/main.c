#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int n;
    struct Node* next;
} Node;

Node* create(int n) {
    Node* newnode = malloc(sizeof(Node));
    newnode->n = n;
    newnode->next = NULL;

    return newnode;
}

Node* addFirst(Node* head, int newint) {
    Node* newnode = create(newint);
    newnode->next = head;

    return newnode;
}

Node* addBack(Node* head, int newint) {
    Node* newnode = create(newint);
    Node* temp = head;

    if(head == NULL) {
        return newnode;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

Node* odd(Node* head, int newint) {
    Node* newnode = create(newint);
    Node* temp = head;

    if(head == NULL) {
        return;
    }

    while(temp != NULL) {
        if(temp->n < newint) {
            temp->n += newint;
            break;  // Once the addition is done, break out of the loop
        }
        temp = temp->next;  // Move to the next node
    }

    return head;
}


void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->n);
        if(head->next != NULL)
            printf("-");
        head = head->next;
    }
    printf("\n");
}

void printCount(Node* head, int count) {
    while (head != NULL) {
            ++count;
        head = head->next;
    }
    printf("Anzahl der Mitglieder: %d", count);

    printf("\n");
}

int main() {
    Node* head = NULL;
    int n;
    int count = 0;

    do {
        printf("Input: ");
        scanf("%d", &n);
        if (n > 0) {
            //NODE INSERTION
            if(n % 2 == 0) {
                head = addBack(head, n);
            } else {
                head = odd(head, n);
            }
            printList(head);
        }
    } while (n > 0);

    //PRINT STATS
    printCount(head, count);

    return 0;
}

