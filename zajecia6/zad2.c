#include <stdio.h>

int main() {
    int tablica[10];
    for (int i = 0; i < 10; i++) {
        tablica[i] = i;
    }

    int *wskaznik = tablica;

    printf("Zawartość tablicy:\n");
    for (int i = 0; i < 10; i++) {
        printf("Element %d: %d\n", i, *(wskaznik + i));
    }

    return 0;
}
