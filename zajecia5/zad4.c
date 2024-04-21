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

    return 0;
}
