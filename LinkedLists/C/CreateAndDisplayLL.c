/*
Implementing Linked List using C language
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void CreateLL(int *arr, int n)
{
    int i;
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void DisplayLL(struct Node *LL)
{
    while (LL != NULL)
    {
        printf("%d -> ", LL->data);
        LL = LL->next;
    }
    printf("Null");
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
    return 0;
}