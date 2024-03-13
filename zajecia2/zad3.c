#include <stdio.h>
typedef struct{
    int x;
    int y;
}point;
void changeXY(point *point){
    point->x+=2;
    point->y+=2;
}
typedef struct{
    int a;
    int b;
}Rectangle;
int getCircuit(Rectangle *rectangle){
    return rectangle->a*2+rectangle->b*2;
}
int main(){
    point p;
    p.x=2;
    p.y=2;
    changeXY(&p);
    printf("%d,%d\n",p.x,p.y);

    Rectangle rectangle={5,4};
    int circuit = getCircuit(&rectangle);
    printf("%d",circuit);
    return 0;
}