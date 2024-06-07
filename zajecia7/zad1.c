#include <stdio.h>
#include <string.h>

int calc(char *line) {
    int length = strlen(line);
    int firstval, lastval;

    for(int i=0; i<length; i++) {
        if (line[i] >= '0' && line[i] <= '9'){
            firstval = line[i] - '0';
            break;
        }
    }

    for(int i= length -1; i >= 0;i--) {
        if(line[i] >= '0' && line[i] <= '9') {
            lastval = line[i] - '0';
            break;
        }
    }
    int value = firstval *10 + lastval;
    printf("Number: %d\n", value);
    return value;
}

int main() {
    int sum = 0;

    FILE *file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Cannot find file with provided name!\n");
        return 1;
    }

    char line[100];

    while (fgets(line,sizeof(line),file)!= NULL) {
        sum += calc(line);
    }

    fclose(file);
    printf("Sum of all energetic values: %d\n", sum);
    return 0;
}