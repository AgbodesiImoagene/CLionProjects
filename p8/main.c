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

//Function to initialise board
void initBoard(square arr[][BOARD_SIZE]);

//Function to print board and return the result of a check for a full board
int printBoard(square arr[][BOARD_SIZE]);

//Function to compute the moves an return the result of a check for any valid moves
int computeMoves(square arr[][BOARD_SIZE], char colour);

//Recursive function to check if there is a valid move in a particular direction from an empty square
void dirCheck(square arr[][BOARD_SIZE], int dir, int x, int y, char colour, int len);

//Function to print all available moves in specified format
void printMoves(square arr[][BOARD_SIZE], char *str);

int main() {
    player p[2]; //Structure array to hold data about the players
    square board[BOARD_SIZE][BOARD_SIZE]; //Structure array to hold data about the board

    initPlayer(p); //Get info from the players and initialise p
    initBoard(board); //Initialise board
    printBoard(board); //Print the board
    computeMoves(board, p[0].colour); //Compute the moves for the the player moving the black pieces
    printMoves(board, p[0].name); //Print the available moves for the player moving the black pieces
    puts("");
    computeMoves(board, p[1].colour); //Compute the moves for the the player moving the white pieces
    printMoves(board, p[1].name); //Print the available moves for the player moving the black pieces
    return 0;
}

void initPlayer(player x[]) {
    int y; //Index to replace '\n' with '\0';

    //Get the name of the first player and assign to them char 'B'
    printf("Enter the name of the first player: ");
    fgets(x[0].name, NAME_LEN, stdin);
    y = 0;
    while (x[0].name[y] != '\n') {
        y++;
    }
    x[0].name[y] = '\0';
    x[0].colour = 'B';
    printf("%s will move the black pieces. \n", x[0].name);

    //Get the name of the second player and assign to them char 'W'
    printf("Enter the name of the second player: ");
    fgets(x[1].name, NAME_LEN, stdin);
    y = 0;
    while (x[1].name[y] != '\n') {
        y++;
    }
    x[1].name[y] = '\0';
    x[1].colour = 'W';
    printf("%s will move the white pieces. \n", x[1].name);
}

void initBoard(square arr[][BOARD_SIZE]) {
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

int computeMoves(square arr[][BOARD_SIZE], char colour) {
    int anyMoveCheck = 0; //Holds result of check for any valid moves
    for (int i = 0; i < BOARD_SIZE; ++i) { //Iterate through board
        for (int j = 0; j < BOARD_SIZE; ++j) {
            //Reset all values of arr[i][j].mv to 0
            arr[i][j].mv.check = 0;
            for (int k = 0; k < NUM_DIRECTIONS; ++k) {
                arr[i][j].mv.direction[k] = 0;
            }

            if (arr[i][j].squareChar == ' ')  {
                for (int k = 0; k < NUM_DIRECTIONS; ++k) { //If square is empty call dirCheck for all 8 directions
                    dirCheck(arr, k, i, j, colour, 0);
                }

                for (int k = 0; k < NUM_DIRECTIONS; ++k) {
                    if (arr[i][j].mv.direction[k] == 1)  { //Update checks
                        arr[i][j].mv.check = 1;
                        anyMoveCheck = 1;
                        break;
                    }
                }
            }
        }
    }
    return anyMoveCheck;
}

void dirCheck(square arr[][BOARD_SIZE], int dir, int x, int y, char colour, int len) {
    //Indices are incremented by values determined by the direction to traverse the board
    //Direction is an integer representation of 8 the cardinal directions with up as 0 and incremented clockwise
    int coeff_x, coeff_y; //Values for indices to be incremented by

    if (dir < 2 || dir > 6)  { //Set values based on dir
        coeff_x = -1;
    } else if (dir == 2 || dir == 6)  {
        coeff_x = 0;
    } else  {
        coeff_x = 1;
    }
    if (dir > 4)  {
        coeff_y = -1;
    } else if (dir == 0 || dir == 4)  {
        coeff_y = 0;
    } else  {
        coeff_y = 1;
    }

    //Update indices
    x += coeff_x;
    y += coeff_y;

    if ((x < 0 || y < 0) || (x > 7 || y > 7))  { //Base case for edges of the board
        return;
    }

    if ((len == 0 && arr[x][y].squareChar == colour) || arr[x][y].squareChar == ' ')  { //Base case for no move
        return;
    }

    if (len != 0 && arr[x][y].squareChar == colour)  { //Base case for valid move
        arr[x - (len + 1) * coeff_x][y - (len + 1) * coeff_y].mv.direction[dir] = 1; //Set square move direction to indicate valid move
        return;
    }

    dirCheck(arr, dir, x, y, colour, ++len); //Recursive call
}

void printMoves(square arr[][BOARD_SIZE], char *str) {
    printf("The moves for %s are: \n", str);
    for (int k = 0; k < BOARD_SIZE; ++k) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (arr[j][k].mv.check == 1)  {
                printf("%c%d  ", 'a' + k, j + 1);
            }
        }
    }
}
