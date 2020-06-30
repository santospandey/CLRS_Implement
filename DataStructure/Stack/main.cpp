#include<iostream>
#include"stack.h"

int main(int argc, char** argv){    
    Stack stk(100);
    for(int i=0; i<100; i++){
        stk.push(rand()%100);
    }    
    
    stk.printElements();
}