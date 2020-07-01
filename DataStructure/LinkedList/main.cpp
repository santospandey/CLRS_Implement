#include<iostream>
#include<string>
#include"LinkedList.cpp"

int main(){
    LinkedList<std::string> ll;
    ll.insert("Mouse");    
    ll.insert("Cat");
    ll.insert("Rabbit");
    ll.insert("leopard");
    ll.insert("Tiger");    
    std::cout<<ll.search("Rabbit");
    std::cout<<std::endl;
    ll.printElements();
}