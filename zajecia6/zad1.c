#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    data.i = 10;
    printf("Wartość typu int: %d\n", data.i);

    data.f = 220.5;
    printf("Wartość typu float: %f\n", data.f);

    data.c = 'A';
    printf("Wartość typu char: %c\n", data.c);

    return 0;
}
