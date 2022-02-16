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

void Display(struct Array *arr)
{
    int i;
    printf("Elements of array are:\n");
    for (i = 0; i < arr->length; i++)
    {
        printf("%d ", arr->Arr[i]);
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

// Finding Maximum in array
int Max(struct Array *arr)
{
    int i, max = arr->Arr[0];
    for (i = 1; i < arr->length; i++)
    {
        if (max < arr->Arr[i])
            max = arr->Arr[i];
    }

    return max;
}

// Finding minimum in array

int Min(struct Array *arr)
{
    int i, min = arr->Arr[0];
    for (i = 1; i < arr->length; i++)
    {
        if (min > arr->Arr[i])
            min = arr->Arr[i];
    }

    return min;
}

// Reversing an Array
void Reverse(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        arr->Arr[i] = arr->Arr[i] + arr->Arr[j];
        arr->Arr[j] = arr->Arr[i] - arr->Arr[j];
        arr->Arr[i] = arr->Arr[i] - arr->Arr[j];
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
    Append(&arr, 10);
    // inserting
    Insert(&arr, 5, 12);

    // Delete at index 0
    Delete(&arr, 0);

    // Set Method
    Set(&arr, 2, 34);
    Display(&arr);
    // Linear Search
    printf("\nPerforming the linear Search:\n");
    int index = LinearSearch(&arr, 10);
    if (index == -1)
        printf("element not found\n");
    else
        printf("element found at %d", index);
    // Binary Search
    printf("\nPerforming the Binary Search:\n");
    index = BinarySearch(&arr, 11);
    if (index == -1)
        printf("element not found\n");
    else
        printf("element found at %d", index);

    // Using Get method
    int found = Get(&arr, 4);
    printf("\nElement at index 4 is %d", found);

    printf("\nThe minimum element of the array is %d", Min(&arr));
    printf("\nThe maximum element of the array is %d", Max(&arr));

    // Left rotate by 2
    LeftRotate(&arr, 2);
    printf("\nAfter two rotations we get:\n");
    Display(&arr);
    // Reversing
    printf("\nThe Reversed Array is:\n");
    Reverse(&arr);
    Display(&arr);
    free(arr.Arr);
    return 0;
}