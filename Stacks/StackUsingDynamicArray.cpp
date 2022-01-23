/*
Using Dynamic Array to implement a Stack Data Structure
*/

#include <iostream>
#include <string>

template <typename T>
class Stack
{
    T *storage_;
    int capability_;
    int n_;

    friend class Iterator;

private:
    void resize(int capacity)
    {
        T *temp = new T[capacity];
        for (int i = 0; i < n_; ++i)
        {
            temp[i] = storage_[i];
        }
        delete[] storage_;
        storage_ = temp;
        capability_ = capacity;
    }

    class Iterator
    {
        Stack *stack_;
        int n_;

    public:
        Iterator()
            : stack_(nullptr), n_(-1)
        {
        }

        Iterator(Stack *stack)
            : stack_(stack), n_(stack->capability_ - 1)
        {
        }

        void operator++()
        {
            --n_;
        }

        bool operator!=(const Iterator &Other)
        {
            return n_ != Other.n_;
        }

        T &operator*()
        {
            return stack_->storage_[n_];
        }
    };

public:
    Stack()
    {
        capability_ = 1;
        storage_ = new T[1];
        n_ = 0;
    }

    ~Stack()
    {
        delete[] storage_;
    }

    void push(T item)
    {
        if (n_ == capability_)
        {
            resize(capability_ * 2);
        }
        storage_[n_++] = item;
    }

    T pop()
    {
        T item = storage_[--n_];
        storage_[n_] = 0.0f;
        if (n_ > 0 && n_ == capability_ / 4)
        {
            resize(capability_ / 2);
        }
        return item;
    }

    bool is_empty() const
    {
        return n_ == 0;
    }

    int size() const
    {
        return n_;
    }

    Iterator begin()
    {
        return Iterator(this);
    }

    Iterator end()
    {
        return Iterator();
    }
};

// Driver code
int main()
{
    Stack<std::string> names;
    names.push("Felix");
    names.push("Hirwa");
    names.push("Nshuti.");
    std::string poped = names.pop();
    std::cout << "Poped data is "<<poped << std::endl;
    std::cout <<names.size() << std::endl;
    for (const std::string& note : names)
    {
        std::cout << note << std::endl;
    }

    std::cin.get();
}