#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include "Collections/Node.h"

template <typename T>
class LinkedList{
    public:
        LinkedList(){ init(); }
        LinkedList(T first){ init(new Node<T>(first) ); }
        LinkedList(Node<T> *first){ init(first); }

        Node<T>* getFirst(){ return first; }
        Node<T>* getLast() { return last;  }
        int getSize(){ return size; }

        friend ostream& operator<<(ostream &os, const LinkedList<T> &l){
            Node<T> *n = l.first;
            while(n){
                n->print();
                n = n->next();
            }
            return os;
        }

        void push(const T);
        void push(const T, const int);
        void pushBack(const T);

        Node<T>* getNode(const int);
        T get(const int index){ return getNode(index)->getData(); }

        Node<T>* findNode(const T, Node<T> **previous = NULL);
        Node<T>* findNode(const Node<T> *n, Node<T> **previous = NULL){ return findNode(n->getData(), previous); }

        void concat(const List<T>&);
        void del(const T);
        void delAll();

    protected:

    private:
        int size;
        Node<T> *first, *last;

        void init(Node<T> *first = NULL);
};

template <typename T>
void LinkedList<T>::init(Node<T> *first){
    size = 0;
    this->first = first;
    last = NULL;
}

template <typename T>
void LinkedList<T>::push(const T element){
    Node<T> *n = new Node<T>(element);

    //If the list is not empty
    //the new node will point to the first element of the list.
    if(first) n->setNext(first);

    //Push the new node as the first element.
    first = n;
    size++;
}

template <typename T>
void LinkedList<T>::push(const T element, const int index){
    //Validate the index.
    if(index < 0 || index > size) return;

    if(index == 0){
        push(element);
        return;
    }

    //The new node to push in the list.
    Node<T> *newNode = new Node<T>(element);

    //If the list is not empty.
    if(first){
        //Pointer to the previous node to be pushed.
        Node<T> *prev = new Node<T>();
        //Pointer to the node which is going to be pushed.
        Node<T> *n = first;
        for(int i = 0; i < index; i++){
            prev = n;
            n = n->next();
        }

        //The prevous node will point to the newly created node.
        prev->setNext(newNode);
        //Push the new node in between the previous and the actual node 'n'.
        newNode->setNext(n);
    }else first = newNode;
    size++;
}

template <typename T>
void LinkedList<T>::pushBack(const T element){
    Node<T> *n = new Node<T>(element);

    //If the list is not empty.
    if(first){
        last->setNext(n);
        last = n;
    }
    else first = last = n;
    size++;
}

template <typename T>
Node<T>* LinkedList<T>::getNode(const int index){
    if(index < 0 || index >= size) return NULL;

    Node<T> *n = first;
    for(int i = 0; i < index; i++)
        n = n->next();
    return n;
}

template <typename T>
Node<T>* LinkedList<T>::findNode(const T element, Node<T> **previous){
    Node<T> *node = first;

    while(node){
        if(element == node->getData()) return node;
        if(previous) *previous = node;
        node = node->next();
    }

    return NULL;
}

template <typename T>
void LinkedList<T>::concat(const List<T> &other){
    //Retrieve the first node of the list to concatenate.
    Node<T> *node = other.getFirst();

    //Add each node at the end of this list.
    while(node){
        pushBack( node->getData() );
        node = node->next();
    }

}

template <typename T>
void LinkedList<T>::del(const T element){

    if(first->getData() == element){
         first = first->next();
         size--;
    }

    size_t i = 0;
    Node<T> *n1 = first;
    Node<T> *n2 = first->next();
    while(n2){
        if(n2->getData() == element){
            while(n2 && (n2->next()->getData() == element) ){
                n2 = n2->next();
                size--;
            }
            n1->setNext(n2->next()?
                            n2->next():
                            NULL
            );
            i++;
            size--;
        }
        n1 = n1->next();
        if(n2) n2 = n2->next();

    }
    if(i == 0) std::cerr<<"Element not found."<<std::endl;
}

template <typename T>
void LinkedList<T>::delAll(){
    first->destroy();
    first = NULL;
}
#endif // LINKEDLIST_H
