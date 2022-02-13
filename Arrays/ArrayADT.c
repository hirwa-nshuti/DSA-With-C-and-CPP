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

    Display(arr);

    free(arr.Arr);
    return 0;
}