/*
Using recursive approach to find pow(m, n)
*/

#include <stdio.h>

long int power(int m, int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return power(m * m, n / 2);
    }
    else
    {
        return m * power(m * m, (n - 1) / 2);
    }
}

int main()
{
    int num, exp;
    long int powered;

    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the power: ");
    scanf("%d", &exp);

    powered = power(num, exp);

    if (powered == -1)
    {
        printf("Enter the positive exponent\n");
    }
    else
        printf("The power of %d by %d is %ld", num, exp, powered);

    return 0;
}