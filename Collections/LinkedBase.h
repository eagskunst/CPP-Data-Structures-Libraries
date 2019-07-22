#ifndef LINKEDBASE_H
#define LINKEDBASE_H

#include <iostream>
#include "Collections/Node.h"

template <class T>
class LinkedBase{
    public:
        typedef Node<T>* NodePointer;

        LinkedBase(){ init(new Node<T>, 0); }
        LinkedBase(T data){ init(new Node<T>(data), 1); }

        int getLength(){ return length; }

        friend std::ostream& operator<<(std::ostream &os, const LinkedBase<T> &l){
            NodePointer n = l.head;
            do{
                try{ os<<n<<std::endl; }
                catch(...){ return os; }
                n = n->next();
            }while(n != l.head );
            return os;
        }

        friend LinkedBase<T>& operator+=(LinkedBase<T> &a, const LinkedBase<T> &b){
            //Retrieve the first node of the list to concatenate.
            NodePointer node = b.head;

            //Add each node at the end of this list.
            do{
                a.pushBack( node->getData() );
                node = node->next();
            }while(node != b.head);

            return a;
        }

    protected:

        /** @brief Appends a new element at the tail is this collection.
         *
         * @param The data to be added into the list.
         * @return the length of this collection if succeed, -1 otherwise.
         *
         */
        int pushBack(const T);

        /** @brief Removes every element in this collections */
        void clear();

        virtual int remove(T&) = 0;

        void linkSentinels();

        NodePointer head, tail;
        size_t length;

    private:
        void init(NodePointer, int);
};

template <typename T>
void LinkedBase<T>::init(NodePointer h, int l){
    head = h;
    length = l;
    tail = new Node<T>();

    linkSentinels();
}

template <typename T>
int LinkedBase<T>::pushBack(const T data){
    NodePointer n = new Node<T>(data);

    //Check for memory errors.
    if(!n) return -1;

    //If the list is not empty.
    if(length != 0){
        //Link the new node with the tail.
        tail->setNext(n);
        n->setPrev(tail);

        //Link the new node with the head.
        n->setNext(head);
        head->setPrev(n);

        //Set the new node as the tail.
        tail = n;
    }else{
        head = tail = n;
        this->linkSentinels();
    }

    return length++;
}

template <typename T>
void LinkedBase<T>::clear(){
    head->destroy();
    head = tail = new Node<T>();
}

template <typename T>
void LinkedBase<T>::linkSentinels(){
    //Forward.
    head->setNext(tail);
    tail->setNext(head);

    //Backwards.
    head->setPrev(tail);
    tail->setPrev(head);
}

#endif // LINKEDBASE_H
