#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Function to find the minimum number of dice of each color required for each game
void find_min_dice(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int game_id = 0;
    unsigned long total_power = 0;

    while (fgets(line, sizeof(line), file)) {
        game_id++;

        int min_red = INT_MAX, min_green = INT_MAX, min_blue = INT_MAX;
        char *token = strtok(line, ";");

        while (token != NULL) {
            int red = 0, green = 0, blue = 0;
            sscanf(token, " %*[^0-9]%d%*[^0-9]%d%*[^0-9]%d", &green, &blue, &red);
            if (red > 0 && red < min_red) min_red = red;
            if (green > 0 && green < min_green) min_green = green;
            if (blue > 0 && blue < min_blue) min_blue = blue;
            token = strtok(NULL, ";");
        }

        unsigned long power = min_red * min_green * min_blue;
        total_power += power;
        printf("Game %d: min_red=%d, min_green=%d, min_blue=%d, power=%lu\n", game_id, min_red, min_green, min_blue, power);
    }

    fclose(file);
    printf("Total power sum: %lu\n", total_power);
}

int main() {
    const char* filename = "input2.txt";
    find_min_dice(filename);
    return 0;
}