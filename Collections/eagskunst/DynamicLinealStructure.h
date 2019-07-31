#ifndef DYNAMIC_LINEAL_STRUCTURE
#define DYNAMIC_LINEAL_STRUCTURE
#include <iostream>
#include "BaseStructure.h"

using namespace std;

enum DynamicTypes{
    StackType,
    QueueType,
    ListType
};

template <typename T>
class DynamicLinealStructure: public BaseStructure<T> {
    private:
        DynamicTypes structureType;
        bool pushIfEmpty(T data);
        /*Override BaseStructure methods not needed */
        bool insertAtEnd(T data){return false;}
        bool insertAtPosition(T data, int pos);
        bool insertAtStart(T data){return false;}
        bool deleteAtEnd(){return false;}
        bool deleteAtStart(){return false;}
        bool deleteElement(T data){return false;}
    public:
        DynamicLinealStructure(DynamicTypes);
        bool push(T data);
        bool pop(T &element);
        DynamicTypes getStructureType();
        ~DynamicLinealStructure();
};

template <typename T>
DynamicLinealStructure<T>::DynamicLinealStructure(DynamicTypes sType):BaseStructure<T>(){
    this->structureType = sType;
}

template <typename T>
bool DynamicLinealStructure<T>::pushIfEmpty(T data){
    Node<T>* nNode = new Node<T>(data);
    if(!nNode) return false;
    this->head = nNode;
    this->size++;
    return true;
}

template <typename T>
bool DynamicLinealStructure<T>::push(T data){
    if(this->isEmpty()) return pushIfEmpty(data);
    switch(structureType){
        case ListType:
        case QueueType: {
            Node<T>* nNode = new Node<T>(data);
            if(!nNode) return false;
            if(this->size == 1){
                this->tail = nNode;
                this->head->next = this->tail;
            }
            else{
                this->tail->next = nNode;
                this->tail = nNode;
            }
            this->size++;
            return true;
            break;
        }
        case StackType: {
            Node<T>* nNode = new Node<T>(data);
            if(!nNode) return false;
            if(this->size == 1){
                this->tail = this->head;
            }

            nNode->next = this->head;
            this->head = nNode;
            
            this->size++;
            return true;
            break;
        }
        default: return false;
        break;
    }
    return false;
}

template <typename T>
bool DynamicLinealStructure<T>::insertAtPosition(T data, int pos){
    if(structureType == ListType) return this->insertAtPosition(data, pos);
    cout<<"La Cola/Pila no permite insertar en una posicion especifica.";
    return false;
}

template <typename T>
bool DynamicLinealStructure<T>::pop(T &element){
    if(this->isEmpty()) {
        element = NULL;
        return false;
    }
    switch(structureType){
        case ListType:
        case StackType:
        case QueueType: {
            Node<T>* mHead = this->head;
            element = mHead->getData();
            this->head = mHead->next;
            delete mHead;//OJO
            this->size--;
            return true;
            break;
        }
        default: return false;
        break;
    }
    return false;
}

template <typename T>
DynamicLinealStructure<T>::~DynamicLinealStructure(){

}

template <typename T>
DynamicTypes DynamicLinealStructure<T>::getStructureType(){
    return this->structureType;
}


#endif