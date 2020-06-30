#include <iostream>

template <typename T>
class Queue
{
private:
    T *arr;
    int limit;
    int front;
    int rear;

public:
    Queue()
    {
        limit = 10;
        front = -1;
        rear = -1;
        arr = new T[limit];
    }

    bool isFull()
    {
        return (rear == limit - 1);
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void enqueue(T value)
    {
        if (!isFull())
        {
            rear = rear + 1;
            arr[rear] = value;
        }
        else
        {
            std::cout << "Queue is full" << std::endl;
        }
    }

    T dequeue()
    {
        if (!isEmpty())
        {
            front = front + 1;
            T value = arr[front];
            return value;
        }
        else
        {
            front = -1;
            rear = -1;
            std::cout << "Queue is empty" << std::endl;
        }
    }

    void printElements()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Queue()
    {
        delete[] arr;
    }
};
