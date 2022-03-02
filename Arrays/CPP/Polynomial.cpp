/*
Polynomial representation in C++
*/
#include <iostream>

using namespace std;

class Terms
{
public:
    int coeff;
    int Exp;
};

class Polynomial
{
    int n;
    Terms *ele;

public:
    Polynomial(int n)
    {
        this->n = n;
        ele = new Terms[this->n];
    }
    ~Polynomial()
    {
        delete[] ele;
    }
    Polynomial operator+(Polynomial &p);
    friend istream &operator>>(istream &is, Polynomial &p);
    friend ostream &operator<<(ostream &os, Polynomial &p);
};

// Getting Polynomial Data
istream &operator>>(istream &is, Polynomial &p)
{
    int i;

    cout << "Enter " << p.n << " Terms" << endl;
    ;
    for (i = 0; i < p.n; i++)
    {
        cout << i << "'th Term : ";
        cin >> p.ele[i].coeff >> p.ele[i].Exp;
    }

    return is;
}

// Displaying Polynomial
ostream &operator<<(ostream &os, Polynomial &p)
{
    int i;
    for (i = 0; i < p.n; i++)
    {
        cout << p.ele[i].coeff << "x" << p.ele[i].Exp << endl;
    }

    return os;
}

// Adding two Polynomials
Polynomial Polynomial::operator+(Polynomial &p)
{
    int i, j, k;

    Polynomial *sum = new Polynomial(n + p.n);
    i = j = k = 0;
    while (i < n && j < p.n)
    {
        if (ele[i].Exp > p.ele[j].Exp)
            sum->ele[k++] = ele[i++];
        else if (ele[i].Exp < p.ele[j].Exp)
            sum->ele[k++] = p.ele[j++];
        else
        {
            sum->ele[k].Exp = ele[i].Exp;
            sum->ele[k++].coeff = ele[i++].coeff + p.ele[j++].coeff;
        }
    }
    for (; i < n; i++)
        sum->ele[k++] = ele[i];
    for (; j < p.n; j++)
        sum->ele[k++] = ele[j];
    sum->n = k;
    return *sum;
}
int main()
{
    Polynomial p1(3), p2(5);
    cout << "Enter for polynomial 1:\n";
    cin >> p1;
    cout << p1;
    cout << "Enter for polynomial 2:\n";
    cin >> p2;
    cout << p2;
    Polynomial sum = p1 + p2;
    cout << "\n\nSum is:\n";
    cout << sum;
    return 0;
}