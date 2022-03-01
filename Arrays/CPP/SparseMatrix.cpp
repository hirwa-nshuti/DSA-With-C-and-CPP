/*
Implementing Sparse Matrix using c++
*/

#include <iostream>

using namespace std;

class Element
{
public:
    int i;
    int j;
    int val;
};

class SparseM
{
    int n;
    int m;
    int num;
    Element *ele;

public:
    SparseM(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
    ~SparseM()
    {
        delete[] ele;
    }

    SparseM operator+(SparseM &s);
    friend istream &operator>>(istream &is, SparseM &s);
    friend ostream &operator<<(ostream &os, SparseM &s);
};

// Getting Inputs of Matrix
istream &operator>>(istream &is, SparseM &s)
{
    cout << "Enter all non-zero elements\n";
    for (int i = 0; i < s.num; i++)
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].val;
    return is;
}

// Displaying the Matrix
ostream &operator<<(ostream &os, SparseM &s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (s.ele[k].i == i && s.ele[k].j == j)
                cout << s.ele[k++].val << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return os;
}

// Adding two Sparse Matrices
SparseM SparseM::operator+(SparseM &s)
{
    int i, j, k;
    if (m != s.m || n != s.n)
        return SparseM(0, 0, 0);
    SparseM *sum = new SparseM(m, n, num + s.num);

    i = j = k = 0;
    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[j].i)
            sum->ele[k++] = ele[i++];
        else if (ele[i].i > s.ele[j].i)
            sum->ele[k++] = s.ele[j++];
        else
        {
            if (ele[i].j < s.ele[j].j)
                sum->ele[k++] = ele[i++];
            else if (ele[i].j > s.ele[j].j)
                sum->ele[k++] = s.ele[j++];
            else
            {
                sum->ele[k] = ele[i];
                sum->ele[k++].val = ele[i++].val + s.ele[j++].val;
            }
        }
    }
    for (; i < num; i++)
        sum->ele[k++] = ele[i];
    for (; j < s.num; j++)
        sum->ele[k++] = s.ele[j];
    sum->num = k;

    return *sum;
}
int main()
{
    SparseM s1(5, 5, 5);
    SparseM s2(5, 5, 5);

    cin >> s1;
    cout << "First Matrix" << endl
         << s1;
    cin >> s2;
    cout << "Second Matrix" << endl
         << s2;
    SparseM sum = s1 + s2;
    cout << "Sum of both" << endl
         << sum;
    return 0;
}