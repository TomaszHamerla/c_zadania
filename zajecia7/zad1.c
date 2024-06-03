#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Funkcja do obliczania wartości energetycznej z danej linijki
int oblicz_wartosc(char *linijka) {
    int dlugosc = strlen(linijka);
    int pierwsza_cyfra, ostatnia_cyfra;

    // Szukamy pierwszej cyfry w linijce
    for (int i = 0; i < dlugosc; i++) {
        if (isdigit(linijka[i])) {
            pierwsza_cyfra = linijka[i] - '0';
            break;
        }
    }

    // Szukamy ostatniej cyfry w linijce
    for (int i = dlugosc - 1; i >= 0; i--) {
        if (isdigit(linijka[i])) {
            ostatnia_cyfra = linijka[i] - '0';
            break;
        }
    }

    // Obliczamy wartość energetyczną
    return pierwsza_cyfra * 10 + ostatnia_cyfra;
}

int main() {
    FILE *plik;
    char linijka[100];
    int suma = 0;

    // Otwieramy plik
    plik = fopen("dane.txt", "r");
    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku.");
        return 1;
    }

    // Odczytujemy linijki z pliku i obliczamy sumę wartości energetycznych
    while (fgets(linijka, sizeof(linijka), plik) != NULL) {
        suma += oblicz_wartosc(linijka);
    }

    // Zamykamy plik
    fclose(plik);

    printf("Suma wszystkich wartości energetycznych: %d\n", suma);

    return 0;
}
