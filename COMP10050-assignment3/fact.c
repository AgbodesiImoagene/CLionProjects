#include "fact.h"


long factorial(int size)
/*  This function assumes that the argument is non-negative, ie >= 0.  */
{
    int i;
    long fact;

    fact = 1;

    for (i = 1;  i <= size;  i++)
    {
        fact *= i;
    }

    return fact;    
}
