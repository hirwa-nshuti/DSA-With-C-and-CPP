#include <iostream>

using namespace std;

template <class T>

class LowUpMatrix
{
    T *Arr;
    int n;

public:
    LowUpMatrix()
    {
        n = 3;
        Arr = new T[n * (n + 1) / 2];
    }

    LowUpMatrix(int x)
    {
        this->n = x;
        Arr = new T[n * (n + 1) / 2];
    }

    ~LowUpMatrix()
    {
        delete[] Arr;
    }

    // For Lower Matrix
    void Set_low(int i, int j, T val);
    T Get_low(int i, int j);
    void Set_up(int i, int j, T data);
    T Get_up(int i, int j);
    void Display_low();
    void Display_up();
    int GetDim() { return n; };
};

// Setting values for lowe matrix
template <class T>
void LowUpMatrix<T>::Set_low(int i, int j, T val)
{
    if (i >= j)
        Arr[i * (i - 1) / 2 + j - 1] = val;
}

// Returning element for lower triangle matrix at index i, j
template <class T>
T LowUpMatrix<T>::Get_low(int i, int j)
{
    if (i >= j)
        return Arr[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

// Displaying lower triangle Matrix
template <class T>
void LowUpMatrix<T>::Display_low()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << Arr[i * (i - 1) / 2 + j - 1] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

// Setting values for upper triangle matrix
template <class T>
void LowUpMatrix<T>::Set_up(int i, int j, T data)
{
    if (i <= j)
        Arr[n * (i - 1) - ((i - 2) * (i - 1)) / 2 + j - 1] = data;
}

// Return at index i, j for upper triangle
template <class T>
T LowUpMatrix<T>::Get_up(int i, int j)
{
    if (i <= j)
        return Arr[n * (i - 1) - ((i - 2) * (i - 1)) / 2 + j - 1];
    else
        return 0;
}

// Displaying Upper Triangle matrix
template <class T>
void LowUpMatrix<T>::Display_up()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i <= j)
                cout << Arr[n * (i - 1) - ((i - 2) * (i - 1)) / 2 + j - 1] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

int main()
{
    int d;
    cout << "Enter the matrix dimensions: ";
    cin >> d;
    LowUpMatrix<int> mat(d);

    int choice, data;
    do
    {
        cout << "\n\nMenu\n";
        cout << "1. LowerTriangle\n";
        cout << "2. UpperTriangle\n";
        cout << "0. Quit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter all Elements:\n";
            for (int i = 1; i <= d; i++)
            {
                for (int j = 1; j <= d; j++)
                {
                    cin >> data;
                    mat.Set_low(i, j, data);
                }
            }
            cout << "Displaying lower Triangle matrix\n";
            mat.Display_low();
            cout << "\nElement at [2][1] is : " << mat.Get_low(2, 1);
            cout << "\nDimension of lower Triangle matrix is: " << mat.GetDim();
            break;
        case 2:
            cout << "Enter all Elements:\n";
            for (int i = 1; i <= d; i++)
            {
                for (int j = 1; j <= d; j++)
                {
                    cin >> data;
                    mat.Set_up(i, j, data);
                }
            }
            cout << "Displaying Upper Triangle matrix\n";
            mat.Display_up();
            cout << "\nElement at [1][2] is : " << mat.Get_up(1, 3);
            cout << "\nDimension of Upper Triangle matrix is: " << mat.GetDim();
            break;

        default:
            break;
        }

    } while (choice < 3 && choice > 0);

    return 0;
}