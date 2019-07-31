#ifndef QUEUE_H
#define QUEUE_H

#include "Collections/LinkedBase.h"

template <class T>
class Queue: public LinkedBase<T>{
    public:
        Queue(): LinkedBase<T>(){}
        Queue(T data): LinkedBase<T>(data){}

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
int Queue<T>::remove(T &buffer){
    if(length == 0) return -1;

    if(length == 1){
        buffer = head->getData();
        this->clear();

        LinkedBase<T>::linkSentinels();
    }else{
        head->next()->setPrev(tail);
        tail->setNext( head->next() );

        buffer = head->getData();
        head = head->next();
    }

    return length--;
}

#endif // QUEUE_H
