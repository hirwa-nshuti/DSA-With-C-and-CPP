/*
Performing Binary and Linear Search to our array
*/

#include <stdio.h>
#include <stdlib.h>
#include "Arrayadt.h"

// Performing Linear Search on Array
int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (arr->Arr[i] == key)
            return i;
    }
    return -1;
}

// Performing Binary Search
int BinarySearch(struct Array *arr, int key)
{
    int low = 0;
    int high = arr->length;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr->Arr[mid] == key)
            return mid;
        else if (arr->Arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
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

    // Linear Search
    printf("\nUsing linear Search to search 4\n");
    printf("Element 4 is at index %d", LinearSearch(&arr, 4));

    // Binary Search
    printf("\nUsing Binary Search to look for 0\n");
    printf("Element 4 is at index %d", BinarySearch(&arr, 0));

    free(arr.Arr);
    return 0;
}