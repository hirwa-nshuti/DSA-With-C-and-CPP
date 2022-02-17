/*
Reversing and Rotating an Array
*/

#include <stdio.h>
#include <stdlib.h>
#include "Arrayadt.h"

// Reversing an Array
void Reverse(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        Swap(&arr->Arr[i], &arr->Arr[j]);
    }
}

// Left Rotation
void LeftRotate(struct Array *arr, int rotations)
{
    int i;
    while (rotations--)
    {
        int temp = arr->Arr[0];
        for (i = 0; i < arr->length - 1; i++)
        {
            arr->Arr[i] = arr->Arr[i + 1];
        }
        arr->Arr[arr->length - 1] = temp;
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
    // Left Rotating an array by 2
    LeftRotate(&arr, 2);
    printf("\nAfter two rotations we get:\n");
    Display(&arr);

    // Reversing
    printf("\nRevesring our array:\n");
    Reverse(&arr);
    Display(&arr);

    free(arr.Arr);
    return 0;
}