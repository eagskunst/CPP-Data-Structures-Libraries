#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>

template <class T>
class Collection{
    public:
        //Collection(){ init(0, T() ); } //Not sure if T() works over raw data types or arrays.
        Collection(int length, T sValue){ init(length, sValue); }
        ~Collection(){ }

        void print(){
            for(int i = 0; i < length; i++)
                std::cout<<v[i]<<std::endl;
        }

        enum Errors{
            SUCCESS = 0,
            MEMORY_FULL = -1,
            MEMORY_EMPTY = -2,
            MEMORY_ERROR = -3,
            ELEMENT_NOT_FOUND = -4,
            INDEX_OUT_OF_BOUNDS = -5,
            UNSUPPORTED_OPERATION = -6
        };

        int getLength(){ return length; }
        int getNumElements(){ return numElements; }
        bool isFull(){ return numElements >= length; }

    protected:
        int length, numElements;
        T *v, sValue;

        int add(T element);
        T get(int numElements);
        int find(const T element);
        int remove();
        int remove(int index);
        //FIXME: error: 'int Collection<T>::remove(T) [with T = int]' cannot be overloaded
        //int remove(T element);

        //FIXME: Collection.h|65|error: initializer fails to determine size of 'aux'
        /*void extend(int n, T value);
        void extend(int n){ extend(n, sValue); }*/

    private:
        void init(int length, T sValue);
};

template <typename T>
void Collection<T>::init(int length, T sValue){
    this -> length = length;
    this -> sValue = sValue;
    numElements = -1;

    v = new T[length];
    for(int i = 0; i < length; i++)
        v[i] = sValue;
}

/*template <typename T>
void Collection::extend(int n, T value){
    T aux[] = new T[length + n];
    for(int i = 0; i < length + n; i++){
        if(i < length) aux[i] = v[i];
        else aux[i] = value;
    }

    v = aux;
    length += n;
}*/

#endif // COLLECTION_H
