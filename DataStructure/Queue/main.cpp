#include<iostream>
#include<string>
#include"Queue.cpp"

int main(int argc, char** argv){
    Queue<std::string> queue;
    queue.enqueue("hello");
    queue.enqueue("mr.");
    queue.enqueue("jockey");    
    queue.printElements();
}