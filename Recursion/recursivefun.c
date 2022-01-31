/*
A recursive function is a function which is calling itself and has a base condition
responsible for terminating the recursive loop
*/

#include <stdio.h>

void fun(int num)
{
    if (num > 0)
    {
        printf("%d ", num);
        fun(num - 1);
    }
}

int main()
{
    int x = 5;
    fun(x); // 5 4 3 2 1

    return 0;
}
