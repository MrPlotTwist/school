#include <stdlib.h>
#include <stdio.h>

struct node
{
    int element;
    struct node* next;
};

int func(struct node* head, int value);
struct node* addBefore(int value, struct node* head);

int main()
{
    struct node* head = NULL;
    head = addBefore(2, head);
    head = addBefore(1, head);
    head = addBefore(2, head);
    head = addBefore(5, head);
    head = addBefore(2, head);
    printf("%d", func(head, 2));

    return 0;
}

int func(struct node* current, int value) {
    if(current == NULL)
        return 0;
    else if(current->element == value)
        return 1 + func(current->next, value);
    else
        return func(current->next, value);
}

struct node* addBefore(int value, struct node* head)
{
    struct node* newHead = (struct node*)malloc(sizeof(struct node));
    newHead->element = value;
    newHead->next = head;
    return newHead;
}

