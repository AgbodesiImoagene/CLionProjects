//
// Created by agbod on 4/10/2021.
//

#include "help.h"

void initPlayer(player x[]) {
    int y;

    printf("Enter the name of the first player: ");
    fgets(x[0].name, 49, stdin);
    y = 0;
    while (x[0].name[y] != '\n') {
        y++;
    }
    x[0].name[y] = '\0';
    x[0].colour = 'B';
    printf("%s will move the black pieces. \n", x[0].name);
    printf("Enter the name of the second player: ");
    fgets(x[1].name, 49, stdin);
    y = 0;
    while (x[1].name[y] != '\n') {
        y++;
    }
    x[1].name[y] = '\0';
    x[1].colour = 'W';
    printf("%s will move the white pieces. \n", x[1].name);
}

void dirCheck(square arr[][BOARD_SIZE], int dir, int x, int y, char colour, int len) {
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
    if ((x < 0 || y < 0) || (x > 7 || y > 7))  {
        return;
    }
    if ((len == 0 && arr[x][y].squareChar == colour) || arr[x][y].squareChar == ' ')  {
        return;
    }
    if (len != 0 && arr[x][y].squareChar == colour)  {
        arr[x - (len + 1) * coeff_x][y - (len + 1) * coeff_y].mv.direction[dir] = 1;
        return;
    }
    dirCheck(arr, dir, x, y, colour, ++len);
}

void flipSquares(square arr[][BOARD_SIZE], int dir, int x, int y, char colour, int len) {
    if (arr[x][y].squareChar == colour && len != 0)  {
        return;
    }

    arr[x][y].squareChar = colour;

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
    flipSquares(arr, dir, x, y, colour, ++len);
}

int result(square arr[][BOARD_SIZE], player x[]) {
    int b_count = 0, w_count = 0;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (arr[i][j].squareChar == 'B')  {
                b_count++;
            } else if (arr[i][j].squareChar == 'W')  {
                w_count++;
            }
        }
    }
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
    if ((fp = fopen("../othello-results.txt", "a")) == 0)  {
        puts("File othello-results.txt could not be opened. ");
    } else {
        if (result == 0)  {
            fprintf(fp, "This game ended with a win for %s(%c) over %s(%c). \n\n", x[0].name, x[0].colour, x[1].name, x[1].colour);
        } else if (result == 1)  {
            fprintf(fp, "This game ended with a win for %s(%c) over %s(%c). \n\n", x[1].name, x[1].colour, x[0].name, x[0].colour);
        } else {
            fprintf(fp, "This game ended in a tie between %s(%c) and %s(%c). \n\n", x[0].name, x[0].colour, x[1].name, x[1].colour);
        }
        puts("The result of this game has been appended to othello-results.txt. ");
    }
    fclose(fp);
}
