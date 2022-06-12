// Circular Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} NODE;
NODE *start, *end;

void InsertNode(int ele) {
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = ele;
    newnode->prev = newnode->next = NULL;
    if (start == NULL) {
        start = end = newnode;
        end->prev = newnode;
        end->next = newnode;
    } else {
        end->next = newnode;
        newnode->prev = end;
        newnode->next = start;
        start->prev = newnode;
        end = newnode;
    }
}

void CLLDisplay() {
    NODE *tptr = start;
    do {
        printf("%d ", tptr->data);
        tptr = tptr->next;
    } while (tptr != start);
}

void GetInput() {
    int num;
    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        InsertNode(num);
    }
}

int main() {
    GetInput();
    CLLDisplay();
    return 0;
}