//
// Created by agbod on 4/12/2021.
//

#include "othMove.h"

void computeMoves(square arr[][BOARD_SIZE], char colour) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            arr[i][j].mv.check = 0;
            for (int k = 0; k < NUM_DIRECTIONS; ++k) {
                arr[i][j].mv.direction[k] = 0;
            }

            if (arr[i][j].squareChar == ' ')  {
                for (int k = 0; k < NUM_DIRECTIONS; ++k) {
                    dirCheck(arr, k, i, j, colour, 0);
                }

                for (int k = 0; k < NUM_DIRECTIONS; ++k) {
                    if (arr[i][j].mv.direction[k] == 1)  {
                        arr[i][j].mv.check = 1;
                        break;
                    }
                }
            }
        }
    }
}

void printMoves(square arr[][BOARD_SIZE], char* str) {
    printf("The moves for %s are: \n", str);
    for (int k = 0; k < BOARD_SIZE; ++k) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (arr[j][k].mv.check == 1)  {
                printf("%c%d  ", 'a' + k, j + 1);
            }
        }
    }
}

void enterMove(square arr[][BOARD_SIZE], char a[]) {
    puts("");
    printf("Enter the label of the square you want to place a piece on: ");
    scanf("%2s", a);
    int check = 0;
    while (check == 0) {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (arr[i][j].mv.check == 1)  {
                    if (a[0] - 'a' == j && a[1] - '1' == i)  {
                        check = 1;
                    }
                }
            }
        }
        if (check == 0)  {
            printf("Please enter a valid move: ");
            scanf("%2s", a);
        }
    }
}

void enterPass(char *str) {
    puts("");
    printf("There are no available moves for %s so this turn is forfeited. \n", str);
    printf("Enter 'p' to pass: ");
    char y;
    scanf("%c", &y);
    while (y != 'p') {
        printf("Enter 'p' to pass: ");
        scanf("%c", &y);
    }

}

int anyMoveCheck(square arr[][BOARD_SIZE]) {
    int x = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (arr[i][j].mv.check == 1)  {
                x = 1;
                break;
            }
        }
    }
    return x;
}
