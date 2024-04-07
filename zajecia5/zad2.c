#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;
    struct Node *next;
} Node;

void push(Node **headRef, int num) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Brak pamięci!\n");
        return;
    }
    newNode->number = num;
    newNode->next = *headRef;
    *headRef = newNode;
}

void pop(Node** node) {
    if (*node == NULL) {
        printf("Lista jest pusta, nie ma elementów do usunięcia.\n");
        return;
    }
    Node *temp = *node;
    *node=(*node)->next;
    free(temp);
}
void printList(Node* node) {
    while (node != NULL) {
        printf("%d\n ", node->number);
        node = node->next;
    }
    printf("\n");
}
int main (){
    Node* head = NULL;
    push(&head, 5);
    push(&head, 10);
    push(&head, 15);
    printList(head);
    pop(&head);
    printList(head);
    return 0;
}