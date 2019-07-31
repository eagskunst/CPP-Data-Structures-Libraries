#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include "BaseStructure.h"

template <typename T>
class DoubleLinkedList : public BaseStructure<T>{
    private:
        bool insertEmptyCase(T data);
        bool insertIfOnlyOneItemInList(T data, const bool isStart);
    public:
        bool insertAtStart(T data);
        bool insertAtEnd(T data);
        bool insertAfter(T element, T data);
        bool insertBefore(T element, T data);
        bool deleteAtEnd();
        bool deleteAtStart();
        bool deleteElement(T data);
        DoubleLinkedList();
        ~DoubleLinkedList();
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList():BaseStructure<T>(){

}

template <typename T>
bool DoubleLinkedList<T>::insertEmptyCase(T data){
    Node<T>* nNode = new Node<T>(data);
    if(!nNode) return false;
    this->head = nNode;
    this->size++;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::insertIfOnlyOneItemInList(T data, const bool isStart){
    Node<T>* nNode = new Node<T>(data);
    if(!nNode) return false;
    if(isStart){
        this->tail = this->head;
        this->tail->prev = nNode;
        nNode->next = this->tail;
        this->head = nNode;
    }
    else{
        nNode->prev = this->head;
        this->head->next = nNode;
        this->tail = nNode;
    }
    this->size++;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::insertAtStart(T data){
    if(this->isEmpty()) return insertEmptyCase(data);
    if(this->getSize() == 1) return insertIfOnlyOneItemInList(data, true);

    Node<T>* nNode = new Node<T>(data);
    if(!nNode) return false;
    nNode->next = this->head;
    this->head->prev = nNode;
    this->head = nNode;
    this->size++;
    return true;    
}

template <typename T>
bool DoubleLinkedList<T>::insertAtEnd(T data){
    if(this->isEmpty()) return insertEmptyCase(data);
    if(this->getSize() == 1) return insertIfOnlyOneItemInList(data, true);

    Node<T>* nNode = new Node<T>(data);
    if(!nNode) return false;
    nNode->prev = this->tail;
    this->tail->next = nNode;
    this->tail = nNode;
    this->size++;
    return true;
    
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){

}


#endif