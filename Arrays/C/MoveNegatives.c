/*
Moving Negative numbers to left and positives to right
*/

/*
Inserting Elements in a sorted array
*/

#include <stdio.h>
#include <stdlib.h>
#include "Arrayadt.h"

// Moving Negative Values to left and Positive to the right
void MoveNegative(struct Array *arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while (arr->Arr[i] < 0)
            i++;
        while (arr->Arr[j] > 0)
            j--;

        if (i < j)
            Swap(&arr->Arr[i], &arr->Arr[j]);
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
    printf("Enter all Elements\n");
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr.Arr[i]);
    }

    arr.length = n;
    printf("Before any operation to the array\n");
    Display(&arr);

    printf("\nMoving Negatives to left\n");
    MoveNegative(&arr);
    Display(&arr);

    free(arr.Arr);
    return 0;
}