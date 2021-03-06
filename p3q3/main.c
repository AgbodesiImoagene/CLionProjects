//
// Created by FOLASADE on 19-Feb-21.
//
#include <stdio.h>
#include <time.h>

const char *NUM_FILE_PATH = "../inputFiles/rand-100000.txt";

int main()
{
    int n;
    int array[100000];
    int i, j;
    int temp;
    clock_t start, end;
    double cpu_time_used;
    FILE *fp = fopen(NUM_FILE_PATH, "r");

    i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%d", &array[i]);
        i++;
    }
    n = i - 1;

    printf("n is %d\n", n);

    start = clock();
    for (i = 1; i < n; i++)
    {
        if (array[i] < array[i - 1])
        {
            temp = array[i];
            j = i;
            while (j > 0 && temp < array[j - 1])
            {
                array[j] = array[j - 1];
                j--;
            }
            array[j] = temp;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The time taken is %lfs\n", cpu_time_used);

    return 0;
}

