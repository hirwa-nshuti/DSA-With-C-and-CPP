/*
Implementing Array ADT using C++
*/

#include <iostream>
using namespace std;

template <class T>

class Array
{
    T *Arr;
    int size;
    int length;
    void Swap(T *x, T *y)
    {
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y;
    }
    bool isSorted()
    {
        int i;
        for (i = 0; i < length - 1; i++)
        {
            if (Arr[i] > Arr[i + 1])
                return false;
        }
        return true;
    }

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

    Array *Merge(Array<T> arr2);
    void Display();
    void Append(T val);
    void Insert(int index, T val);
    void InsertSorted(T val);
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

// Linear Search
template <class T>
T Array<T>::LinearSearch(T val)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (Arr[i] == val)
            return i;
    }
    return -1;
}

// Binary Search
template <class T>
T Array<T>::BinarySearch(T val)
{
    int low = 0;
    int high = length;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (Arr[mid] == val)
            return mid;
        else if (Arr[mid] > val)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Inserting in a Sorted array
template <class T>
void Array<T>::InsertSorted(T val)
{
    if (isSorted())
    {
        int i = length - 1;
        if (length == size)
            return;
        while (i >= 0 && Arr[i] > val)
        {
            Arr[i + 1] = Arr[i];
            i--;
        }
        Arr[i + 1] = val;
        length++;
    }
}
// Using Set Method
template <class T>
void Array<T>::Set(int index, T val)
{
    if (index <= length && index >= 0)
    {
        Arr[index] = val;
    }
}

// Using Get Method
template <class T>
T Array<T>::Get(int index)
{
    if (index <= length && index >= 0)
    {
        return Arr[index];
    }
    return -1;
}

// Max Method
template <class T>
T Array<T>::Max()
{
    int i, max = Arr[0];
    for (i = 0; i < length; i++)
    {
        if (max <= Arr[i])
            max = Arr[i];
    }

    return max;
}

// Minimum method
template <class T>
T Array<T>::Min()
{
    int i, min = Arr[0];
    for (i = 0; i < length; i++)
    {
        if (min >= Arr[i])
            min = Arr[i];
    }

    return min;
}

// Reversing Array
template <class T>
void Array<T>::Reverse()
{
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--)
        Swap(&Arr[i], &Arr[j]);
}

// Left Rotating Array
template <class T>
void Array<T>::LeftRotate(int rotations)
{
    int i;
    while (rotations--)
    {
        int temp = Arr[0];
        for (i = 0; i < length - 1; i++)
            Arr[i] = Arr[i + 1];
        Arr[length - 1] = temp;
    }
}

// Moving Negatives to left
template <class T>
void Array<T>::MoveNegatives()
{
    int i = 0, j = length - 1;
    while (i < j)
    {
        while (Arr[i] < 0)
            i++;
        while (Arr[j] > 0)
            j--;
        if (i < j)
            Swap(&Arr[i], &Arr[j]);
    }
}

// Merging Two Arrays
template <class T>
Array<T> *Array<T>::Merge(Array<T> arr2)
{
    int i, j, k;
    i = j = k = 0;

    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (Arr[i] < arr2.Arr[j])
            arr3->Arr[k++] = Arr[i++];
        else
            arr3->Arr[k++] = arr2.Arr[j++];
    }
    for (; i < length; i++)
        arr3->Arr[k++] = Arr[i];
    for (; j < arr2.length; j++)
        arr3->Arr[k++] = arr2.Arr[j];
    arr3->length = length + arr2.length;

    return arr3;
}

// Driver Code
int main()
{
    Array<int> *arr1, arr2, *arr3;
    int choice, arr_size;
    int val, index;
    cout << "Enter the Size of Array: ";
    cin >> arr_size;
    arr1 = new Array<int>(arr_size);
    arr2.Append(17);
    arr2.Append(29);

    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Append\n";
        cout << "2. Insert\n";
        cout << "3. Insert in Sorted Array\n";
        cout << "4. Set\n";
        cout << "5. Reverse\n";
        cout << "6. Move Negatives to left\n";
        cout << "7. Left Rotate\n";
        cout << "8. Display\n";
        cout << "9. Delete at given Index\n";
        cout << "10. Linear Search\n";
        cout << "11. Binary Search\n";
        cout << "12. Get at given index\n";
        cout << "13. Return Max\n";
        cout << "14. Minimum\n";
        cout << "15. Merger Two arrays\n";
        cout << "0. Ending the program\n";
        cout << "\nEnter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element to append to array : ";
            cin >> val;
            arr1->Append(val);
            break;
        case 2:
            cout << "Enter the index and element : ";
            cin >> index >> val;
            arr1->Insert(index, val);
            break;
        case 3:
            cout << "Enter the value to Insert : ";
            cin >> val;
            arr1->InsertSorted(val);
            break;
        case 4:
            cout << "Enter the index  and element : ";
            cin >> index >> val;
            arr1->Set(index, val);
            break;
        case 5:
            arr1->Reverse();
            break;
        case 6:
            arr1->MoveNegatives();
            break;
        case 7:
            cout << "Enter number of rotations : ";
            cin >> val;
            arr1->LeftRotate(val);
            break;
        case 8:
            cout << "Array Elements are: \n";
            arr1->Display();
            break;
        case 9:
            cout << "Enter the index of element to delete : ";
            cin >> index;
            cout << "Deleted element is " << arr1->Delete(index) << endl;
            break;
        case 10:
            cout << "Enter the value to Search with Linear Search : ";
            cin >> val;
            if (arr1->LinearSearch(val) != -1)
                cout << val << " Found at " << arr1->LinearSearch(val) << endl;
            else
                cout << "Element not found\n";
            break;
        case 11:
            cout << "Enter the value to Search with Binary Search : ";
            cin >> val;
            if (arr1->BinarySearch(val) != -1)
                cout << val << " Found at " << arr1->BinarySearch(val) << endl;
            else
                cout << "Element not found\n";
            break;
        case 12:
            cout << "Enter the index to get it's element : ";
            cin >> index;
            cout << "At " << index << " there is " << arr1->Get(index) << endl;
            break;
        case 13:
            cout << "The maximum element is : " << arr1->Max() << endl;
            break;
        case 14:
            cout << "The minimum element is : " << arr1->Min() << endl;
            break;
        case 15:
            arr3 = arr1->Merge(arr2);
            cout << "Merged Array is : \n";
            arr3->Display();
            break;

        default:
            break;
        }
    } while (choice < 16 && choice > 0);

    return 0;
}