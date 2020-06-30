#include<iostream>

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;
public:
    LinkedList(){
        head = nullptr;
    }
    void insert(int data){
        Node* node = new Node();
        node->data = data;
        node->next = head;
        head = node;
    }
    
    bool remove(int data){
        Node* temp = head;
        Node* prev = nullptr;
        while((temp != nullptr) && (temp->data != data)){
            prev = temp;
            temp = temp->next;
        }
        if(temp == nullptr){
            return false;
        }
        else{
            if(prev == nullptr){
                delete temp;
                return true;
            }
            else{
                prev->next = temp->next;
                delete temp;
                return true;
            }
        }
    }

    bool search(int data){
        Node* temp = head;
        bool found = false;
        while(temp != nullptr){
            if(temp->data == data){
                found = true;
                break;
            }   
            temp = temp->next;
        }
        return found;
    }

    void printElements(){
        Node* temp = head;
        while(temp != nullptr){
            std::cout<<temp->data<<" ";
            temp = temp->next;
        }
        std::cout<<std::endl;
    }

    ~LinkedList(){
        Node* temp = head;
        while(temp != nullptr){
            Node* toRemove = temp;
            temp = temp->next;
            delete toRemove;
        }
    }
};
