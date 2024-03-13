#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    float totalGrade;
}Student;
void sortStudents(Student *students,int size){
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size-1-i; ++j) {
            if(students[j].totalGrade<students[j+1].totalGrade){
                Student temp = students[j];
                students[j]=students[j+1];
                students[j+1]=temp;
            }
        }
    }
}
int main (){
    Student students[100];
    char temp[50];
    for(int i=0;i<100;i++){
        sprintf(temp,"Student %d",i+1);
        students[i].name=strdup(temp);
        students[i].totalGrade=(rand()%6)+1;//1-6
    }
    sortStudents(students,100);
    for (int i = 0; i < 100; ++i) {
        printf("%s - %.2f\n", students[i].name, students[i].totalGrade);
    }
    return 0;
}