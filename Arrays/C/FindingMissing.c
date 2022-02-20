/*
Finding the missing value in a Sorted array
*/
#include <stdio.h>
#include <stdlib.h>
#include "Arrayadt.h"

// When an array is of n natural numbers sequence
int findMissing(struct Array *arr)
{
    int i, s, sum = 0;
    for (i = 0; i < arr->length; i++)
    {
        sum += arr->Arr[i];
    }
    s = arr->Arr[arr->length - 1] * (arr->Arr[arr->length - 1] + 1) / 2;

    return s - sum;
}

// When we have some starting number and ending Number.
int FindMissStart(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        if ((arr->Arr[i] - i) != arr->Arr[0])
            return arr->Arr[0] + i;
    }
}

void FindingMultiple(struct Array *arr)
{
    int diff, i;
    diff = arr->Arr[0];
    for (i = 0; i < arr->length; i++)
    {
        if ((arr->Arr[i] - 1) != diff)
        {
            while (diff < arr->Arr[i] - i)
            {
                printf("%d\n", i + diff);
                diff++;
            }
        }
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
    // Finding the missing when sequence is from 0
    printf("\nThe missing element is : %d", findMissing(&arr));
    // Finding the missing when sequence is from a certain number
    printf("\nMissing element is : %d", FindMissStart(&arr));
    // Finding multiple missing elements
    FindingMultiple(&arr);
    free(arr.Arr);
    return 0;
}