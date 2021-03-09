#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int input(int argc, char *argv[], char str[][STR_LEN]);
void sortAndPrint(char str[][STR_LEN], int n);
void playlist(char str[][STR_LEN], int n);

int main(int argc, char *argv[]) {
    char string[STR_NUM][STR_LEN]; //2D array to hold input
    int n; //Holds size of input

    //Function calls
    n = input(argc, argv, string);
    sortAndPrint(string, n);
    playlist(string, n);

    puts("Thank you for using this program. ");
    return 0;
}

int input(int argc, char *argv[], char str[][STR_LEN]) {
    int inputSize;
    FILE *fp;

    if (argc < 2) { //Case that program is called without arguments
        puts("File not specified. ");
        puts("The program will now read input from artistes+songs.txt. ");
        if ((fp = fopen("..//artistes+songs.txt", "r")) != NULL) { //Case that artistes+songs.txt can be opened, read from file
            inputSize = fileInput(fp, str);
        } else { //In the instance it can't be opened enter data from keyboard
            fclose(fp);
            puts("No file found. ");
            puts("Enter input from the keyboard in the following format - ");
            puts("");
            puts("Artiste name");
            puts("Song title***Song duration");
            puts("Song title***Song duration");
            puts("...");
            puts("Song title***Song duration");
            puts("<blank line>");
            puts("Artiste name");
            puts("Song title***Song duration");
            puts("Song title***Song duration");
            puts("...");
            puts("Song title***Song duration");
            puts("<blank line>");
            puts("...");
            puts("");
            puts("\"Song duration\" is in the form [m]m:ss, where [m]m denotes a one- or two-digit number of minutes\n"
                 "and ss denotes a two-digit number of seconds.");
            puts("");
            inputSize = keyboardInput(str);
        }
    } else if ((fp = fopen(argv[1], "r")) == NULL) { //If file specified cannot be opened exit program
        printf("The file %s does not exist or is not readable. ", argv[1]);
        fclose(fp);
        exit(EXIT_FAILURE);
    } else { //If file specified can be opened read from file
        inputSize = fileInput(fp, str);
    }

    return inputSize;
}

void sortAndPrint(char str[][STR_LEN], int n) {
    sortByArtiste(str, n);
    sortBySong(str, n);

    //Print sorted input
    puts("");
    puts("Sorted list of artistes and songs");
    for (int i = 0; i < n; ++i) {
        puts(str[i]);
    }
}

void playlist(char str[][STR_LEN], int n) {
    char play[n][STR_LEN]; //Holds playlist
    int songNums[n]; //Holds song indexes in playlist
    int playlistSize = createPlaylist(str, play, songNums, n);

    printPlaylist(str, play, songNums, n, playlistSize);
}
