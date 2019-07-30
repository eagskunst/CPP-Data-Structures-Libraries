#ifndef EAGS_BASE_STRUCTURE
#define EAGS_BASE_STRUCTURE

#include "Node.h"
#include <iostream>

template <typename T>
class BaseStructure{
    private:
        bool isValidInstanceType();
    protected:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* currentPeak;
        int size;
    public:
        virtual bool insertAtEnd(T data) = 0;
        bool insertAtPosition(T data, int pos);
        virtual bool insertAtStart(T data) = 0;
        virtual bool deleteAtEnd() = 0;
        virtual bool deleteAtStart() = 0;
        virtual bool deleteElement(T data) = 0;
        void peek(T &value);
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
    Beware, you need to override your class is '=' operator:
    Example:
    Str* operator= (char* word){
        if(word != NULL) return new Str(word);
        else return NULL;
    }
 */

template <typename T>
void BaseStructure<T>::peek(T &value){
    if(isEmpty()) {
        value = NULL;
        return;
    }
    else if(this->currentPeak == NULL){
        this->currentPeak = this->head;
    }
    else if(this->currentPeak->next != NULL){
        this->currentPeak = this->currentPeak->next;
    }
    else{
        this->currentPeak = NULL;
        value =  NULL;
        return;
    }
    value = this->currentPeak->getData();
}

template <typename T>
bool BaseStructure<T>::insertAtPosition(T data, int pos){
    // if(!isValidInstanceType()) return false;
    if(pos<=0) return insertAtStart(data);
    if(pos>size) return insertAtEnd(data);
    Node<T>* mRef = this->head == NULL ? this->tail->next : this->head; //Si la cabeza es nula, usar la cola como cabeza 
    Node<T>* prevRef;
    int i;
    for (i = 0; i < pos; i++){
        prevRef = mRef;
        mRef = mRef->next;
    }
    Node<T>* nodeToAdd = new Node<T>(data);
    if(!nodeToAdd) return false;
    prevRef->next = nodeToAdd;
    nodeToAdd->next = mRef;
    this->size++;
    return true;
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
    cout<<endl;
}

template <typename T>
int BaseStructure<T>::getSize(){
    return size;
}

/* template <typename T>
bool BaseStructure<T>::isValidInstanceType(){
    type_info ti = typeid(Biqueue<T>);
    return ( typeid(this) != ti );
} */
#endif
