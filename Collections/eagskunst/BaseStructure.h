#ifndef EAGS_BASE_STRUCTURE
#define EAGS_BASE_STRUCTURE

#include "Node.h"
#include "../../Algorithms/algoritmos.h"
#include <iostream>
#include <cmath>

template <typename T>
class BaseStructure{
    private:
        bool isValidInstanceType();
        Node<T>* getStartNode();
    protected:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* currentPeak;
        int size;
        virtual bool insertAtEnd(T data) = 0;
        bool insertAtPosition(T data, int pos);
        virtual bool insertAtStart(T data) = 0;
        virtual bool deleteAtEnd() = 0;
        virtual bool deleteAtStart() = 0;
        virtual bool deleteElement(T data) = 0;
    public:
        static const int NOT_FOUND = -1;
        friend bool operator==(BaseStructure<T> &a, BaseStructure<T> &b);
        void peek(T &value);
        bool isEmpty();
        void print();
        virtual bool clear(); //Not pure virtual because non-circular classes depends on base
        bool contains(T obj);
        virtual int find(T obj);
        virtual void getAt(int pos, T &value);
        virtual bool modify(int pos, T newValue);
        virtual bool modify(T oldValue, T newValue);
        int getSize();
        void sort(bool);
        T* toArray();
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

template <typename S>
bool operator==(BaseStructure<S> &a, BaseStructure<S> &b){
    Node<S>* starNode1 = a->getStartNode();
    Node<S>* starNode2 = b->getStartNode();
    return a == b;
}

template <typename T>
bool BaseStructure<T>::isEmpty(){
    return size == 0;
}

template <typename T>
bool BaseStructure<T>::clear(){ //If fails, change 'delete currentRef' for 'free(currentRef)'
    Node<T>* currentRef = getStartNode();
    Node<T>* next;
    if(isEmpty()){
        return true;
    }
    while (currentRef != NULL){
        next = currentRef->getNext();
        delete currentRef;
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

//Prev is used because of DoubleLinked DS. It won't affect other DS that depends on node.next only
template <typename T>
bool BaseStructure<T>::insertAtPosition(T data, int pos){
    // if(!isValidInstanceType()) return false;
    if(pos<=0) return insertAtStart(data);
    if(pos>size) return insertAtEnd(data);
    Node<T>* mRef = getStartNode();
    Node<T>* prevRef;
    int i;
    for (i = 0; i < pos; i++){
        prevRef = mRef;
        mRef = mRef->next;
    }
    Node<T>* nodeToAdd = new Node<T>(data);
    if(!nodeToAdd) return false;
    nodeToAdd->prev = prevRef;
    prevRef->next = nodeToAdd;
    nodeToAdd->next = mRef;
    mRef->prev = nodeToAdd;
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

template <typename T>
bool BaseStructure<T>::contains(T obj){
    if(isEmpty()) return false;
    Node<T>* mRef = getStartNode();
    
    if(mRef->getData() == obj) return true;
    
    Node<T>* startNode = mRef;
    mRef = mRef->getNext();
    while(mRef != NULL && mRef != startNode){
        if(mRef->getData() == obj) return true;
        mRef = mRef->next;
    }
    return false;
}

template <typename T>
T* BaseStructure<T>::toArray(){
    T* array = new T[size];
    Node<T>* mRef = getStartNode();
    for (int i = 0; i < size; i++){
        array[i] = mRef->getData();
        mRef = mRef->next;
    }
    return array;
}

template <typename T>
Node<T>* BaseStructure<T>::getStartNode(){
    return this->head == NULL ? this->tail->next : this->head; //Si la cabeza es nula, usar la cola como cabeza 
}

template <typename T>
void BaseStructure<T>::sort(bool ascending){
    T* mArray = toArray();
    const int mSize = this->size;
    quickSort(mArray, 0, mSize - 1, ascending);
    clear();
    for (int i = 0; i < mSize; i++){
        insertAtEnd(mArray[i]);
    }   
}

template <typename T>
int BaseStructure<T>::find(T data){
    int pos = 0;
    if(isEmpty()) return NOT_FOUND;
    Node<T>* mRef = getStartNode();
    while(mRef != NULL){
        T nodeData = mRef->getData();
        if(nodeData == data) return pos;
        else{
            mRef = mRef->next;
            pos++;
        }
    }
    return NOT_FOUND;
}

template <typename T>
void BaseStructure<T>::getAt(int pos, T &value){
    if(pos<0) pos*= -1;
    if(pos>=size) {
        value = NULL;
        return;
    }
    Node<T>* mRef = getStartNode();
    for (int i = 0; i < pos; i++){
        mRef = mRef->next;
    }
    value = mRef->getData();
}

template <typename T>
bool BaseStructure<T>::modify(const int pos, const T newData){
    if(pos>= size || isEmpty()) return false;
    Node<T>* mRef = getStartNode();
    for (int i = 0; i < pos; i++){
        mRef = mRef->next;
    }
    mRef->setData(newData);
    return true;
}

template <typename T>
bool BaseStructure<T>::modify(const T oldValue, const T newData){
    if(isEmpty()) return false;
    Node<T>* mRef = getStartNode();
    for (int i = 0; i < size; i++){
        if(mRef->mData == oldValue){
            mRef->setData(newData);
            return true;
        }
        mRef = mRef->next;
    }
    return false;
}

/* template <typename T>
bool BaseStructure<T>::isValidInstanceType(){
    type_info ti = typeid(Biqueue<T>);
    return ( typeid(this) != ti );
} */
#endif
