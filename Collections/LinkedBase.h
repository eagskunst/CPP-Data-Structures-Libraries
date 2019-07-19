#ifndef LINKEDBASE_H
#define LINKEDBASE_H

#include <iostream>
#include "Collections/Node.h"

template <class T>
class LinkedBase{
    public:
        typedef Node<T>* NodePointer;

        LinkedBase(){ init(NULL, 0); }
        LinkedBase(T data){ init(new Node<T>(data), 1); }

        int getLength(){ return length; }
        NodePointer getHead(){ return head; }
        NodePointer getTail(){ return tail; }
    protected:

        /** @brief Appends a new element at the head of the collection.
         *
         * @param The data to be added into the list.
         * @return the length of this collection if succeed. -1 otherwise.
         *
         */
        int push(const T);

        /** @brief Inserts a new element at the provided index of the collection.
         * If the provided index is greather than the length of this collection,
         * the new element is added at the tail.
         * In the same way, if the index is lesser than zero
         * the new element is added at the head of this collection.
         *
         * @param The data to be added into the list.
         * @param The index where the data will be added.
         * @return the length of this collection if succeed. -1 otherwise.
         *
         */
        int push(const T, const int);

        /** @brief Appends a new element at the tail is this collection.
         *
         * @param The data to be added into the list.
         * @return the length of this collection if succeed. -1 otherwise.
         *
         */
        int pushBack(const T);

        int append(const LinkedBase<T>&);
        int remove(const T);
        void clear();

        virtual int remove(const T&) = 0;

        NodePointer getNode(const int);
        T get(const int index){ this->getNode(index)->getData(); }

        NodePointer findNode(const T, NodePointer *previous = NULL);
        NodePointer findNode(const NodePointer n, NodePointer *previous = NULL){ return findNode(n->getData(), previous); }

        friend std::ostream& operator<<(std::ostream &os, const LinkedBase<T> &l){
            NodePointer n = l.head;
            do{
                os<<n;
                n->next();
            }while(n != l.head );
            delete n;
            return os;
        }

    private:
        NodePointer head, tail;
        int length;

        void init(NodePointer, int);
};

template <typename T>
void LinkedBase<T>::init(NodePointer h, int l){
    head = h;
    length = l;
    tail = NULL;
}

template <typename T>
int LinkedBase<T>::push(const T data){
    NodePointer n = new Node<T>(data);

    //Check memory allocation.
    if(!n) return -1;

    //If the list is not empty
    //the new node will point to both head and tail nodes of this collection.
    if(head){
        n->setNext(head);
        n->setPrev(tail);
    }

    //Push the new node.
    head = n;
    return length++;
}

template <typename T>
int LinkedBase<T>::push(const T data, const int index){
    //Delegate push subroutine if index is out of bounds.
    if(index <= 0) return push(data);
    if(index > length) return pushBack(data);

    //The new node to push into the list.
    NodePointer newNode = new Node<T>(data);

    //Check for memory errors.
    if(!newNode) return -1;

    //If the list is not empty.
    if(head){
        //Pointer to the previous node to be pushed.
        NodePointer prev = tail;
        //Pointer to the node which is going to be pushed.
        NodePointer n = head;

        //Iterate through the collection until index is reached.
        for(int i = 0; i < index; i++){
            prev = n;
            n = n->next();
        }

        //Link the new node with the previous one.
        prev->setNext(newNode);
        newNode->setPrev(prev);

        //Link the new node with the immediate next.
        newNode->setNext(n);
        n->setPrev(newNode);

    }else head = newNode;

    return length++;
}

template <typename T>
int LinkedBase<T>::pushBack(const T data){
    NodePointer n = new Node<T>(data);

    //Check for memory errors.
    if(!n) return -1;

    //If the list is not empty.
    if(head){
        //Link the new node with the tail.
        tail->setNext(n);
        n->setPrev(tail);

        //Set the new node as the tail.
        tail = n;
    }else head = n;

    return length++;
}

template <typename T>
int LinkedBase<T>::append(const LinkedBase<T> &other){
    //Retrieve the first node of the list to concatenate.
    NodePointer node = other.getHead();

    if(!node) return -1;

    //Add each node at the end of this list.
    do{
        pushBack( node->getData() );
        node = node->next();
    }while(node != other.getHead() );

    return length;
}

template <typename T>
int LinkedBase<T>::remove(const T data){

    if(head->getData() == data){
        //delete first;
        head = head->next();
        length--;
    }

    NodePointer n1 = head;
    NodePointer n2 = head->next();
    while(n2){
        if(n2->getData() == data){
            while(n2->next()->getData() == data){
                n2 = n2->next();
                length--;
            }
            n1->setNext( n2->next() );
            length--;
        }
        n1 = n1->next();
        if(n2) n2 = n2->next();

    }
    return length;
}

template <typename T>
void LinkedBase<T>::clear(){
    head->destroy();
    head = NULL;
}

#endif // LINKEDBASE_H
