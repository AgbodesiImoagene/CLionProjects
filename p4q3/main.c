#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_RESULTS 5
#define LINE_LENGTH 80
#define TEAM_LENGTH 30
#define RES_LENGTH 5


void readResults(char inputResults[][LINE_LENGTH]);
void sortResults(char inputResults[][LINE_LENGTH]);
void printResults(char inputResults[][LINE_LENGTH]);


int main()
{
    char inputResults[NUM_RESULTS][LINE_LENGTH];

    readResults(inputResults);
/*  Only need the next line when we have to sort the results...  */
/*
    sortResults(inputResults);
*/
    printResults(inputResults);

    return 0;
}

/*
This function requests NUM_RESULTS results from the keyboard
(one per line, according to the given input format)
and stores them in the array inputResults.
*/
void readResults(char inputResults[][LINE_LENGTH])
{
    int i = 0;
    int choice, choice2;
    printf("To input results from the keyboard enter 1, to have them read from a file enter 2: ");
    scanf("%d", &choice);
    while ((choice != 1) && (choice != 2))
    {
        printf("Enter a 1 or a 2: ");
        scanf("%d", &choice);
    }
    if (choice == 1)
    {
        printf("Enter %d results, please, one per line:\n", NUM_RESULTS);
        for (i = 0;  i < NUM_RESULTS;  i++)
        {
            printf("Enter result %d: ", i + 1);

/*  Use fgets to read a line from the standard input (stdin)  */
            fgets(inputResults[i], LINE_LENGTH, stdin);

/*  Don't forget to strip the newline from the end of the line!  */
            if (inputResults[i][strlen(inputResults[i]) - 1] == '\n')
                inputResults[i][strlen(inputResults[i]) - 1] = '\0';

        }
    } else {
        printf("To input results from the gaa-results.txt enter 1, to have them read from soccer-results.txt enter 2: ");
        scanf("%d", &choice2);
        while ((choice2 != 1) && (choice2 != 2))
        {
            printf("Enter a 1 or a 2: ");
            scanf("%d", &choice2);
        }
        FILE *fp;
        if (choice2 == 1)
        {
            fp = fopen("../inputFiles/gaa-results.txt", "r");
            while ((!feof(fp)) && (i < NUM_RESULTS))
            {
                fgets(inputResults[i], LINE_LENGTH, fp);
                if (inputResults[i][strlen(inputResults[i]) - 1] == '\n')
                {
                    inputResults[i][strlen(inputResults[i]) - 1] = '\0';
                }
                i++;
            }
        } else {
            fp = fopen("../inputFiles/soccer-results.txt", "r");
            while ((!feof(fp)) && (i < NUM_RESULTS))
            {
                fgets(inputResults[i], LINE_LENGTH, fp);
                if (inputResults[i][strlen(inputResults[i]) - 1] == '\n')
                {
                    inputResults[i][strlen(inputResults[i]) - 1] = '\0';
                }
                i++;
            }
        }
    }


    return;
}

/*
This function sorts out NUM_RESULTS results in the array inputResults
using the Insertion Sort algorithm.
*/
void sortResults(char inputResults[][LINE_LENGTH])
{
    int i, j;
    char swap[LINE_LENGTH];

    for (i = 1; i < NUM_RESULTS; i++)
    {
        j = i;
        while (j > 0 && strcmp(inputResults[j], inputResults[j - 1]) < 0)
        {
            strcpy(swap, inputResults[j]);
            strcpy(inputResults[j], inputResults[j - 1]);
            strcpy(inputResults[j - 1], swap);
            j--;
        }
    }
    return;
}

/*
This function prints out NUM_RESULTS results in the array inputResults
and prints them out according to the given output format.
*/
void printResults(char inputResults[][LINE_LENGTH])
{
    const char delim[] = "++";
    char homeTeamName[TEAM_LENGTH], awayTeamName[TEAM_LENGTH];
    char homeTeamScore[RES_LENGTH], awayTeamScore[RES_LENGTH];

    int i;
    int linelen;
    char *token;

    printf("The list of ordered results is as follows:\n");
    for (i = 0;  i < NUM_RESULTS;  i++)
    {
/*  Extract the first token (home team name)  */
        token = strtok(inputResults[i], delim);
        strcpy(homeTeamName, token);

/*  Extract the next token (home team score)  */
        token = strtok(NULL, delim);
        strcpy(homeTeamScore, token);

/*  Extract the next token (away team name)  */
        token = strtok(NULL, delim);
        strcpy(awayTeamName, token);

/*  Extract the next token (away team score)  */
        token = strtok(NULL, delim);
        strcpy(awayTeamScore, token);

/*  Now print them out according to the given format  */
        printf("%s-%s %s:%s\n", homeTeamName, awayTeamName, homeTeamScore, awayTeamScore);
    }

    return;
}
