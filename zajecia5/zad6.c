#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void remove_by_index(struct Node** head_ref, int index) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;

    if (index == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    struct Node* next = temp->next->next;

    free(temp->next);

    temp->next = next;
}

void remove_by_value(struct Node** head_ref, int value) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void insert_at_index(struct Node** head_ref, int index, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (index == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;

    if (temp == NULL)
        return;

    new_node->next = temp->next;
    temp->next = new_node;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_list(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    push(&head, 6);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Lista poczatkowa: ");
    print_list(head);

    int index_to_remove = 2;
    remove_by_index(&head, index_to_remove);

    printf("Lista po usunieciu elementu o indeksie %d: ", index_to_remove);
    print_list(head);

    int value_to_remove = 4;
    remove_by_value(&head, value_to_remove);

    printf("Lista po usunieciu elementu o wartosci %d: ", value_to_remove);
    print_list(head);

    int index_to_insert = 2;
    int value_to_insert = 5;
    insert_at_index(&head, index_to_insert, value_to_insert);

    printf("Lista po wstawieniu wartosci %d na indeksie %d: ", value_to_insert, index_to_insert);
    print_list(head);

    return 0;
}
