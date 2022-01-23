/*
Implementing a stack using a simple array
*/
#include <iostream>
#include <cstring>

class Stack
{
    int top;
    int arr[6];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 6; i++)
        {
            arr[i] = 0.0f;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == 5)
            return true;
        else
            return false;
    }

    void push(int data);
    int pop();
    int count();
    int peek(int index);
    void change(int pos, int data);
    void display();
};

void Stack::push(int data)
{
    if (isFull())
        std::cout << "Stack overflow";
    else
    {
        top++;
        arr[top] = data;
    }
}

int Stack::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack Underflow" << std::endl;
        return 0;
    }
    else
    {
        int pop_val = arr[top];
        arr[top] = 0.0f;
        top--;
        return pop_val;
    }
}

int Stack::peek(int index)
{
    if (top == -1 || index > top)
    {
        std::cout << "Stack overflow" << std::endl;
    }
    return arr[index];
}

int Stack::count()
{
    return (top + 1);
}

void Stack::change(int pos, int data)
{
    if (pos > top)
    {
        std ::cout << "Position out of range" << std::endl;
    }
    else
    {
        arr[pos] = data;
        std::cout << "The changed value at: " << pos << std::endl;
    }
}

void Stack::display()
{
    std::cout << "All stack elements are:" << std::endl;
    for (int i = 5; i >= 0; i--)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << "\n";
}

// Driver code
int main()
{
    Stack S1;
    int option, position, data;

    do
    {
        std::cout << "Select Option. Enter 0 to exit";
        std::cout << "\n1. Push()";
        std::cout << "\n2. Pop()";
        std::cout << "\n3. Count()";
        std::cout << "\n4. Peek()";
        std::cout << "\n5. Change()";
        std::cout << "\n6. IsEmpty()";
        std::cout << "\n7. IsFull()";
        std::cout << "\n8. Display()";
        std::cout << "\n9. Clear screen\n\n";

        std::cin >> option;
        switch (option)
        {
            case 0:
                break;
            case 1:
                std::cout << "Enter Data to push to stack\n";
                std::cin >> data;
                S1.push(data);
                break;

            case 2:
                std::cout << "\nProcessing the pop operation\n";
                std::cout << "Poped value is: " << S1.pop();
                break;

            case 3:
                std::cout << "\n Objects of stack are: " << S1.count() << "\n";
                break;

            case 4:
                std::cout << "\nEnter Position to to lookup\n";
                std::cin >> position;
                std::cout << "Peek function called and value at: " << position << "is \n"
                        << S1.peek(position) << "\n";
                break;

            case 5:
                std::cout << "\nEnter the postion\n";
                std::cin >> position;
                std::cout << "\nEnter the data\n";
                std::cin >> data;
                std::cout << "Change function called\n";
                S1.change(position, data);
                break;

            case 6:
                if (S1.isEmpty())
                    std::cout << "The stack is Empty\n";
                else
                    std::cout << "The stack is not Empty\n";
                break;

            case 7:
                if (S1.isFull())
                    std::cout << "The stack is Full\n";
                else
                    std::cout << "The stack is not Full\n";
                break;
            case 8:
                std::cout << "\n";
                S1.display();
                break;
            case 9:
                system("cls");
                break;
            default:
                std::cout << "Choose the right option and try again\n";
                break;
        }
    } while (option != 0);
    std ::cin.get();
}