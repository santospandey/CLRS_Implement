#include<iostream>

template<typename T>
struct Node
{
    T data;
    Node* next;
};

template<typename T>
class LinkedList
{
private:
    Node<T>* head;
public:
    LinkedList(){
        head = nullptr;
    }
    
    void insert(T data){
        Node<T>* node = new Node<T>();
        node->data = data;
        node->next = head;
        head = node;
    }
    
    bool remove(T data){
        Node<T>* temp = head;
        Node<T>* prev = head;
        while((temp != nullptr) && (temp->data != data)){
            prev = temp;
            temp = temp->next;
        }

        if(temp == nullptr){
            return false;
        }
        else if(prev == head){
            if(prev->next == nullptr){
                head = nullptr;
                delete temp;
                return true;
            }
            else{
                head = head->next;
                delete temp;
                return true;
            }
        }
        else{
            prev->next = temp->next;
            delete temp;
            return true;
        }
    }

    bool search(T data){
        Node<T>* temp = head;
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
        Node<T>* temp = head;
        while(temp != nullptr){
            std::cout<<temp->data<<" ";
            temp = temp->next;
        }
        std::cout<<std::endl;
    }

    ~LinkedList(){
        Node<T>* temp = head;
        while(temp != nullptr){
            Node<T>* toRemove = temp;
            temp = temp->next;
            delete toRemove;
        }
    }
};
