#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fydkShuffle1(int arr[], int size);
void printArr(int arr[], int size);


int main()
{
    int arr[30];

    int i;
    int size;

    size = 30;

/*  Initialise the array.  */
    for (i = 0;  i < size;  i++)
        arr[i] = i;

    srand(time(NULL));  /*  srand() should only be called once!  */

    printf("Array before shuffling:\n");
    printArr(arr, size);

    fydkShuffle1(arr, size);


    printf("Array after shuffling:\n");
    printArr(arr, size);

    return 0;
}


/*
Shuffle an array of ints using the Fisher-Yates Durstenfeld Knuth Shuffle algorithm.
*/
void fydkShuffle1(int arr[], int size) {

    int temp[size];
    int i, j;

    for (i = 0; i < size; ++i) {
        j = rand() % (i + 1);
        if (j != i) {
            temp[i] = temp[j];
        }
        temp[j] = arr[i];
    }
    for (i = 0; i < size; ++i) {
        arr[i] = temp[i];
    }

}


/*
Print out an array of ints of size size.
*/
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    puts("");
}
