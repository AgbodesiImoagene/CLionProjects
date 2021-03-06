//
// Created by Agbodesi Imoagene on 2/22/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "mylib.h"

void swapByArtiste(char str[][STR_LEN], int n, int ind[][2], int iterator);
void swapBySong(char str[][STR_LEN], int i, int ind[][2]);
void copy2Dstrings(char str1[][STR_LEN], char str2[][STR_LEN], int ind1, int ind2, int n);
int randomisePlaylist(char playlist[][STR_LEN], char temp[][STR_LEN], int songNums[], int order[][2], int n, int count);
void strToTime(char str[][STR_LEN], int times[], int n);
int strToNum(const char str[]);

int fileInput(char file[], char str[][STR_LEN], int arraySize) {
    int i = 0;
    FILE *fp;
    fp = fopen(file, "r");
    while ((!feof(fp)) && (i < arraySize)) {
        fgets(str[i], STR_LEN, fp);
        if (str[i][strlen(str[i]) - 1] == '\n') {
            str[i][strlen(str[i]) - 1] = '\0';
        }
        i++;
    }
    if (strcmp(str[i - 1], "") != 0) {
        strcpy(str[i - 1], "");
    }


    if (i == arraySize) {
        puts("Cannot take more input. ");
    }

    return i;
}

int keyboardInput(char str[][STR_LEN], int arraySize) {
    puts("Enter EOF(ctrl+z on windows, ctrl+d on unix) on a new line to end input stream. ");
    puts("EOF character might not be fully functional if program is run in CLion. ");
    puts("Enter input: ");
    int i = 0;
    while ((!feof(stdin)) && (i < arraySize - 1)) {
        fgets(str[i], STR_LEN, stdin);
        if (str[i][strlen(str[i]) - 1] == '\n') {
            str[i][strlen(str[i]) - 1] = '\0';
        }
        i++;
    }
    if (strcmp(str[i - 1], "") != 0) {
        strcpy(str[i - 1], "");
    }

    if (i == arraySize) {
        puts("Cannot take more input. ");
    }

    return i;
}

void copy2Dstrings(char str1[][STR_LEN], char str2[][STR_LEN], int ind1, int ind2, int n) {
    for (int i = 0; i < n; ++i) {
        strcpy(str1[ind1 + i], str2[ind2 + i]);
    }
}

