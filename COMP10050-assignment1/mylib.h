//
// Created by Agbodesi Imoagene on 2/22/2021.
//

#ifndef COMP10050_ASSIGNMENT1_MYLIB_H
#define COMP10050_ASSIGNMENT1_MYLIB_H
#define STR_LEN 100

int fileInput(char file[], char str[][STR_LEN], int arraySize);
/*
 * Stores data from file in char array
 */

int keyboardInput(char str[][STR_LEN], int arraySize);
/*
 * Stores data from keyboard in char array
 */

void sortByArtiste(char str[][STR_LEN], int n);
/*
 * Sorts array by artiste names in alphabetical order
 */

void sortBySong(char str[][STR_LEN], int n);
/*
 * Sorts array by song names in alphabetical order
 */

int createPlaylist(char str[][STR_LEN], char playlist[][STR_LEN], int songNums[], int n);
/*
 * Creates randomised playlist
 */

void printPlaylist(char str[][STR_LEN], char playlist[][STR_LEN], const int songNums[], int n, int size);
/*
 * Prints playlist
 */
#endif //COMP10050_ASSIGNMENT1_MYLIB_H
