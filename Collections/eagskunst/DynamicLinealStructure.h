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
        bool insertAtEnd(T data){return false;}
        bool insertAtPosition(T data, int pos);
        bool insertAtStart(T data){return false;}
        bool deleteAtEnd(){return false;}
        bool deleteAtStart(){return false;}
        bool deleteElement(T data){return false;}
    public:
        DynamicLinealStructure(DynamicTypes);
        ~DynamicLinealStructure();
};

template <typename T>
DynamicLinealStructure<T>::DynamicLinealStructure(DynamicTypes sType):BaseStructure<T>(){

}

template <typename T>
DynamicLinealStructure<T>::~DynamicLinealStructure(){

}




#endif