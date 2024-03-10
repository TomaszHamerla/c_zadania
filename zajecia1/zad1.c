#include <stdio.h>

int main() {
    printf("Give your name");
    char name[10];
    scanf("%s", name);
    printf("Hello %s", name);
    return 0;
}