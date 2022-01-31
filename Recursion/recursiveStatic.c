/*
Recursive function with Static variables
*/

#include <stdio.h>

// Using static variable
int recur(int num)
{
    static int x = 0;

    if (num > 0)
    {
        x++;
        return recur(num - 1) + x;
    }
    return 0;
}

// Using Global variable
int x = 0;
int recGlo(int num)
{
    if (num > 0)
    {
        x++;
        return recGlo(num - 1) + x;
    }
    return 0;
}

// Driver code
int main()
{
    int number = 5;
    printf("%d\n", recur(5));  // 25
    printf("%d\n", recGlo(5)); // 25
    return 0;
}