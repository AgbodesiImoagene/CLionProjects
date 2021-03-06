#include <stdio.h>
// Remember to MODIFY the location of weather file in YOUR COMPUTER
const char *WEATHER_FILE_PATH = "../inputFiles/weather.txt";
char weatherArr[5][70]; // stores weather data (limited to five rows)
int lineNum;
int i;
int main ()
{
    FILE *fp = fopen(WEATHER_FILE_PATH, "r+" ); /* open for reading */
// This will take each row in the file and store it in weatherArr.
    if (fp == NULL ){ /* check does weather file exist etc */
        perror ("Error opening weather file");
        lineNum = -1; /* use this as a file not found code */
    } else {
// fgets returns NULL when it gets to the end of the file
        while ( fgets( weatherArr[lineNum], sizeof(weatherArr[lineNum]), fp ) != NULL ) {
            lineNum++;
        }
        fclose (fp);
    }
// Print out the lines that were read from the file
    for(i =0; i < lineNum; i ++)
    {
        printf("\n%s\n", weatherArr[i]);
    }
}