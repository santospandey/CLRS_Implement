#pragma once

class Stack
{
private:
    int limit;
    int* arr;
    int top;
public:
    Stack();
    Stack(int limit);
    void printElements() const;
    void push(int elem);
    int pop();
    bool isEmpty() const;
    bool isFull() const;
    ~Stack();
};