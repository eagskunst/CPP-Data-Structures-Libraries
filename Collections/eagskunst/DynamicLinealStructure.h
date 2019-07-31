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
    return true;
}

template <typename T>
bool DynamicLinealStructure<T>::push(T data){
    if(this->isEmpty()) return pushIfEmpty(data);
    switch(DynamicLinealStructure){
        case ListType:
        case QueueType: {
            Node<T>* nNode = new Node<T>(data);
            if(!nNode) return false;
            if(this->size == 1){
                this->tail = nNode;
            }
            else{
                this->tail->next = nNode;
                this->tail = nNode;
            }
            this->size++;
            break;
        }
        case StackType: {
            Node<T>* nNode = new Node<T>(data);
            if(!nNode) return false;
            if(this->size == 1){
                this->tail = this->head;
                this->head = nNode;
            }
            else{
                this->head->next = nNode;
                this->head = nNode;
            }
            this->size++;
            break;
        }
    }
}

template <typename T>
bool DynamicLinealStructure<T>::insertAtPosition(T data, int pos){
    if(structureType == List) return this->insertAtPosition(data, pos);
    cout<<"La Cola/Pila no permite insertar en una posicion especifica."
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