//
// Created by agbod on 4/12/2021.
//

#include "othBoard.h"

time_t initBoard(square arr[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) { //Iterate over board
        for (int j = 0; j < BOARD_SIZE; ++j) {
            arr[i][j].squareChar = ' '; //Set squares to empty

            if ((i == 3 || i == 4) && (j == 3 || j == 4))  { //Set initial arrangement of pieces
                if (i == j)  {
                    arr[i][j].squareChar = 'W';
                } else  {
                    arr[i][j].squareChar = 'B';
                }
            }
        }
    }
    time_t t = time(NULL); //Set start time of game
    return t;
}

void printScores(square arr[][BOARD_SIZE], player x[]) {
    int bCount = 0, wCount = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (arr[i][j].squareChar == 'B') {
                bCount++;
            }
            if (arr[i][j].squareChar == 'W') {
                wCount++;
            }
        }
    }
    printf("%s : (%d) \n", x[0].name, bCount);
    printf("%s : (%d) \n", x[1].name, wCount);
}

int printBoard(square arr[][BOARD_SIZE]) {
    int fullBoardCheck = 1; //Holds result of check of whether the board is full or not

    for (int i = 0; i < BOARD_SIZE; ++i) { //Print board outline and square characters
        printf("   ");
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf(" ---");
        }
        printf(" \n %d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("| %c ", arr[i][j].squareChar);
            if (arr[i][j].squareChar == ' ')  { //Empty spaces indicate board is not full
                fullBoardCheck = 0; //Update check
            }
        }
        printf("|\n");
    }
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf(" ---");
    }
    printf("\n   ");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("  %c ", 'a' + i);
    }
    puts("\n\n");
    return fullBoardCheck;
}

void updateBoard(square arr[][BOARD_SIZE], int x, int y, char colour) {
    for (int i = 0; i < NUM_DIRECTIONS; ++i) { //Iterate through all 8 directions
        if (arr[x][y].mv.direction[i] == 1)  { //If there is a valid move in this direction flip pieces
            flipSquares(arr, i, x, y, colour, 0);
        }
    }
}
