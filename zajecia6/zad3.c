#include <stdio.h>

int dodaj(int a, int b);
int mnoz(int a, int b);
int odejmij(int a, int b);

int main() {
    int (*funkcja)(int, int);

    int liczba1, liczba2, wynik;
    char operacja;

    printf("Wprowadz pierwsza liczbe: ");
    scanf("%d", &liczba1);

    printf("Wprowadz druga liczbe: ");
    scanf("%d", &liczba2);

    printf("Wybierz operacje (+, *, -): ");
    scanf(" %c", &operacja);

    switch (operacja) {
        case '+':
            funkcja = dodaj;
            break;
        case '*':
            funkcja = mnoz;
            break;
        case '-':
            funkcja = odejmij;
            break;
        default:
            printf("Nieznana operacja\n");
            return 1;
    }

    wynik = funkcja(liczba1, liczba2);
    printf("Wynik: %d\n", wynik);

    return 0;
}

int dodaj(int a, int b) {
    return a + b;
}

int mnoz(int a, int b) {
    return a * b;
}

int odejmij(int a, int b) {
    return a - b;
}
