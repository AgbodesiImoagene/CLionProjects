//
// Created by agbod on 4/12/2021.
//

#ifndef COMP10050_ASSIGNMENT2_OTHBOARD_H
#define COMP10050_ASSIGNMENT2_OTHBOARD_H

#include "help.h"

//Function to initialise board
void initBoard(square arr[][BOARD_SIZE]);

//Function to print board and return the result of a check for a full board
int printBoard(square arr[][BOARD_SIZE]);

//Function to update board
void updateBoard(square arr[][BOARD_SIZE], int x, int y, char colour);

#endif //COMP10050_ASSIGNMENT2_OTHBOARD_H
