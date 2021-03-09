//
// Created by Agbodesi Imoagene on 2/22/2021.
//

#include <stdio.h>
#include <string.h>
#include "mylib.h"
#include "help.h"

int fileInput(FILE *pointer, char str[][STR_LEN]) {
    int i = 0;
    while ((!feof(pointer)) && (i < STR_NUM - 1)) { //Read input line by line from file into array and replace '\n' at the end with '\0'
        fgets(str[i], STR_LEN, pointer);
        if (str[i][strlen(str[i]) - 1] == '\n') {
            str[i][strlen(str[i]) - 1] = '\0';
        }
        i++;
    }

    //Deal with multiple or no '\n' characters at end of file
    const char delim[] = "***"; //Delimiter that separates song names and times
    char temp1[STR_LEN]; //Holds string temporarily for strtok function
    strcpy(temp1, str[i - 1]);
    strtok(temp1, delim);
    char *temp2 = strtok(NULL, delim);
    if (temp2 != NULL) { //Case that last line is a song: add an extra empty line
        strcpy(str[i], "");
        i++;
    } else { //If not ensure that the last line is empty then remove extra empty lines
        if (strcmp(str[i - 1], "") != 0) {
            strcpy(str[i - 1], "");
        }
        for (int j = i - 1; j >= 0; --j) { //Check to remove extra '\n' characters at the end of the file
            if (strcmp(str[j], "") != 0) {
                i = j + 2;
                break;
            }
        }
    }

    if (i == STR_NUM) { //Lets user know array is full
        puts("Cannot take more input. ");
    }

    return i;
}

int keyboardInput(char str[][STR_LEN]) {
    puts("Enter EOF(ctrl+z on windows, ctrl+d on unix) on a new line to end input stream. ");
    puts("EOF character might not be fully functional if program is run in CLion. ");
    puts("Enter input: ");
    int i = 0;
    while ((!feof(stdin)) && (i < STR_NUM - 1)) { //Read input line by line from keyboard into array and replace '\n' at the end with '\0'
        fgets(str[i], STR_LEN, stdin);
        if (str[i][strlen(str[i]) - 1] == '\n') {
            str[i][strlen(str[i]) - 1] = '\0';
        }
        i++;
    }

    //Deal with multiple or no '\n' characters at end of input
    const char delim[] = "***"; //Delimiter that separates song names and times
    char temp1[STR_LEN]; //Holds string temporarily for strtok function
    strcpy(temp1, str[i - 1]);
    strtok(temp1, delim);
    char *temp2 = strtok(NULL, delim);
    if (temp2 != NULL) { //Case that last line is a song: add an extra empty line
        strcpy(str[i], "");
        i++;
    } else { //If not ensure that the last line is empty then remove extra empty lines
        if (strcmp(str[i - 1], "") != 0) {
            strcpy(str[i - 1], "");
        }
        for (int j = i - 1; j >= 0; --j) { //Check to remove extra '\n' characters at the end of input
            if (strcmp(str[j], "") != 0) {
                i = j + 2;
                break;
            }
        }
    }

    if (i == STR_NUM) { //Lets user know array is full
        puts("Cannot take more input. ");
    }

    return i;
}

void sortByArtiste(char str[][STR_LEN], int n) {
    int order[n][2]; //Int array to hold indexes of string array, effectively recording the ordering according to artistes
    int start = 1, count = 0; //Count holds the number of artistes

    //Initialise order array with indexes of string array
    for (int i = 0; i < n; ++i) {
        if (start == 1) {
            order[count][0] = i;
            start = 0;
        }
        if (strcmp(str[i], "") == 0) {
            order[count][1] = i;
            count++;
            start = 1;
        }
    }

    //Perform insertion sort on string in blocks and records the new arrangement in order array for each artiste
    for (int i = 1; i < count; ++i) {
        int count2 = 0;
        shiftByArtiste(str, n, order, i);
        for (int j = 0; j < n; ++j) {
            if (start == 1) {
                order[count2][0] = j;
                start = 0;
            }
            if (strcmp(str[j], "") == 0) {
                order[count2][1] = j;
                count2++;
                start = 1;
            }
        }
    }
}

void sortBySong(char str[][STR_LEN], int n) {
    int order[n][2];
    int start = 1, count = 0;

    for (int i = 0; i < n; ++i) {
        if (start == 1) {
            order[count][0] = i;
            start = 0;
        }
        if (strcmp(str[i], "") == 0) {
            order[count][1] = i;
            count++;
            start = 1;
        }
    }

    //Perform insertion sort on songs for each artist
    for (int i = 0; i < count; ++i) {
        shiftBySong(str, i, order);
    }
}

int createPlaylist(char str[][STR_LEN], char playlist[][STR_LEN], int songNums[], int n) {
    int order[n][2];
    char allSongs[n][STR_LEN]; //Array of strings that contains only songs and no artiste names or empty lines
    int j = 0;
    int start = 1, count = 0;

    //Initialise order and allSongs at the same time
    for (int i = 0; i < n; ++i) {
        if (start == 1) {
            order[count][0] = j;
            start = 0;
        } else if (strcmp(str[i], "") == 0) {
            order[count][1] = j - 1;
            count++;
            start = 1;
        } else {
            strcpy(allSongs[j], str[i]);
            j++;
        }
    }

    int numOfSongs = j;
    int playlistSize = randomisePlaylist(playlist, allSongs, songNums, order, numOfSongs, count);

    return playlistSize;
}

void printPlaylist(char str[][STR_LEN], char playlist[][STR_LEN], const int songNums[], int n, int size) {
    if (size == 0) { //Lets user know if there arent enough songs
        puts("There are not enough songs to form a 1 hour playlist. ");
        return;
    } else if (size == -1) { //Lets user know a playlist couldn't be formed from the songs provided that meets all conditions
        puts("A 1 hour playlist that satisfies all conditions could not be generated. ");
        puts("Please try again. ");
        return;
    }

    int order[n][2];
    char songTimes[n][STR_LEN]; //Holds the strings of song times separated from song names
    char artisteNames[n][STR_LEN]; //Holds the artiste names
    char *token;
    const char delim[] = "***";
    int j = 0;
    int start = 1, count = 0;

    //Initialise order and artisteNames at the same time
    for (int i = 0; i < n; ++i) {
        if (start == 1) {
            strcpy(artisteNames[count], str[i]);
            order[count][0] = j;
            start = 0;
        } else if (strcmp(str[i], "") == 0) {
            order[count][1] = j - 1;
            count++;
            start = 1;
        } else {
            j++;
        }
    }

    //Prints out randomised playlist in specified format
    puts("Randomised playlist ");
    for (int i = 0; i < size; ++i) {
        for (int k = 0; k < count; ++k) {
            if ((songNums[i] >= order[k][0]) && (songNums[i] <= order[k][1])) { //Matches sng to artiste and prints artiste name
                printf("%s: ", artisteNames[k]);
            }
        }
        token = strtok(playlist[i], delim);
        printf("\"%s\" ", token); //Prints name of song
        token = strtok(NULL, delim);
        printf("(%s) \n", token); //Prints song time
        strcpy(songTimes[i], token);
    }

    //Calculate and print the total time
    int timesSec[size]; //Converts strings of song times to time in seconds
    strToTime(songTimes, timesSec, size);
    int totalTime = 0;
    for (int i = 0; i < size; ++i) {
        totalTime += timesSec[i];
    }
    int min, sec;
    min = totalTime / 60;
    sec = totalTime % 60;
    printf("Total duration: %d:%d. \n", min, sec);
}
