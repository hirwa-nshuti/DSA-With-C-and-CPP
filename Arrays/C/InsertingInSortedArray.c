/*
Inserting Elements in a sorted array
*/

#include <stdio.h>
#include <stdlib.h>
#include "Arrayadt.h"

// Inserting in a Sorted Array
void InsertSorted(struct Array *arr, int val)
{
    int i = arr->length - 1;
    if (IsSorted(arr))
    {
        while (val < arr->Arr[i])
        {
            arr->Arr[i + 1] = arr->Arr[i];
            i--;
        }

        arr->Arr[i + 1] = val;
        arr->length++;
    }
}

int main()
{
    int n, i;
    struct Array arr;
    printf("Enter size of array: ");
    scanf("%d", &arr.size);
    arr.Arr = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter number of element: ");
    scanf("%d", &n);
    printf("Enter all Sorted Elements\n");
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr.Arr[i]);
    }

    arr.length = n;
    printf("Before any operation to the array\n");
    Display(&arr);

    printf("\nInserting 17 in the array\n");
    InsertSorted(&arr, 17);
    Display(&arr);

    free(arr.Arr);
    return 0;
}