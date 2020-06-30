#include <iostream>

template <typename T>
class Stack
{
private:
    int limit;
    T *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        limit = 10;
        arr = new T[limit];
    };

    Stack(int limit)
    {
        top = -1;
        this->limit = limit;
        arr = new T[limit];
    };
    
    bool isEmpty() const
    {
        return (top == -1);
    };
    
    bool isFull() const
    {
        return (top == limit - 1);
    };

    void push(T elem)
    {
        if (!isFull())
        {
            arr[++top] = elem;
        }
        else
        {
            std::cout << "Array is full" << std::endl;
        }
    };

    T pop()
    {
        if (!isEmpty())
        {
            int elem = arr[top];
            top = top - 1;
            return elem;
        }
        else
        {
            std::cout << "Array is empty" << std::endl;
            return -1;
        }
    };

    void printElements() const
    {
        std::cout << "Elements are :" << std::endl;
        for (int i = 0; i <= top; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    };
    
    ~Stack()
    {
        delete[] arr;
    };
};