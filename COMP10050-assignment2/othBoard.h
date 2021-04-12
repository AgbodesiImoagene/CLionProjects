//
// Created by agbod on 4/12/2021.
//

#ifndef COMP10050_ASSIGNMENT2_OTHBOARD_H
#define COMP10050_ASSIGNMENT2_OTHBOARD_H

#include "help.h"

void initBoard(square arr[][BOARD_SIZE]);

void printBoard(square arr[][BOARD_SIZE]);

void updateBoard(square arr[][BOARD_SIZE], int x, int y, char colour);

int fullBoard(square arr[][BOARD_SIZE]);

#endif //COMP10050_ASSIGNMENT2_OTHBOARD_H
