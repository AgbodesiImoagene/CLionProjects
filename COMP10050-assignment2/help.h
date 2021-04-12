//
// Created by agbod on 4/10/2021.
//

#ifndef COMP10050_ASSIGNMENT2_HELP_H
#define COMP10050_ASSIGNMENT2_HELP_H

#include <stdio.h>

#define BOARD_SIZE 8
#define NUM_DIRECTIONS 8

typedef struct Move{
    int check;
    int direction[NUM_DIRECTIONS];
} move;

typedef struct Square{
    char squareChar;
    move mv;
} square;

typedef struct Player{
    char name[50];
    char colour;
} player;

void initPlayer(player x[]);

void dirCheck(square arr[][BOARD_SIZE], int dir, int x, int y, char colour, int len);

void flipSquares(square arr[][BOARD_SIZE], int dir, int x, int y, char colour, int len);

int result(square arr[][BOARD_SIZE], player x[]);

void manageFile(int result, player x[]);

#endif //COMP10050_ASSIGNMENT2_HELP_H
