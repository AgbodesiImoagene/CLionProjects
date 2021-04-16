//
// Created by agbod on 4/10/2021.
//

#include "help.h"

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

void flipSquares(square arr[][BOARD_SIZE], int dir, int x, int y, char colour, int len) {
    if (arr[x][y].squareChar == colour && len != 0)  { //Base case that all pieces from empty space to a disc of your colour have been flipped
        return;
    }

    arr[x][y].squareChar = colour; //Set new colour of squares

    //Update indices
    int coeff_x, coeff_y;
    if (dir < 2 || dir > 6)  {
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
    x += coeff_x;
    y += coeff_y;

    flipSquares(arr, dir, x, y, colour, ++len); //Recursive call
}

int result(square arr[][BOARD_SIZE], player x[]) {
    int b_count = 0, w_count = 0; //Hold counts of each colour of pieces

    //Count pieces
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (arr[i][j].squareChar == 'B')  {
                b_count++;
            } else if (arr[i][j].squareChar == 'W')  {
                w_count++;
            }
        }
    }

    //Print result
    if (b_count > w_count)  {
        printf("%s won this game. \n", x[0].name);
        return 0;
    } else if (b_count < w_count)  {
        printf("%s won this game. \n", x[1].name);
        return 1;
    } else {
        printf("This game ended in a draw. \n");
        return -1;
    }
}

void manageFile(int result, player x[]) {
    FILE *fp;

    if ((fp = fopen("../othello-results.txt", "a")) == 0)  { //Check that file can be opened
        puts("File othello-results.txt could not be opened. ");
    } else {
        if (result == 0)  { //Print result to file
            fprintf(fp, "This game ended with a win for %s(%c) over %s(%c). \n\n", x[0].name, x[0].colour, x[1].name, x[1].colour);
        } else if (result == 1)  {
            fprintf(fp, "This game ended with a win for %s(%c) over %s(%c). \n\n", x[1].name, x[1].colour, x[0].name, x[0].colour);
        } else {
            fprintf(fp, "This game ended in a tie between %s(%c) and %s(%c). \n\n", x[0].name, x[0].colour, x[1].name, x[1].colour);
        }
        puts("The result of this game has been appended to othello-results.txt. ");
    }

    fclose(fp); //Close file
}
