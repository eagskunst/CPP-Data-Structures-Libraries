#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>

template <class T>
class Collection{
    public:
        Collection(){ init(0, T() ); } //Not sure if T() works over raw data types or arrays.
        Collection(int length, T sValue){ init(length, sValue); }
        ~Collection(){ }

        virtual int add(T element);
        virtual T get(int index);
        virtual int find(T element);
        virtual int remove();

        //Collection.h|51|error: initializer fails to determine size of 'aux'
        /*void extend(int n, T value);
        void extend(int n){ extend(n, sValue); }*/

        void print(){
            for(int i = 0; i < length; i++)
                std::cout<<v[i]<<std::endl;
        }

        protected:

        private:
            int length;
            T sValue;
            T *v;

            void init(int length, T sValue);
};

template <typename T>
void Collection<T>::init(int length, T sValue){
    this -> length = length;
    this -> sValue = sValue;

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
