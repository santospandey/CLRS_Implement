#include<iostream>
#include "p_queue.h"

int main(){

    PriorityQueue* pq = new PriorityQueue();
    pq->insert(56);
    pq->insert(78);
    pq->insert(23);
    pq->insert(378);
    pq->insert(223);
    std::cout<<pq->extractMaximum()<<" "<<std::endl;
    pq->display();
    std::cout<<pq->extractMaximum()<<" "<<std::endl;
    pq->display();
    return 0;
}