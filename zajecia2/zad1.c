#include <stdio.h>

int main(){
    int a = 5;
    int *b=&a;
    *b=10;
    printf("%d\n",a);
    printf("%d",*b);
    return 0;
}
