#include <stdio.h>
#include <stdbool.h>

#ifndef ARRAYADT
#define ARRAYADT

struct Array
{
    int *Arr;
    int size;
    int length;
};

void Display(struct Array *arr)
{
    int i;
    printf("Elements of array are:\n");
    for (i = 0; i < arr->length; i++)
    {
        printf("%d ", arr->Arr[i]);
    }
}

// Swapping
void Swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

// Cheching if Array is Sorted
bool IsSorted(struct Array *arr)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (arr->Arr[i] > arr->Arr[i + 1])
            return false;
    }
    return true;
}

#endif