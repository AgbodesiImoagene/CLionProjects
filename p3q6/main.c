#include <stdio.h>
#define STR_SIZE 200

int main() {
    char str[STR_SIZE][50];
    int i = 0;
    FILE *fp;
    fp = fopen("../inputFiles/indie-1990s-2000s.txt", "r");
    while ((!feof(fp)) && (i < STR_SIZE))
    {
        fgets(str[i], 30, fp);
        for (int j = 0; j < 50; ++j) {
            if (str[i][j] == '\n')
            {
                str[i][j] = '\0';
                break;
            }
        }
        i++;
    }
    if (i == STR_SIZE)
    {
        puts("Cannot take more input. ");
    }
    for (int j = 0; j < i; ++j)
    {
        puts(str[j]);
    }

    return 0;
}
