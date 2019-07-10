#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Node.h"
#include "iostream"
#include "BaseStructure.h"
using namespace std;

template <typename T>
class LinkedList: public BaseStructure<T>{
public:
    LinkedList();
    bool insertAtStart(T data);
    bool insertAtEnd(T data);
    bool deleteAtEnd(){return false;}
    bool deleteAtStart(){return false;}
    bool deleteElement(T data){return false;}
};

template <typename T>
LinkedList<T>::LinkedList():BaseStructure<T>(){

}

template<typename T>
bool LinkedList<T>::insertAtStart(T data){
    Node<T> *nNode = new Node<T>(data);
    if(!nNode) return false;
    if(this->size == 0){
        this->head = nNode;
        this->tail = nNode;
    }
    else{
        nNode->next = this->head;
        this->head->prev = nNode;
        this->head = nNode;
    }
    this->size++;
    return true;
}

template <typename T>
bool LinkedList<T>::insertAtEnd(T data){
    Node<T> *nNode = new Node<T>(data);
    if(!nNode) return false;
    if(this->size == 0){
        this->head = nNode;
        this->tail = nNode;
    }
    else{
        nNode->prev = this->tail;
        this->tail->next = nNode;
        this->tail = nNode;
    }
    this->size++;
    return true;
}

#endif