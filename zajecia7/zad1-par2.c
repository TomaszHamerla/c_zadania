#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getWordValue(const char *str, int *index) {
    if (strncmp(&str[*index], "one", 3) == 0) {
        *index += 3;
        return 1;
    } else if (strncmp(&str[*index], "two", 3) == 0) {
        *index += 3;
        return 2;
    } else if (strncmp(&str[*index], "three", 5) == 0) {
        *index += 5;
        return 3;
    } else if (strncmp(&str[*index], "four", 4) == 0) {
        *index += 4;
        return 4;
    } else if (strncmp(&str[*index], "five", 4) == 0) {
        *index += 4;
        return 5;
    } else if (strncmp(&str[*index], "six", 3) == 0) {
        *index += 3;
        return 6;
    } else if (strncmp(&str[*index], "seven", 5) == 0) {
        *index += 5;
        return 7;
    } else if (strncmp(&str[*index], "eight", 5) == 0) {
        *index += 5;
        return 8;
    } else if (strncmp(&str[*index], "nine", 4) == 0) {
        *index += 4;
        return 9;
    }
    return -1;
}

int calc(const char *line) {
    int length = strlen(line);
    int firstval = -1, lastval = -1;

    for (int i = 0; i < length; ) {
        char c = tolower(line[i]);
        if (isdigit(c)) {
            firstval = c - '0';
            break;
        } else {
            int numericValue = getWordValue(line, &i);
            if (numericValue != -1) {
                firstval = numericValue;
                break;
            } else {
                i++;
            }
        }
    }

    for (int i = length - 1; i >= 0; ) {
        char c = tolower(line[i]);
        if (isdigit(c)) {
            lastval = c - '0';
            break;
        } else {
            int tempIndex = i;
            int numericValue = getWordValue(line, &tempIndex);
            if (numericValue != -1) {
                lastval = numericValue;
                break;
            } else {
                i--;
            }
        }
    }

    if (firstval == -1 || lastval == -1) {
        return -1;
    }

    int value = firstval * 10 + lastval;
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

    while (fgets(line, sizeof(line), file) != NULL) {
        int num = calc(line);
        if (num != -1) {
            sum += num;
            printf("Number: %d\n", num);
        }
    }

    fclose(file);
    printf("Sum of all energetic values: %d\n", sum);
    return 0;
}