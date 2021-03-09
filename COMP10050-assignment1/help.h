//
// Created by Agbodesi Imoagene on 2/22/2021.
// Helper functions for mylib.c
//

#ifndef COMP10050_ASSIGNMENT1_HELP_H
#define COMP10050_ASSIGNMENT1_HELP_H
#define STR_LEN 100

void shiftByArtiste(char str[][STR_LEN], int n, int ind[][2], int iterator);
/*
 * Shifts all the songs by an artiste to arrange artists alphabetically
 */

void shiftBySong(char str[][STR_LEN], int i, int ind[][2]);
/*
 * Shifts individual songs by an artiste to arrange them alphabetically
 */

void copy2Dstrings(char str1[][STR_LEN], char str2[][STR_LEN], int ind1, int ind2, int n);
/*
 * Copies a block of strings from one array to another
 */

int randomisePlaylist(char playlist[][STR_LEN], char temp[][STR_LEN], int songNums[], int order[][2], int n, int count);
/*
 * Generates random playlist while respecting constraints
 */

void strToTime(char str[][STR_LEN], int times[], int n);
/*
 * Converts strings to numbers and then to seconds
 */

int strToNum(const char str[]);
/*
 * Converts strings to numbers
 */
#endif //COMP10050_ASSIGNMENT1_HELP_H
