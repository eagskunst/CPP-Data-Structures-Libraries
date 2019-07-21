#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
private:
    T mData;
    Node<T> *prev;
    Node<T> *next;

public:
    Node(T &data);
    T getData();
    Node<T> *getPrev();
    Node<T> *getNext();
    void setData(T data);
    template<typename> friend class Biqueue;
    template<typename> friend class BaseStructure;
};

template <typename T>
Node<T>::Node(T &data):prev(NULL),next(NULL){
    this->mData = data;
}

template <typename T>
void Node<T>::setData(T data){
    this->mData = data;
}

template <typename T>
T Node<T>::getData(){
    return this->mData;
}

template <typename T>
Node<T>* Node<T>::getPrev(){
    return this->prev;
}

template <typename T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

#endif