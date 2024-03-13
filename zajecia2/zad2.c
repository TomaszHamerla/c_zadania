#include <stdio.h>
void addOne(float *a){
    *a+=1;
}
int main(){
    float a =0;
    addOne(&a);
    printf("%f",a);
    return 0;
}
