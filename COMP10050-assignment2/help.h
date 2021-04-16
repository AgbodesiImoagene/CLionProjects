//
// Created by agbod on 4/10/2021.
//

#ifndef COMP10050_ASSIGNMENT2_HELP_H
#define COMP10050_ASSIGNMENT2_HELP_H

#include <stdio.h>

#define BOARD_SIZE 8
#define NUM_DIRECTIONS 8
#define NAME_LEN 100

typedef struct Move{
    int check;
    int direction[NUM_DIRECTIONS];
} move;

typedef struct Square{
    char squareChar;
    move mv;
} square;

typedef struct Player{
    char name[NAME_LEN];
    char colour;
} player;

//Function to get names from users and set the colour of their pieces
void initPlayer(player x[]);

//Recursive function to check if there is a valid move in a particular direction from an empty square
void dirCheck(square arr[][BOARD_SIZE], int dir, int x, int y, char colour, int len);

//Recursive function to flip discs after a move is made
void flipSquares(square arr[][BOARD_SIZE], int dir, int x, int y, char colour, int len);

//Function to print result and output value that can be interpreted as result by manageFile
int result(square arr[][BOARD_SIZE], player x[]);

//Function to append result to othello-results.txt
void manageFile(int result, player x[]);

#endif //COMP10050_ASSIGNMENT2_HELP_H
