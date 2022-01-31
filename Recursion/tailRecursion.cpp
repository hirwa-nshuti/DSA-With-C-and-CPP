/*
A tail recursive function is calling itself and that call is the
last statement of that function.
*/

#include <iostream>
using namespace std;

void fun(int x)
{
    if (x > 0)
    {
        cout << x << " ";
        fun(x - 1);
    }
}
int main()
{
    int n = 5;
    fun(n);
    cin.get();
}