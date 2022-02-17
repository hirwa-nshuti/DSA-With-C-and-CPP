/*
Considering an array as set of elements and implement the set operation:
- Intersection
- Union
- Difference

*/

#include <stdio.h>
#include <stdlib.h>
#include "Arrayadt.h"

// Sets Intersection
struct Array *Intersection(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->Arr[i] < arr2->Arr[j])
            i++;
        else if(arr2->Arr[j] < arr1->Arr[i])
            j++;
        else if(arr1->Arr[i] == arr2->Arr[j])
        {
            arr3->Arr[k++] = arr1->Arr[i++];
            j++;
        }
    }
    arr3->size = arr1->size + arr2->size;
    arr3->length = k;
    return arr3;
}


// Set Union
struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->Arr[i] < arr2->Arr[j])
            arr3->Arr[k++] = arr1->Arr[i++];
        else if(arr2->Arr[j] < arr1->Arr[i])
            arr3->Arr[k++] = arr2->Arr[j++];
        else
        {
            arr3->Arr[k++] = arr1->Arr[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->Arr[k++] = arr1->Arr[i++];
    for (; j < arr2->length; j++)
        arr3->Arr[k++] = arr2->Arr[j++];
    
    arr3->size = arr1->size + arr2->size;
    arr3->length = k;
    return arr3;
}

int main()
{
    int i;
    struct Array arr, arr2, *arr3;
    printf("Enter size of first array: ");
    scanf("%d", &arr.size);
    arr.Arr = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter number of element for first Array: ");
    scanf("%d", &arr.length);
    printf("Enter all Elements\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr.Arr[i]);
    }

    printf("First array\n");
    Display(&arr);

    printf("\nEnter size of second array: ");
    scanf("%d", &arr2.size);
    arr2.Arr = (int *)malloc(arr2.size * sizeof(int));
    printf("Enter the number of in the second elements: ");
    scanf("%d", &arr2.length);
    printf("Enter all Elements in the Second Array\n");
    for (i = 0; i < arr2.length; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr2.Arr[i]);
    }
    printf("The second array is:\n");
    Display(&arr2);
    arr3 = Union(&arr, &arr2);
    printf("\nAfter Union\n");
    Display(arr3);
    free(arr3);
    free(arr.Arr);
    free(arr2.Arr);
    return 0;
}