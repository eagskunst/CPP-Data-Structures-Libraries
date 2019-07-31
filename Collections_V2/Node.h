#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <class T>
class Node{
    public:
        //WARNING: delegating constructors only available with -std=c++11 or -std=gnu++11
        Node(){ init(T(), NULL, NULL); }
        Node(T data){ init(data, NULL, NULL); }
        Node(T data, Node *__next){ init(data, __next, NULL); }
        Node(T data, Node<T> *__next, Node<T> *__prev){ init(data, __next, __prev); }
        ~Node(){}

        T getData(){ return data; }
        Node<T>* next(){ return __next; }
        Node<T>* prev(){ return __prev; }
        void setData(const T data){ this->data = data; }
        void setNext(Node<T> *node){ __next = node; }
        void setPrev(Node<T> *node){ __prev = node; }
        void destroy(){
            if(__next != this) __next->destroy();
            if(__prev != this) __prev->destroy();
            delete this;
        }

        friend bool operator< (const Node<T> &a, const Node<T> &b){ return a.data < b.data;  }
        friend bool operator> (const Node<T> &a, const Node<T> &b){ return !(a < b);  }
        friend bool operator==(const Node<T> &a, const Node<T> &b){ return a.data == b.data; }
        friend bool operator!=(const Node<T> &a, const Node<T> &b){ return !(a == b); }
        friend bool operator<=(const Node<T> &a, const Node<T> &b){ return a.data <= b.data; }
        friend bool operator>=(const Node<T> &a, const Node<T> &b){ return !(a <= b); }

        //For dinamic instances.
        friend ostream& operator<<(ostream &os, Node<T> *n){ return os<<*n; }

        //For static instances.
        friend ostream& operator<<(ostream &os, const Node<T> &n){ return os<<n.data; }

    protected:

    private:
        T data;
        Node<T> *__next = NULL;
        Node<T> *__prev = NULL;

        void init(T, Node<T>*, Node<T>*);
};

template <typename T>
void Node<T>::init(T data, Node<T> *__next, Node<T> *__prev){
    this->data = data;
    this->__next = __next;
    this->__prev = __prev;
}
#endif // NODE_H
