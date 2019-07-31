#ifndef LINKEDPILE_H
#define LINKEDPILE_H

#include "Collections/LinkedBase.h"

template <class T>
class LinkedPile: public LinkedBase<T>{
    public:
        LinkedPile(): LinkedBase<T>(){}
        LinkedPile(T data): LinkedBase<T>(data){}

        int add(const T data){ return LinkedBase<T>::pushBack(data); }
        int remove(T&);
        void clear(){ LinkedBase<T>::clear(); }

    private:
        //Grant acces over parent's class attributes.
        using LinkedBase<T>::head;
        using LinkedBase<T>::tail;
        using LinkedBase<T>::length;
};

template <typename T>
int LinkedPile<T>::remove(T &buffer){
    if(length == 0) return -1;

    if(length == 1){
        buffer = head->getData();
        this->clear();

        LinkedBase<T>::linkSentinels();
    }else{
        //Unlink the tail node from the pile.
        tail->prev()->setNext(head);
        head->setPrev(tail->prev());

        buffer = tail->getData();
        tail = tail->prev();
    }

    return length--;
}

#endif // LINKEDPILE_H
