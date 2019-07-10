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
    bool insertAt(int i, T data);
    bool insertAtEnd(T data);
    bool isEmpty();
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
    if(!nNode) return false;
    if(size == 0){
        this->head = nNode;
        this->tail = nNode;
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
bool LinkedList<T>::insertAt(int i, T data){
    if(true) return false; //Work in process
    bool startHead = i<=size;
    int j;
    Node<T> *nNode = new Node<T>(data);
    Node<T> *tempNode;
    if(startHead){
        j = 0;
        tempNode = this->head;
        while(j<=size/2){
            if(j != i){
                tempNode = tempNode->getNext();
            }
            else{

            }
            j++;
        }
    }
}

template <typename T>
bool LinkedList<T>::insertAtEnd(T data){
    Node<T> *nNode = new Node<T>(data);
    if(!nNode) return false;
    if(size == 0){
        this->head = nNode;
        this->tail = nNode;
    }
    else{
        nNode->prev = tail;
        this->tail->next = nNode;
        this->tail = nNode;
    }
}

template <typename T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}


template <typename T>
void LinkedList<T>::print(){
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