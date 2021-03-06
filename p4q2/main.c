#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "Today's practical is about splitting******strings using the ***strtok*** function.";
    const char delim[] = "***";

    char copy[100];

    char *token;

/*  First of all, we will split the string based on the space character.  */
    printf("Splitting the string based on the space character:\n");

    strcpy(copy, string);  //  What happens if you don't make a copy of the original string and try to work on it again later?

/*  Extract the first token...  */
    token = strtok(copy, " ");

/*  Now loop through the string to extract all the other tokens...  */
    while (token != NULL)
    {
/*  Print a token...  */
        printf("%s\n", token);  //  Printing each token

/*  ... and get the next one.  */
        token = strtok(NULL, " ");
    }


/*  Now we will split the string based on the substring containing three asterisks.  */
    printf("Splitting the string based on the substring containing three asterisks (%s):\n", delim);

    strcpy(copy, string);  //  What happens if you don't re-initialise copy with the original string?

/*  Extract the first token...  */
    token = strtok(copy, delim);

/*  Now loop through the string to extract all the other tokens...  */
    while (token != NULL)
    {
/*  Print a token...  */
        printf("%s\n", token);  //  Printing each token

/*  ... and get the next one.  */
        token = strtok(NULL, delim);
    }

    return 0;
}
