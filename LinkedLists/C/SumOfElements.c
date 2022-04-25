#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    int *Arr = (int *)malloc(5 * sizeof(int));
    Arr[0] = 3;
    Arr[1] = 4;
    Arr[2] = 8;
    Arr[3] = 9;
    Arr[4] = 19;
    CreateLL(Arr, 5);
    DisplayLL(first);
    return 0;
}