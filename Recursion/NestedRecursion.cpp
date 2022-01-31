/*
When the recursion call passes the parameter as a recursive call function
*/

#include <iostream>
using namespace std;

int nestedRecur(int n)
{
    if(n > 100)
    {
        return n - 10;
    }
    else
    {
        return nestedRecur(nestedRecur(n + 11));
    }
}

int main()
{
    int x = nestedRecur(110);
    cout << x << endl;
    cin.get();
}