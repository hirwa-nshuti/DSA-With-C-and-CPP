/*
Code for:
finding maximum and minimum element in a linked list
Searching for a given element
Inserting to a linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#define MIN_INT -2147483648
#define MAX_INT 2147483647

// Finding the maximum
int max(struct Node *p)
{
    int x;
    if (p == NULL)
        return MIN_INT;
    x = max(p->next);
    return x > p->data ? x : p->data;
}

// Finding the minimum
int min(struct Node *p)
{
    int m = MAX_INT;
    while (p != NULL)
    {
        if (m > p->data)
            m = p->data;
        p = p->next;
    }

    return m;
}

int main()
{
    int *Arr = (int *)malloc(5 * sizeof(int));
    Arr[0] = 3;
    Arr[1] = 4;
    Arr[2] = 78;
    Arr[3] = 9;
    Arr[4] = 19;
    CreateLL(Arr, 5);
    DisplayLL(first);
    free(Arr);
    int maximum = max(first);
    int minimum = min(first);
    printf("\nThe maximum element is %d", maximum);
    printf("\nThe minimum element is %d", minimum);
}