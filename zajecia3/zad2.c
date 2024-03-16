#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main(){
    int size;
    printf("Podaj wielkosc macierzy");
    scanf("%d",&size);
    int **matrix=(int**)malloc(size * sizeof (int *));
    for (int i = 0; i < size; ++i) {
        matrix[i]=(int*) malloc(size*sizeof (int));
        for (int j = 0; j <size ; ++j) {
            matrix[i][j]=rand()%6;
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <size ; ++j) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}