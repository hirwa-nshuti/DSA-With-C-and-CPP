/*
When the first statement of recursive function is the recursive call
the function is considered the head recursive function
*/

#include <iostream>
using namespace std;

void fun(int x)
{
    if (x > 0)
    {
        fun(x - 1);
        cout << x << " ";
    }
}

int main()
{
    int num = 5;
    fun(num);

    cin.get();
}