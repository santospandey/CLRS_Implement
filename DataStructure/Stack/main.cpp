#include<iostream>
#include <string>
#include "stack.cpp"

int main(int argc, char** argv){    
    Stack<std::string> stk(100);
    for(int i=0; i<100; i++){
        std::string str = "Hello world";
        stk.push(str);
    }    
    
    stk.printElements();
}