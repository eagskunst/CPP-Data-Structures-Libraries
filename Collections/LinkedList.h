#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "iostream"
#include "BaseStructure.h"
using namespace std;

template <typename T>
class LinkedList: public BaseStructure<T>{
private:
    
public:
    LinkedList();
    bool insertAtStart(T data);
    bool insertAtEnd(T data);
    bool insertAfter(T element, T data);
    bool insertBefore(T element, T data);
    bool deleteAtEnd();
    bool deleteAtStart();
    bool deleteElement(T data);
};

template <typename T>
LinkedList<T>::LinkedList():BaseStructure<T>(){

}

template <typename T>
bool LinkedList<T>::insertAtStart(T data){
    Node<T> *nNode = new Node<T>(data);
    if(!nNode) return false;
    if(this->isEmpty()){
        this->head = nNode;
    }
    else{
        nNode->next = this->head;
        this->head = nNode;
    }
    this->size++;
    return true;
}

template <typename T>
bool LinkedList<T>::insertAtEnd(T data){
    Node<T> *nNode = new Node<T>(data);
    Node<T> *tempNode = this->head;
    if(!nNode) return false;
    if(this->isEmpty()){
        this->head = nNode;
    }
    else{
        while(tempNode->next != NULL) tempNode = tempNode->next;
        tempNode->next = nNode;
    }
    this->size++;
    return true;
}

template <typename T>
bool LinkedList<T>::deleteAtEnd(){
    if(this->isEmpty()) return false;
    
    Node<T> *tempNode = this->head;
    Node<T> *prev = NULL;

    while(tempNode->next != NULL) {
        prev = tempNode;
        tempNode = tempNode->next;
    }

    prev->next = NULL;
    free(tempNode);
    tempNode = NULL;
    this->size--;
    return true;
}

template <typename T>
bool LinkedList<T>::deleteAtStart(){
    if(this->isEmpty()) return false;
    
    Node<T> *mHead = this->head->next;
    free(this->head);
    this->head = mHead;
    this->size--;
    return true;
}

template <typename T>
bool LinkedList<T>::deleteElement(T data){
    if(this->isEmpty()){
        return false;
    }

    if(this->head->getData() == data){
        this->head = this->head->next;
        return true;
    }
    
    Node<T>* curr = this->head;
    Node<T>* prev;

    while(curr != NULL && curr->getData() != data ){
        prev = curr;
        curr = curr->getNext();
    }
    if(curr == NULL) return false;

    prev->next = curr->next;
    return true;
}

#endif