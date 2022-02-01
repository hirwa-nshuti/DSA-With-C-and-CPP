/*
Tylor series with loop approach
*/

#include <iostream>
using namespace std;

double e(int x, int n)
{
    double s = 1;
    int i;
    double num = 1;
    double den = 1;

    for (i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}

int main()
{
    int x, n;

    x = 1;
    n = 10;

    cout << e(x, n);
    cin.get();
}