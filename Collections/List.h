#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Collections/Collection.h"

template <class T>
class List: public Collection<T>{
    public:
        List(int length, T sValue): Collection<T>(length, sValue){}

        int add(T element);
        T get(int index);
        int find(const T element);
        int remove();
        int remove(int index);
        //FIXME: error: 'int Collection<T>::remove(T) [with T = int]' cannot be overloaded
        //int remove(T element);

    protected:

    private:
        //Grant access over base class template's members.
        //Base attributes.
        using Collection<T>::v;
        using Collection<T>::sValue;
        using Collection<T>::length;
        using Collection<T>::numElements;

        //Base methods.
        using Collection<T>::isFull;
        using Collection<T>::print;

        //Base inner 'Errors' enum.
        using Collection<T>::SUCCESS;
        using Collection<T>::MEMORY_FULL;
        using Collection<T>::MEMORY_EMPTY;
        using Collection<T>::MEMORY_ERROR;
        using Collection<T>::ELEMENT_NOT_FOUND;
        using Collection<T>::INDEX_OUT_OF_BOUNDS;
        using Collection<T>::UNSUPPORTED_OPERATION;
};

template <typename T>
int List<T>::add(T element){
    if(isFull() ){
        std::cout<<"Lista llena."<<std::endl;
        return MEMORY_FULL;
    }

    v[numElements] = element;
    numElements++;
    return SUCCESS;
}

template <typename T>
T List<T>::get(int index){
    if(index > numElements || index < 0){
        std::cout<<"Indice invalido."<<std::endl;
        return INDEX_OUT_OF_BOUNDS;
    }

    return v[index];
}

template <typename T>
int List<T>::find(const T element){
    for(int i = 0; i < numElements; i++)
        if(v[i] == element)
            return i;

    std::cout<<"Elemento no encontrado."<<std::endl;
    return ELEMENT_NOT_FOUND;
}

template <typename T>
int List<T>::remove(){
    if(numElements > 0){
        v[numElements] = sValue;
        numElements--;
        return SUCCESS;
    }
    std::cout<<"Lista vacia."<<std::endl;
    return MEMORY_EMPTY;
}

template <typename T>
int List<T>::remove(int index){
    //TODO: handle acces over arbitrary poitions.
    std::cout<<"Operacion no valida."<<std::endl;
    return UNSUPPORTED_OPERATION;

    if(index > numElements || index < 0){
        std::cout<<"Indice invalido."<<std::endl;
        return INDEX_OUT_OF_BOUNDS;
    }

    //Will cause memory lost due arbitraty position operations.
    v[index] = sValue;
    numElements--;
    return SUCCESS;
}

//FIXME: error: 'int Collection<T>::remove(T) [with T = int]' cannot be overloaded
/*template <typename T>
int List<T>::remove(T element){
    //TODO: handle acces over arbitrary poitions.
    std::cout<<"Operacion no valida."<<std::endl;
    return UNSUPPORTED_OPERATION;

    return remove(find(element));
}*/
#endif // LIST_H
