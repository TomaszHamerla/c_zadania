#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int computerMove() {
    return rand() % 3; //0 - paper, 1 - rock, 2 - scissors
}

int checkRound(int playerMove, int computerMove) {
    if ((playerMove == 0 && computerMove == 1) || // paper beats rock
        (playerMove == 1 && computerMove == 2) || // rock beats scissors
        (playerMove == 2 && computerMove == 0))   // scissors beat paper
        return 0; // player wins
    else if (playerMove == computerMove)
        return 1; // draw
    else
        return 2; // computer wins
}

int main() {
    int roundCount = 1;
    int playerMove, computerMoveResult;
    int playerWins = 0, computerWins = 0, draws = 0;
    int scores[] = {playerWins, draws, computerWins, roundCount};
    srand(time(NULL));
    while (1) {
        printf("Enter your move:\n0-paper\n1-rock\n2-scissors\n\n3 - end game");
        scanf("%d", &playerMove);
        if (playerMove == 3) {
            break;
        }
        if (playerMove < 0 || playerMove > 2) {
            printf("Incorrect move!\n");
            continue;
        }
        computerMoveResult = computerMove();
        printf("The computer chose %d\n", computerMoveResult);
        int result = checkRound(playerMove, computerMoveResult);
        switch (result) {
            case 0:
                scores[0]++;
                break;
            case 1:
                scores[1]++;

                break;
            case 2:
                scores[2]++;
                break;

        }
    }
    printf("player wins: %d\ndraws: %d\ncomputers wins: %d", scores[0], scores[1], scores[2]);
    return 0;
}