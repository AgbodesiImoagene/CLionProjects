//
// Created by agbod on 5/15/2021.
//

#include "corrected_avg_and_max.h"

double adj_average(double array[], int size)
{
    double sum = 0;

    for (int i = 0;  i < size;  i++)
    {
        sum += array[i];
    }

    return sum/size;
}


double adj_max(double array[], int size)
{
    double max = array[0];

    for (int i = 1;  i < size;  i++)
    {
        if(max < array[i])
            max = array[i];
    }

    return max;
}
