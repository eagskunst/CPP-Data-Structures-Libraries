#ifndef EAGS_BASE_STRUCTURE
#define EAGS_BASE_STRUCTURE

#include "Node.h"
#include <iostream>

template <typename T>
class BaseStructure{
    protected:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* currentPeak;
        int size;
    public:
        virtual bool insertAtEnd(T data) = 0;
        virtual bool insertAtStart(T data) = 0;
        virtual bool deleteAtEnd() = 0;
        virtual bool deleteAtStart() = 0;
        virtual bool deleteElement(T data) = 0;
        T* peek();
        bool isEmpty();
        void print();
        bool clear();
        int getSize();
        BaseStructure();
        ~BaseStructure();
};

template <typename T>
BaseStructure<T>::BaseStructure(){
    this->head = NULL;
    this->tail = NULL;
    this->currentPeak = NULL;
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
    this->size = 0;
    this->currentPeak = NULL;
    return true;
}

/*
    Beware, you need a copy constructor for T and recieve 
    the return type on a reference (Ex: Person p = list.peek())
 */

template <typename T>
T* BaseStructure<T>::peek(){
    if(isEmpty()) return NULL;
    else if(this->currentPeak == NULL){
        this->currentPeak = this->head;
    }
    else if(this->currentPeak->next != NULL){
        this->currentPeak = this->currentPeak->next;
    }
    else{
        this->currentPeak = NULL;
        return NULL;
    }
    T *ref = new T(this->currentPeak->getData());
    return ref;
}

template <typename T>
void BaseStructure<T>::print(){
    Node<T>* tempNode = this->head;
    if(isEmpty()){
        return;
    }
    while(tempNode != NULL){
        cout<<tempNode->getData()<<" ";
        tempNode = tempNode->getNext();
    }
}

template <typename T>
int BaseStructure<T>::getSize(){
    return size;
}
#endif
