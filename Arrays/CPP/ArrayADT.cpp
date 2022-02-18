#include <iostream>
using namespace std;

template <class T>

class Array
{
    T *Arr;
    int size;
    int length;
    void swap(T *x, T *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        Arr = new T[size];
    }

    Array(int siz)
    {
        size = siz;
        length = 0;
        Arr = new T[size];
    }

    ~Array()
    {
        delete[] Arr;
    }
    void Display();
    void Append(T val);
    void Insert(int index, T val);
    void Set(int index, T val);
    void Reverse();
    void LeftRotate(int rots);
    void MoveNegatives();
    T Delete(int index);
    T LinearSearch(T val);
    T BinarySearch(T val);
    T Get(int index);
    T Max();
    T Min();
};

// Displaying the Array
template <class T>
void Array<T>::Display()
{
    for (int i = 0; i < length; i++)
        cout << Arr[i] << " ";
    cout << endl;
}

// Inserting to the array
template <class T>
void Array<T>::Insert(int index, T x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            Arr[i + 1] = Arr[i];
        }
        Arr[index] = x;
        length++;
    }
}

// Appending Values to the array
template <class T>
void Array<T>::Append(T val)
{
    if (length < size)
        Arr[length++] = val;
}

// Deleting at a given index
template <class T>
T Array<T>::Delete(int index)
{
    T x;
    if (index >= 0 && index <= length)
    {
        x = Arr[index];
        for (int i = index; i < length - 1; i++)
            Arr[i] = Arr[i + 1];
        length--;
    }
    return x;
}
int main()
{
    Array<int> arr(5);
    arr.Insert(0, 1);
    arr.Insert(1, 2);
    arr.Append(4);
    arr.Display();
    cout << "Deleted Item: " << arr.Delete(2) << endl;
    cout << "After Deletion the array is:\n";
    arr.Display();
    return 0;
}