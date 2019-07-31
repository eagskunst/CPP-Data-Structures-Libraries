#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include "BaseStructure.h"

using namespace std;

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
bool DoubleLinkedList<T>::deleteAtEnd(){
    if(isEmpty()) return false;
    if(this->size == 1){
        delete this->head;
    }
    else{
        Node<T>* currentTail = this->tail;
        Node<T>* mRef = currentTail->prev;
        mRef->next = NULL;
        this->tail = mRef;
        delete currentTail;
    }
    this->size--;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteAtStart(){
    if(isEmpty()) return false;
    if(this->size == 1){
        delete this->head;
    }
    else{
        Node<T>* currentHead = this->head;
        Node<T>* mRef = currentHead->next;
        mRef->prev = NULL;
        this->head = mRef;
        delete currentHead;
    }
    this->size--;
    return true;
}

template <typename T>
bool DoubleLinkedList<T>::deleteElement(T data){
    if(isEmpty()) return false;
    Node<T>* mHead = this->head;
    Node<T>* mTail = this->tail;
    if(mHead != NULL && mHead->getData() == data){
        delete mHead;
        return true;
    }
    else if(mTail != NULL && mTail->getData() == data){
        delete mTail;
        return true;
    }
    else if(mHead != NULL && mTail != NULL){
        Node<T>* checkNode = mHead->next;
        Node<T>* prevCheckNode = checkNode->prev;
        while(checkNode != mTail){
            if(checkNode->getData() == data) {
                prevCheckNode->next = checkNode->next;
                checkNode->prev = prevCheckNode;
            }
        }
    }
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){

}


#endif