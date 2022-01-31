/*
When a function is calling itself more than one times it is considered
a tree recursive function.
*/
#include <iostream>
using namespace std;

void fun(int x)
{
    if (x > 0)
    {
        cout << x << " ";
        fun(x - 1);
        fun(x - 1);
    }
}

// Example is printing the Fibonnaci Sequence

int fibo(int num)
{
    if(num == 0 || num == 1)
    {
        return num;
    }
    else
    {
        return fibo(num-1) + fibo(num-2);
    }
}
int main()
{
    int n = 3;
    fun(n);
    
    cout <<"\n" << fibo(9) << endl;
    cin.get();
}