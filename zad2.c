#include <stdio.h>

#define SUBJECTS 2
#define STUDENTS 5

int main() {
    int grades[SUBJECTS][STUDENTS];
    float averages[SUBJECTS] = {0, 0};
    printf("Please provide the students' grades\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student: %d\n", i + 1);
        for (int j = 0; j < SUBJECTS; j++) {
            printf("The grade of the subject of %s", j == 0 ? "mathematics" : "physics");
            scanf("%d", &grades[j][i]);
        }
    }
    for (int i = 0; i < SUBJECTS; i++) {
        for (int j = 0; j < STUDENTS; ++j) {
            averages[i] += grades[i][j];
        }
        averages[i] /= STUDENTS;
    }
    printf("The average grade:\n");
    printf("Mathematics: %.f\n", averages[0]);
    printf("Physics: %.f\n", averages[1]);
    return 0;
}