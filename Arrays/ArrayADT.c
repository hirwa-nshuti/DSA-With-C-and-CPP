/*
Implementing array ADT
*/

#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *Arr;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("Elements of array are:\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.Arr[i]);
    }
}

// Appending
void Append(struct Array *arr, int num)
{
    if (arr->length < arr->size)
        arr->Arr[arr->length++] = num;
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

// Item Deletion
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
    Append(&arr, 10);
    // inserting
    Insert(&arr, 5, 11);

    // Delete at index 0
    Delete(&arr, 0);
    Display(arr);

    free(arr.Arr);
    return 0;
}