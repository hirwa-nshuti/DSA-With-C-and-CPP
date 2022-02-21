/*
Using Get, Set methods and implementing methods to find maximum and minimum
*/

#include <stdio.h>
#include <stdlib.h>
#include "Arrayadt.h"

// Getting a variable at a given index
int Get(struct Array *arr, int index)
{
    if (index <= arr->length && index >= 0)
        return arr->Arr[index];
    return 0;
}

// Setting a variable at Index to a given value
void Set(struct Array *arr, int index, int val)
{
    if (index <= arr->length && index >= 0)
        arr->Arr[index] = val;
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

    // Getting element at 2nd index
    printf("\nThe element at 2nd index is : %d", Get(&arr, 2));

    // Setting element at 3rd index to 50
    Set(&arr, 3, 50);
    printf("\nAfter setting 3rd index element to 50 our array is: \n");
    Display(&arr);

    // Finding maximum and minimum
    printf("\nMaximum = %d and minimum = %d\n", Max(&arr), Min(&arr));
    free(arr.Arr);
    return 0;
}