//
// Created by agbod on 4/12/2021.
//

#include "othBoard.h"

void printBoard(square arr[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("   ");
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf(" ---");
        }
        printf(" \n %d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("| %c ", arr[i][j].squareChar);
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
}

void initBoard(square arr[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            arr[i][j].squareChar = ' ';
        }
    }
    arr[3][3].squareChar = 'W';
    arr[3][4].squareChar = 'B';
    arr[4][3].squareChar = 'B';
    arr[4][4].squareChar = 'W';
}

void updateBoard(square arr[][BOARD_SIZE], int x, int y, char colour) {
    for (int i = 0; i < NUM_DIRECTIONS; ++i) {
        if (arr[x][y].mv.direction[i] == 1)  {
            flipSquares(arr, i, x, y, colour, 0);
        }
    }
}

int fullBoard(square arr[][BOARD_SIZE]) {
    int check = 1;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (arr[i][j].squareChar == ' ')  {
                check = 0;
                break;
            }
        }
        if (check == 0)  {
            break;
        }
    }
    return check;
}
