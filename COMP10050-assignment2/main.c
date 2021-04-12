
#include "othBoard.h"
#include "othMove.h"
#define BOARD_SIZE 8

int main() {
    player p[2];
    square board[BOARD_SIZE][BOARD_SIZE];

    initPlayer(p);
    initBoard(board);
    printBoard(board);

    int gameOver = 0;
    while (gameOver == 0) {
        int forfeit = 0;
        for (int i = 0; i < 2; ++i) {
            int x = fullBoard(board);
            if (x == 1)  {
                gameOver = 1;
                break;
            }
            computeMoves(board, p[i].colour);
            int y = anyMoveCheck(board);
            if (y == 1)  {
                printMoves(board, p[i].name);
                char input[3];
                enterMove(board, input);
                updateBoard(board, input[1] - '1', input[0] - 'a', p[i].colour);
                printBoard(board);
                forfeit = 0;
            } else {
                enterPass(p[i].name);
                forfeit++;
            }
            if (forfeit == 2)  {
                gameOver = 1;
                break;
            }
        }
    }

    manageFile(result(board, p), p);
    return 0;
}

