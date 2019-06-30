#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class Node{
    public:
        Node() { init( T() ); }
        Node(T data){ init(data); }
        Node(T data, Node *__next){ init(data, __next); }
        ~Node(){}

        T getData(){ return data; }
        Node* next() const { return __next; }
        void setData(const T data){ this->data = data; }
        void setNext(Node<T> *node){ __next = node;}
        void destroy(){
            if(__next) delete __next;
            delete this;
        }

        friend bool operator<(const Node<T> &a, const Node<T> &b){ return a.data < b.data; }
        friend bool operator>(const Node<T> &a, const Node<T> &b){ return !(a < b); }

        //FIXME: not working over dinamic instances.
        friend ostream& operator<<(ostream &os, const Node &n){
            std::cout<<n->data<<std::endl;
            return os;
        }

        void print(){ std::cout<<data<<std::endl; }

    protected:

    private:
        T data;
        Node *__next = NULL;

        void init(T data, Node *__next = NULL);
};

template <typename T>
void Node<T>::init(T data, Node *__next){
    this->data = data;
    this->__next = __next;
}
#endif // NODE_H
