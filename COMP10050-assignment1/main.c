#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#define STR_LEN 100
#define STR_NUM 100

int input(int argc, char *argv[], char str[][STR_LEN]);
void sortAndPrint(char str[][STR_LEN], int n);
void playlist(char str[][STR_LEN], int n);

int main(int argc, char *argv[]) {
    char string[STR_NUM][STR_LEN];
    int n;
    n = input(argc, argv, string);
    sortAndPrint(string, n);
    playlist(string, n);
    puts("Thank you");
    return 0;
}

int input(int argc, char *argv[], char str[][STR_LEN]) {
    int inputSize;
    FILE *fp;

    if (argc < 2) {
        puts("File not specified. ");
        puts("The program will now read input from artistes+songs.txt. ");
        if ((fp = fopen("artistes+songs.txt", "r")) != NULL) {
            fclose(fp);
            inputSize = fileInput("artistes+songs.txt", str, STR_NUM);
        } else {
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
            inputSize = keyboardInput(str, STR_NUM);
        }
    } else if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("The file %s does not exist or is not readable. ", argv[1]);
        exit(EXIT_FAILURE);
    } else {
        fclose(fp);
        inputSize = fileInput(argv[1], str, STR_NUM);
    }

    return inputSize;
}

void sortAndPrint(char str[][STR_LEN], int n) {
    sortByArtiste(str, n);
    sortBySong(str, n);
    puts("");
    puts("Sorted list of artistes and songs");
    for (int i = 0; i < n; ++i) {
        puts(str[i]);
    }
}

void playlist(char str[][STR_LEN], int n) {
    char play[n][STR_LEN];
    int songNums[n];
    int playlistSize = createPlaylist(str, play, songNums, n);
    printPlaylist(str, play, songNums, n, playlistSize);
}
