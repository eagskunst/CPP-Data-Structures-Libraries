#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include "iostream"
using namespace std;

template <typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList();
    bool insertAtStart(T data);
    bool insertAtEnd();
    void print();
};

template <typename T>
LinkedList<T>::LinkedList(){
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

template<typename T>
bool LinkedList<T>::insertAtStart(T data){
    Node<T> *nNode = new Node<T>(data);
    if(size == 0){
        this->head = nNode;
    }
    else{
        nNode->next = head;
        this->head->prev = nNode;
        this->head = nNode;
    }
    size++;
    return true;
}

template <typename T>
void LinkedList<T>::print(){
    Node<T>* tempNode = this->head;;
    while (true){
        cout<<tempNode->getData()<<" ";
        tempNode = tempNode->getNext();
        if(tempNode == NULL)break;
    }
    
}






#endif