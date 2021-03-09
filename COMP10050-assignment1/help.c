//
// Created by Agbodesi Imoagene on 2/22/2021.
//

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "help.h"

void shiftByArtiste(char str[][STR_LEN], int n, int ind[][2], int iterator) {
    char buffer[n][STR_LEN]; //Holds name and songs of artiste to be inserted
    int bufferSize;
    if (strcmp(str[ind[iterator][0]], str[ind[iterator - 1][0]]) < 0) { //Case that artiste name is lower alphabetically than previous one
        copy2Dstrings(buffer, str, 0, ind[iterator][0], ind[iterator][1] - ind[iterator][0] + 1); //Copy block into buffer
        bufferSize = ind[iterator][1] - ind[iterator][0] + 1; //Initialise buffer size

        //Shift strings above down by 'bufferSize' indexes, effectively overwriting the block for the artiste to be inserted
        int j = iterator;
        while ((j > 0) && (strcmp(buffer[0], str[ind[j - 1][0]]) < 0)) { //Check for artiste's sorted position alphabetically
            for (int k = 0; k <= (ind[j - 1][1] - ind[j - 1][0]); k++) {
                strcpy(str[ind[j - 1][1] + bufferSize - k], str[ind[j - 1][1] - k]);
            }
            j--;
        }

        copy2Dstrings(str, buffer, ind[j][0], 0, bufferSize); //Copies block for artiste back into new position in array
    }
}

void shiftBySong(char str[][STR_LEN], int i, int ind[][2]) {
    char buffer[STR_LEN]; //Holds song to be inserted
    int start, stop;
    start = ind[i][0] + 1, stop = ind[i][1];
    for (int j = start + 1; j < stop; j++) {
        if (strcmp(str[j], str[j - 1]) < 0) { //Case that song is alphabetically lower than previous song
            strcpy(buffer, str[j]); //Initialise buffer with song
            int k = j;

            //Shift all songs above down 1 index until new position of song is located
            while ((k > start) && (strcmp(buffer, str[k - 1]) < 0)) { //Check for new position of song
                strcpy(str[k], str[k - 1]);
                k--;
            }
            strcpy(str[k], buffer); //Copy song back into array
        }
    }
}

void copy2Dstrings(char str1[][STR_LEN], char str2[][STR_LEN], int ind1, int ind2, int n) {
    for (int i = 0; i < n; ++i) { //Copy a block of strings
        strcpy(str1[ind1 + i], str2[ind2 + i]);
    }
}

int randomisePlaylist(char playlist[][STR_LEN], char temp[][STR_LEN], int songNums[], int order[][2], int n, int count) {
    srand(time(NULL)); //Seed rand function with time
    char songTimes[n][STR_LEN]; //Holds the song times
    char copy[STR_LEN]; //Songs are held here temporarily for strtok function
    const char delim[] = "***"; //Delimiter that separates song names and times
    char *token;

    //Initialise songTimes
    for (int i = 0; i < n; ++i) {
        strcpy(copy, temp[i]);
        strtok(copy, delim);
        token = strtok(NULL, delim);
        strcpy(songTimes[i], token);
    }

    //Convert time to int seconds and calculate the total time
    int timesSec[n];
    strToTime(songTimes, timesSec, n);
    int totalTime = 0;
    for (int i = 0; i < n; ++i) {
        totalTime += timesSec[i];
    }
    if (totalTime < 3600) { //Case that there are not enough songs to form a 1 hour playlist
        return 0;
    }

    totalTime = 0;
    int playlistSize = 0; //Holds number of songs in playlist
    int artistePlays[count]; //Holds number of songs each artiste has in playlist
    for (int i = 0; i < count; ++i) {
        artistePlays[i] = 0;
    }
    int change = 0; //Ensures playlist generator does not get stuck in an infinite loop
    int prevPrev = -1, prev = -1, curr = -1; //Variables to enable check that three songs from the same artiste dont play in a row

    while ((totalTime < 3600) && (change < n)) { //Check that playlist does not exceed 1 hour and new song can be added to playlist
        int j = rand() % n; //Generates random number j to correspond to a random song
        int rep = 0; //Holds result of check for potential repetitions of a song
        //Check to make sure if no random 1 hour playlist can be created, loop ends
        change++;
        //Check that three songs don't play from the same artist in a row
        for (int i = 0; i < count; ++i) {
            if ((j >= order[i][0]) && (j <= order[i][1])) { //Sets curr with the artiste index
                curr = i;
                break;
            }
        }
        if ((prevPrev == prev) && (prev == curr)) {
            continue; //Choose another random number
        }
        //Check that not more than 3 songs from the same artist appear in the playlist
        if (artistePlays[curr] >= 3) {
            continue;
        }
        //Check for repetitions of songs in the playlist
        for (int i = 0; i < playlistSize; ++i) {
            if (j == songNums[i]) {
                rep = 1;
                break;
            }
        }
        if (rep == 1) {
            continue;
        }

        //When all conditions are met
        strcpy(playlist[playlistSize], temp[j]); //Add song to playlist
        songNums[playlistSize] = j; //Add song index to songNums
        totalTime += timesSec[j]; //Add song time to total time
        playlistSize++; //Increment the size of the playlist
        prevPrev = prev; //Shift the values of prevPrev and prev
        prev = curr;
        artistePlays[curr]++; //Increment the number of the artiste's songs in the playlist
        change = 0; //Reset change to show a new song has been added to the playlist
    }
    if (change == n) { //Case that a 1 hour playlist cannot be generated
        return -1;
    } else {
        return playlistSize;
    }
}

void strToTime(char str[][STR_LEN], int times[], int n) {
    const char delim[] = ":"; //Delimiter that separates minutes from seconds in time
    char *token; //Holds minutes and seconds as strings
    int min, sec; //Variables to hold time as integers

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

    while (str[i] != '\0') { //Converts string to int
        num = (num * 10) + (str[i] - '0');
        i++;
    }

    return num;
}