void sortByArtiste(char str[][STR_LEN], int n) {
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

    for (int i = 1; i < count; ++i) {
        int count2 = 0;
        swapByArtiste(str, n, order, i);
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

void swapByArtiste(char str[][STR_LEN], int n, int ind[][2], int iterator) {
    char buffer[n][STR_LEN];
    int bufferSize;
    if (strcmp(str[ind[iterator][0]], str[ind[iterator - 1][0]]) < 0) {
        copy2Dstrings(buffer, str, 0, ind[iterator][0], ind[iterator][1] - ind[iterator][0] + 1);
        bufferSize = ind[iterator][1] - ind[iterator][0] + 1;

        int j = iterator;
        while ((j > 0) && (strcmp(buffer[0], str[ind[j - 1][0]]) < 0)) {
            for (int k = 0; k <= (ind[j - 1][1] - ind[j - 1][0]); k++) {
                strcpy(str[ind[j - 1][1] + bufferSize - k], str[ind[j - 1][1] - k]);
            }
            j--;
        }

        copy2Dstrings(str, buffer, ind[j][0], 0, bufferSize);
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
    for (int i = 0; i < count; ++i) {
        swapBySong(str, i, order);
    }
}

void swapBySong(char str[][STR_LEN], int i, int ind[][2]) {
    char buffer[STR_LEN];
    int start, stop;
    start = ind[i][0] + 1, stop = ind[i][1];
    for (int j = start + 1; j < stop; j++) {
        if (strcmp(str[j], str[j - 1]) < 0) {
            strcpy(buffer, str[j]);
            int k = j;
            while ((k > start) && (strcmp(buffer, str[k - 1]) < 0)) {
                strcpy(str[k], str[k - 1]);
                k--;
            }
            strcpy(str[k], buffer);
        }
    }
}

int createPlaylist(char str[][STR_LEN], char playlist[][STR_LEN], int songNums[], int n) {
    int order[n][2];
    char allSongs[n][STR_LEN];
    int j = 0;
    int start = 1, count = 0;
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

int randomisePlaylist(char playlist[][STR_LEN], char temp[][STR_LEN], int songNums[], int order[][2], int n, int count) {
    srand(time(NULL));
    char songTimes[n][STR_LEN];
    char copy[STR_LEN];
    const char delim[] = "***";
    char *token;
    for (int i = 0; i < n; ++i) {
        strcpy(copy, temp[i]);
        token = strtok(copy, delim);
        token = strtok(NULL, delim);
        strcpy(songTimes[i], token);
    }

    int timesSec[n];
    strToTime(songTimes, timesSec, n);

    int totalTime = 0;
    for (int i = 0; i < n; ++i) {
        totalTime += timesSec[i];
    }
    if (totalTime < 3600) {
        return 0;
    }

    totalTime = 0;
    int playlistSize = 0;
    int artistePlays[count];
    for (int i = 0; i < count; ++i) {
        artistePlays[i] = 0;
    }
    int change = 0;
    int prevPrev = -1, prev = -1, curr = -1;
    while ((totalTime < 3600) && (change < n)) {
        int j = rand() % n;
        int rep = 0;
        //Check to make sure if no random 1 hour playlist can be created, loop ends
        change++;
        //Check that three songs don't play from the same artist in a row
        for (int i = 0; i < count; ++i) {
            if ((j >= order[i][0]) && (j <= order[i][1])) {
                curr = i;
                break;
            }
        }
        if ((prevPrev == prev) && (prev == curr)) {
            continue;
        }
        //Check that not more than 3 songs from the same artist appear in the playlist
        if (artistePlays[curr] >= 3) {
            continue;
        }
        //Check for repititions of songs in the playlist
        for (int i = 0; i < playlistSize; ++i) {
            if (j == songNums[i]) {
                rep = 1;
                break;
            }
        }
        if (rep == 1) {
            continue;
        }

        strcpy(playlist[playlistSize], temp[j]);
        songNums[playlistSize] = j;
        totalTime += timesSec[j];
        playlistSize++;
        prevPrev = prev;
        prev = curr;
        artistePlays[curr]++;
        change = 0;
    }
    return playlistSize;
}

void printPlaylist(char str[][STR_LEN], char playlist[][STR_LEN], const int songNums[], int n, int size) {

    if (size == 0) {
        puts("There are not enough songs to form a 1 hour playlist. ");
        return;
    }
    int order[n][2];
    char songTimes[n][STR_LEN];
    char artisteNames[n][STR_LEN];
    char *token;
    const char delim[] = "***";
    int j = 0;
    int start = 1, count = 0;
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


    puts("Randomised playlist ");
    for (int i = 0; i < size; ++i) {
        for (int k = 0; k < count; ++k) {
            if ((songNums[i] >= order[k][0]) && (songNums[i] <= order[k][1])) {
                printf("%s: ", artisteNames[k]);
            }
        }
        token = strtok(playlist[i], delim);
        printf("\"%s\" ", token);
        token = strtok(NULL, delim);
        printf("(%s) \n", token);
        strcpy(songTimes[i], token);

    }


    int timesSec[size];
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

void strToTime(char str[][STR_LEN], int times[], int n) {
    const char delim[] = ":";
    char *token;
    int min, sec;
    for (int i = 0; i < n; ++i) {
        token = strtok(str[i], delim);
        min = strToNum(token);
        token = strtok(NULL, delim);
        sec = strToNum(token);
        times[i] = (min * 60) + sec;
    }
}

int strToNum(const char str[]) {
    int i = 0;
    int num = 0;
    while (str[i] != '\0') {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    return num;
}
