#include<iostream>
#include<list>

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
    Node<T>* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    
    void insertStart(T data){
        Node<T>* node = new Node<T>();
        node->data = data;
        node->next = head;
        head = node;
    }

    void insertEnd(T data){
        Node<T>* node = new Node<T>();
        node->data = data;
        node->next = nullptr;

        if(head == nullptr){
            head = node;
            tail = node;
        }
        else{
            tail->next = node;
            tail = node;
        }
    }

    void insert(T data){
        insertEnd(data);
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

    Node<T>& search(T data){
        Node<T>* temp = head;        
        while(temp != nullptr && temp->data != data){            
            temp = temp->next;
        }
        return *temp;
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
