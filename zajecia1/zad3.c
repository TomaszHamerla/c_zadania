#include <stdio.h>

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

void calculateFactorials(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Factorial for number %d = %d\n", arr[i], factorial(arr[i]));
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);
    calculateFactorials(array, size);
    return 0;
}