/*
Code for counting number of nodes and adding all the nodes
of a linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Counting the nodes
int count(struct Node *p)
{
    int cnt = 0;
    while (p != NULL)
    {
        cnt += 1;
        p = p->next;
    }

    return cnt;
}

// Finding sum of all elements of the Linked list
int add(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}
int main()
{
    int *Arr = (int *)malloc(5 * sizeof(int));
    Arr[0] = 3;
    Arr[1] = 4;
    Arr[2] = 8;
    Arr[3] = 9;
    Arr[4] = 19;
    CreateLL(Arr, 5);
    DisplayLL(first);
    int nodes = count(first);
    printf("\nThe number of nodes in a linked list is %d", nodes);
    int sum = add(first);
    printf("\nThe sum of all elements is %d", sum);
    return 0;
}