/*
Implementing Insertion Deletion and appending elements to array
*/

#include <stdio.h>
#include <stdlib.h>
#include "Arrayadt.h"

// Appending
void Append(struct Array *arr, int num)
{
    if (arr->length < arr->size)
        arr->Arr[arr->length++] = num;
}
// Deleting
void Delete(struct Array *arr, int index)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = index; i < arr->length - 1; i++)
            arr->Arr[i] = arr->Arr[i + 1];
        arr->length--;
    }
}

// Inserting
void Insert(struct Array *arr, int index, int num)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->Arr[i] = arr->Arr[i - 1];
        arr->Arr[index] = num;
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
    printf("Enter all Elements\n");
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr.Arr[i]);
    }

    arr.length = n;
    printf("Before any operation to the array\n");
    Display(&arr);
    // Appending
    Append(&arr, 10);
    printf("\nAfter appending 10 our array became:\n");
    Display(&arr);

    // Deleting
    printf("\nDeleting item at index 3 from the array\n");
    Delete(&arr, 3);
    Display(&arr);
    // inserting
    Insert(&arr, 3, 12);
    printf("\nInserting 12 and index 3 array became:\n");
    Display(&arr);
    free(arr.Arr);
    return 0;
}