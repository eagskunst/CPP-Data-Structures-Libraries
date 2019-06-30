#ifndef LINKEDLIST_V2_H
#define LINKEDLIST_V2_H

#include <iostream>

template <class T>
class Nodo{
    public:
        Nodo(){ data = T(); }
        Nodo(T data){ this->data = data; }
        Nodo(T data, Nodo<T> next){ __next = next; }

        Nodo<T>* next(){ return __next; }
        T getData(){ return data; }

        setNext(Nodo<T> *node){ __next = node; }

    private:
        T data;
        Nodo<T> *__next = NULL;
};



template <class T>
class LinkedList{
    public:
        LinkedList(Nodo<T> *f, Nodo<T> *l){
            first = f;
            last = l;
            size = 0;
        }

        LinkedList(T f, T l){
            first = new Nodo<T>(f);
            //last = new Nodo<T>(l);
            last = first;
            size = 0;
        }

        Nodo<T>* getFirst(){ return first; }
        Nodo<T>* getLast(){ return last; }

        void push(const T element){
            Nodo<T> *node = new Nodo<T>(element);

            if(first) node->setNext(first);

            first = node;
            size++;
        }
    protected:
    private:
        Nodo<T> *first;
        Nodo<T> *last;
        int size;
};





#endif // LINKEDLIST_V2_H
