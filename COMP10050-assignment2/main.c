/*
 * COMP10050 Assignment 2
 * Othello
 * Written by Agbodesi Imoagene
 * Last updated 16/04/2021
 * Github Repository - https://github.com/AgbodesiImoagene/CLionProjects
 */
#include "othBoard.h"
#include "othMove.h"

void manageGame(square arr[][BOARD_SIZE], player x[]); //Function to manage game

int main() {
    player p[2]; //Structure array to hold data about the players
    square board[BOARD_SIZE][BOARD_SIZE]; //Structure array to hold data about the board

    initPlayer(p); //Get info from the players and initialise p
    time_t t = initBoard(board); //Initialise board
    printBoard(board); //Print the board
    manageGame(board, p);
    manageFile(result(board, p), p, &t); //Print results to screen and othello-results.txt
    return 0;
}

 void manageGame(square arr[][BOARD_SIZE], player x[]) {
     int gameOver = 0; //Indicates whether the game is over or not
     int forfeit; //Indicates whether a player has an available move or not
     int fullBoard; //Indicates whether board is full or not
     while (gameOver == 0) {
         for (int i = 0; i < 2; ++i) { //Repeat for each player
             int y = computeMoves(arr, x[i].colour); //Calculate available moves for current player

             if (y == 1)  { //Case that there are available moves
                 printMoves(arr, x[i].name); //Print moves
                 char input[3];
                 enterMove(arr, input); //Get player choice
                 updateBoard(arr, input[1] - '1', input[0] - 'a', x[i].colour); //Update board
                 printScores(arr, x); //Print player scores
                 fullBoard = printBoard(arr); //Print board and check if board is full
                 forfeit = 0;
             } else {
                 enterPass(x[i].name); //Pass move
                 forfeit++;
             }

             //Case that there are no available moves for both players or board is full so game ends
             if (forfeit == 2 || fullBoard == 1)  {
                 gameOver = 1;
                 break;
             }
         }
     }
 }