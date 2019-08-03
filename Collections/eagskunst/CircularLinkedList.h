#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H
#include "iostream"
#include "BaseStructure.h"
using namespace std;

template <typename T>
class CircularLinkedList: public BaseStructure<T>{
    private:
        bool insertEmpty(T data);
        Node<T> *ptr;
    public:
        CircularLinkedList();
        bool insertAtStart(T data);
        bool insertAtEnd(T data);
        void move(int pos);
        void restartMove();
        bool deleteAtEnd();
        bool deleteAtStart();
        bool deleteElement(T data){return false;}
        void print();
        void peek(T &value);
        bool clear();
};

template <typename T>
CircularLinkedList<T>::CircularLinkedList():BaseStructure<T>(){

}

template <typename T>
bool CircularLinkedList<T>::insertAtStart(T data){
    if(this->tail == NULL) return insertEmpty(data);

    Node<T> *nNode = new Node<T>(data);
    if(!nNode) return false;
    nNode->next = this->tail->next;
    this->tail->next = nNode;
    this->size++;
    return true;
}

template <typename T>
bool CircularLinkedList<T>::insertAtEnd(T data){
    if(this->tail == NULL) return insertEmpty(data);

    Node<T> *nNode = new Node<T>(data);
    if(!nNode) return false;

    nNode->next = this->tail->next;
    this->tail->next = nNode;
    this->tail = nNode;
    this->size++;
    return true;
}

template <typename T>
bool CircularLinkedList<T>::insertEmpty(T data){
    this->tail = new Node<T>(data);
    if(!(this->tail)) return false;
    this->tail->next = this->tail;
    this->ptr = this->tail;
    this->size++;
    return true;
}

template <typename T>
bool CircularLinkedList<T>::deleteAtStart(){
    if(this->tail == NULL) return false;
    Node<T> *mHead = this->tail->next;
    this->tail->next = mHead->next;
    delete mHead;
    mHead = NULL;
    this->size--;
    return true;
}

template <typename T>
bool CircularLinkedList<T>::deleteAtEnd(){
    if(this->tail == NULL) return false;
    move(this->size - 1);
    Node<T> *curr = this->ptr;
    curr->next = this->tail->next;
    Node<T> *lastTail = this->tail;
    this->tail = curr;
    delete lastTail;
    restartMove();
    this->size--;
    return true;
}

template <typename T>
void CircularLinkedList<T>::move(int pos){
    if(pos<0) pos *=-1;
    for (int i = 0; i < pos; i++){
        this->ptr = this->ptr->next;
    }
}

template <typename T>
void CircularLinkedList<T>::restartMove(){
    this->ptr = this->tail;
}

template <typename T>
void CircularLinkedList<T>::print(){
    if(this->tail == NULL) return;
    Node<T> *tempNode = this->tail->next;
    do{
        cout<<tempNode->getData()<<" ";
        tempNode = tempNode->next;
    }while(tempNode != this->tail->next);
    cout<<endl;
}

template <typename T>
void CircularLinkedList<T>::peek(T &value){
    if(this->tail == NULL) {
        value = NULL;
        return;
    }
    else if(this->currentPeak == NULL){
        this->currentPeak = this->tail;
    }
    else{
        this->currentPeak = this->currentPeak->next;
    }
    value = this->currentPeak->getData();
}

template <typename T>
bool CircularLinkedList<T>::clear(){
    Node<T>* currentRef = this->tail;
    Node<T>* next;
    if(this->isEmpty()){
        return true;
    }
    do {
        next = currentRef->getNext();
        delete currentRef;
        currentRef = next;
    }while(currentRef != this->tail);
    this->tail = NULL;
    this->size = 0;
    this->currentPeak = NULL;
    return true;
}

#endif