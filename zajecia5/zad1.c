#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int number;
    struct Node* next;
}Node;

void addFirst(Node** headRef, int number){
    Node* newNode = (Node*)malloc(sizeof (Node));
    if(newNode == NULL){
        printf("Brak pamieci !");
        return;
    }
    newNode->number=number;
    newNode->next=*headRef;
    *headRef=newNode;
}
void printList(Node* node){
    while(node != NULL){
        printf("%d\n",node->number);
        node=node->next;
    }
    printf("\n");
}
int main(){
    Node* head = NULL;
    addFirst(&head,3);
    addFirst(&head,4);
    addFirst(&head,7);
    printList(head);
    return 0;
}