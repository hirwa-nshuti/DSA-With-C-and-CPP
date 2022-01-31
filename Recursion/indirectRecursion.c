/*
When more than one recursive functions are calling eachother in
a circular fashion.
*/

#include <stdio.h>

void funB(int num);

void funA(int num)
{
    if(num > 0)
    {
        printf("%d ", num);
        funB(num -1);
    }
}
void funB(int num)
{
    if(num > 0)
    {
        printf("%d ", num);
        funA(num/2);
    }
}

int main()
{
    funA(20);

    return 0;
}