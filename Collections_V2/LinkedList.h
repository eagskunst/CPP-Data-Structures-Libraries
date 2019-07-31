#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Collections/Node.h"
#include "Collections/LinkedBase.h"

template <class T>
class LinkedList: public LinkedBase<T>{
    public:
        typedef Node<T>* NodePointer;

        LinkedList(): LinkedBase<T>(){}
        LinkedList(T data): LinkedBase<T>(data){}

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

        int pushBack(const T data){ return LinkedBase<T>::pushBack(data); }
        int remove(const T data);
        int remove(T &data){ return -1; } //TODO: implement.
        void clear(){ LinkedBase<T>::clear(); }

    protected:

    private:
        using LinkedBase<T>::head;
        using LinkedBase<T>::tail;
        using LinkedBase<T>::length;
};

template <typename T>
int LinkedList<T>::push(const T data){
    NodePointer n = new Node<T>(data);

    //Check memory allocation.
    if(!n) return -1;

    if(length != 0){
        //Forward.
        tail->setNext(n);
        n->setNext(head);

        //Backward.
        head->setPrev(n);
        n->setPrev(tail);

        head = n;
    }else{
        head = tail = n;
        this->linkSentinels();
    }

    return length++;
}

template <typename T>
int LinkedList<T>::push(const T data, const int index){
    //Delegate push subroutine if index is out of bounds.
    if(index <= 0) return push(data);
    if(index > length) return pushBack(data);

    //The new node to push into the list.
    NodePointer newNode = new Node<T>(data);

    //Check for memory errors.
    if(!newNode) return -1;

    //Pointer to the previous node to be pushed.
    NodePointer prev = tail;
    //Pointer to the node which is going to be pushed.
    NodePointer n = head;

    //Iterate through the collection until index is reached.
    for(int i = 0; i < index-1; i++){
        prev = n;
        n = n->next();
    }

    //Link the new node with the previous one.
    prev->setNext(newNode);
    newNode->setPrev(prev);

    //Link the new node with the immediate next.
    newNode->setNext(n);
    n->setPrev(newNode);

    return length++;
}

template <typename T>
int LinkedList<T>::remove(const T data){
    if(length == 0) return -1;

    NodePointer n = head;

    do{
        if(n->getData() == data){
            //Unlink the node which contains the data from the list.
            n->prev()->setNext( n->next() );
            n->next()->setPrev( n->prev() );

            //Reassign sentinel nodes if necessary.
            if(n == head) head = n->next();
            else if(n == tail) tail = n->prev();

            //Deallocate memory.
            delete n;

            return length--;
        }

        n = n->next();
    }while(n != head);

    //Element not found.
    return -1;
}

#endif // LINKEDLIST_H
