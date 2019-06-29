#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <typename T>
class Stack{
private:
    T* stack;
    int top;
    int size;
    bool badMemory = false;

public:
    Stack(int size);
    bool add(T buffer);
    bool remove(T &buffer);
    void print();
};

template <typename T>
Stack<T>::Stack(int size):size(size){
    this->top = -1;
    this->stack = new T[size];
    if(!stack){
        this->badMemory = true;
        cout<<"No se pudo reservar memoria"<<endl;
    }
}

template <typename T>
bool Stack<T>::add(T buffer){
    if(this->badMemory)  return false;
    if(this->top == size - 1){
        cout<<"La pila esta llena"<<endl;
        return false;
    }
    this->stack[++top] = buffer;
    return true;
}

template <typename T>
bool Stack<T>::remove(T &buffer){
    if(this->badMemory)  return false;
    if(this->top <= -1){
        cout<<"La pila esta vacia"<<endl;
        return false;
    }
    buffer = this->stack[top--];

    return true;
}
template <typename T>
void Stack<T>::print(){
    if(badMemory)  return;
    if(this->top <= -1){
        cout<<"La pila esta vacia"<<endl;
        return;
    }
    else{
        for (int i = 0; i <= top; i++){
            cout<<stack[i]<<endl;
        }
        
    }
}



#endif