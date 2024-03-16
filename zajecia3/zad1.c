#include <stdio.h>
#include <malloc.h>

int main (){
    int height;
    printf("Podaj wysokosc trojkata");
    scanf("%d",&height);
    int **triangle=(int **)malloc(height * sizeof (int *));
    for (int i = 0; i < height; ++i) {
        triangle[i]=(int *) malloc((i+1) * sizeof(int));
        for (int j = 0; j <=i ; ++j) {
            if(j==0||i==j){
                triangle[i][j]=1;
            } else{
                triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
            }
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        free(triangle[i]);
    }
    free(triangle);
    return 0;
}