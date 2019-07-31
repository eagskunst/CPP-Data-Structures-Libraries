#ifndef BIQUEUE_H
#define BIQUEUE_H
#include "iostream"
#include "BaseStructure.h"
using namespace std;

template <typename T>
class Biqueue: public BaseStructure<T>{
public:
    Biqueue();
    bool insertAtStart(T data);
    bool insertAtEnd(T data);
    bool deleteAtEnd();
    bool deleteAtStart();
    bool deleteElement(T data);
};

template <typename T>
Biqueue<T>::Biqueue():BaseStructure<T>(){

}

template<typename T>
bool Biqueue<T>::insertAtStart(T data){
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
bool Biqueue<T>::insertAtEnd(T data){
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

template <typename T>
bool Biqueue<T>::deleteAtStart(){
    if(this->isEmpty()){
        return false;
    }
    if(this->head->next != NULL){
        this->head = this->head->next;
        this->head->prev = NULL;
    }
    else{
        this->head = NULL;
    }
    this->size--;
    return true;
}

template <typename T>
bool Biqueue<T>::deleteAtEnd(){
    if(this->isEmpty()){
        return false;
    }
    if(this->tail->prev != NULL){
        this->tail = this->tail->prev;
        this->tail->next = NULL;
    }
    else{
        this->tail = NULL;
    }
    this->size--;
    return true;
}

template <typename T>
bool Biqueue<T>::deleteElement(T data){
    if(this->isEmpty()){
        return false;
    }
    if(this->head->getData() == data){
        this->head = this->head->next;
        return true;
    }
    else if(this->tail->getData() == data){
        this->tail = this->tail->prev;
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