#ifndef EAGS_BASE_STRUCTURE
#define EAGS_BASE_STRUCTURE

#include "Node.h"
#include <iostream>

template <typename T>
class BaseStructure{
    protected:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        virtual bool insertAtEnd(T data) = 0;
        virtual bool insertAtStart(T data) = 0;
        virtual bool deleteAtEnd(T data) = 0;
        virtual bool deleteAtStart(T data) = 0;
        bool isEmpty();
        void print();
        bool clear();
        BaseStructure();
        ~BaseStructure();
};

template <typename T>
BaseStructure<T>::BaseStructure(){
    this->head = NULL;
    this->tail = NULL;
    size = 0;
}
template <typename T>
BaseStructure<T>::~BaseStructure(){
}

template <typename T>
bool BaseStructure<T>::isEmpty(){
    return size == 0;
}

template <typename T>
bool BaseStructure<T>::clear(){
    Node<T>* currentRef = this->head;
    Node<T>* next;
    if(isEmpty()){
        return true;
    }
    while (currentRef != NULL){
        next = currentRef->getNext();
        free(currentRef);
        currentRef = next;
    }
    this->head = NULL;
    return true;
}

template <typename T>
void BaseStructure<T>::print(){
    Node<T>* tempNode = this->head;
    if(isEmpty()){
        return;
    }
    do{
        cout<<tempNode->getData()<<" ";
        tempNode = tempNode->getNext();
        if(tempNode == tail && tempNode != NULL){
            cout<<tempNode->getData()<<" ";
        }
    }while(tempNode != this->tail && tempNode != NULL);
}
#endif
