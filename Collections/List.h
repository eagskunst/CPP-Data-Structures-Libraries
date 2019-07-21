#ifndef LIST_H

#if false
#if __cplusplus <= 199711L
    #error This library needs at least a C++11 compliant compiler
#else  define LIST_H
#endif // __cplusplus
#endif // false

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

        //Base class methods.
        using Collection<T>::isFull;
        using Collection<T>::print;

    protected:

    private:
        //Grant access over base class template's members.
        //Base attributes.
        using Collection<T>::v;
        using Collection<T>::sValue;
        using Collection<T>::length;
        using Collection<T>::numElements;

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
        std::cerr<<"Lista llena."<<std::endl;
        return MEMORY_FULL;
    }

    v[numElements] = element;
    numElements++;
    return SUCCESS;
}

template <typename T>
T List<T>::get(int index){
    if(index > numElements || index < 0){
        std::cerr<<"Indice invalido."<<std::endl;
        return NULL;//INDEX_OUT_OF_BOUNDS;
    }

    return v[index];
}

template <typename T>
int List<T>::find(const T element){
    for(int i = 0; i < numElements; i++)
        if(v[i] == element)
            return i;

    std::cerr<<"Elemento no encontrado."<<std::endl;
    return ELEMENT_NOT_FOUND;
}

template <typename T>
int List<T>::remove(){
    if(numElements > 0 || numElements <= length){
        v[numElements] = sValue;
        numElements--;
        return SUCCESS;

    std::cerr<<v[numElements]<<std::endl;
    }
    std::cerr<<"Lista vacia."<<std::endl;
    return MEMORY_EMPTY;
}

template <typename T>
int List<T>::remove(int index){
    //TODO: handle acces over arbitrary poitions.
    std::cerr<<"Operacion no valida."<<std::endl;
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
    std::cerr<<"Operacion no valida."<<std::endl;
    return UNSUPPORTED_OPERATION;

    return remove(find(element));
}*/

#endif // LIST_H
