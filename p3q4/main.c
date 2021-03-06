//
// Created by FOLASADE on 19-Feb-21.
//
#include <stdio.h>
#include <time.h>

const char *NUM_FILE_PATH = "../inputFiles/sorted-10000.txt";

void quicksort(int arr[], int start, int end);
int partitionarray(int arr[], int start, int end);
void swap(int arr[], int i, int j);

int main()
{
    int n;
    int arr[100000];
    int i;
    clock_t start, end;
    double cpu_time_used;
    FILE *fp = fopen(NUM_FILE_PATH, "r");

    i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%d", &arr[i]);
        i++;
    }
    n = i - 1;

    printf("n is %d\n", n);

    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The time taken is %lfs\n", cpu_time_used);

}


void quicksort(int arr[], int start, int end)
{
    int pivotindex;

    if (start < end)
    {
        pivotindex = partitionarray(arr, start, end);

        quicksort(arr, start, pivotindex - 1);
        quicksort(arr, pivotindex + 1, end);
    }
}


int partitionarray(int arr[], int start, int end)
{
    int pivot;
    int i, j;

    pivot = arr[start];

    i = start + 1;
    j = end;
    while (i <= j)
    {
        if (arr[i] <= pivot)
            i++;
        else if (arr[j] > pivot)
            j--;
        else
        {
            swap(arr, i, j);
            i++;
            j--;
        }
    }

    swap(arr, start, j);

    return j;
}


void swap(int arr[], int i, int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

