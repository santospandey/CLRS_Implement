#ifndef PRIORITY_Q
#define PRIORITY_Q

#include<iostream>
#include<vector>

class PriorityQueue{
    private:        
        std::vector<int>arr;
    public:    
        PriorityQueue();
        
        void maxHeapify(int i);

        int parent(int index);

        void insert(int key);

        int maximum();

        int extractMaximum();

        void increaseKey(int i, int key);

        void display();
};

#endif