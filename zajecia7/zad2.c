#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int red;
    int green;
    int blue;
} DiceSet;

bool is_game_possible(DiceSet game[], int game_length, int max_red, int max_green, int max_blue) {
    for (int i = 0; i < game_length; i++) {
        if (game[i].red > max_red || game[i].green > max_green || game[i].blue > max_blue) {
            return false;
        }
    }
    return true;
}

int main() {
    int max_red = 12, max_green = 13, max_blue = 14;

    DiceSet games[][10] = {
            {{3, 0, 4}, {1, 2, 6}, {0, 2, 0}},
            {{1, 2, 0}, {1, 3, 4}, {1, 1, 1}},
            {{20, 13, 6}, {4, 13, 5}, {1, 5, 0}},
            {{14, 3, 6}, {6, 3, 6}, {15, 3, 3}},
            {{1, 6, 1}, {1, 2, 2}}
    };

    int game_lengths[] = {3, 3, 3, 3, 2};
    int num_games = sizeof(game_lengths) / sizeof(game_lengths[0]);
    int possible_game_ids_sum = 0;

    for (int i = 0; i < num_games; i++) {
        if (is_game_possible(games[i], game_lengths[i], max_red, max_green, max_blue)) {
            possible_game_ids_sum += i + 1; // Game IDs are 1-based
        }
    }

    printf("Sum of game ID's: %d\n", possible_game_ids_sum);

    return 0;
}