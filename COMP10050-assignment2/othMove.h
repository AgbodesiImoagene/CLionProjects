//
// Created by agbod on 4/12/2021.
//

#ifndef COMP10050_ASSIGNMENT2_OTHMOVE_H
#define COMP10050_ASSIGNMENT2_OTHMOVE_H

#include "help.h"

//Function to compute the moves an return the result of a check for any valid moves
int computeMoves(square arr[][BOARD_SIZE], char colour);

//Function to print all available moves in specified format
void printMoves(square arr[][BOARD_SIZE], char *str);

//Function to get move from user in specified format
void enterMove(square arr[][BOARD_SIZE], char a[]);

//Function to allow user pass turn
void enterPass(char *str);

#endif //COMP10050_ASSIGNMENT2_OTHMOVE_H

