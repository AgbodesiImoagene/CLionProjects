//
// Created by agbod on 4/12/2021.
//

#ifndef COMP10050_ASSIGNMENT2_OTHMOVE_H
#define COMP10050_ASSIGNMENT2_OTHMOVE_H

#include "help.h"

void computeMoves(square arr[][BOARD_SIZE], char colour);

int anyMoveCheck(square arr[][BOARD_SIZE]);

void printMoves(square arr[][BOARD_SIZE], char* str);

void enterMove(square arr[][BOARD_SIZE], char a[]);

void enterPass(char *str);

#endif //COMP10050_ASSIGNMENT2_OTHMOVE_H

