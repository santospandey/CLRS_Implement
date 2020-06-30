#include<iostream>
#include "stack.h"

Stack::Stack(){    
    top = -1;
    limit = 10;
    arr = new int[limit];
}

Stack::Stack(int l){
    top = -1;
    limit = l;
    arr = new int[limit];
}

bool Stack::isEmpty() const{
    return (top == -1);
}

bool Stack::isFull() const{
    return (top == limit-1);
}

void Stack::push(int elem){
    if(!isFull()){
        arr[++top] = elem;
    }
    else{
        std::cout<<"Array is full"<<std::endl;
    }
}

int Stack::pop(){
    if(!isEmpty()){
        int elem = arr[top];
        top = top-1;
        return elem;
    }
    else{
        std::cout<<"Array is empty"<<std::endl;
        return -1;
    }
}

void Stack::printElements() const{
    std::cout<<"Elements are :"<<std::endl;
    for(int i=0; i<=top; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

Stack::~Stack(){
    delete[] arr;
}