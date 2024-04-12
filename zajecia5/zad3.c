#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void remove_last(struct Node** head) {
    if (*head == NULL) {
        printf("Lista jest pusta, nie ma elementów do usunięcia.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* second_last = *head;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    free(second_last->next);
    second_last->next = NULL;
}

void append(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
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

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Lista przed usunięciem ostatniego elementu: ");
    print_list(head);

    remove_last(&head);

    printf("Lista po usunięciu ostatniego elementu: ");
    print_list(head);

    return 0;
}
