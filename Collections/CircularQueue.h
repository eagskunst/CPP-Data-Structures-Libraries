#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
class CircularQueue{
    private:
        T* queue;
        int size;
        int front;
        int back;
    public:
        CircularQueue(int size);
        void add(T buffer);
        void remove(T &buffer);
        void print();
};

template <typename T>
CircularQueue<T>::CircularQueue(int size):size(size),front(-1),back(-1){
    this->queue = new T[size];
    if(!queue) std::cout<<"Fallo al asignar memoria.";
}

template <typename T>
void CircularQueue<T>::add(T buffer){
    /*Revisa si el frente esta al comienzo y el ultimo elemento esta al final de la cola 
    o si el ultimo element + 1 es igual al frente, lo que indica que la cola ya esta llena */
    if( (front == 0 && back == size - 1) || (back+1) == front){ 
        cout<<"La cola esta llena"<<'\n';
        return;
    }

    //Si la cola ya va a llegar a la ultima posicion y no esta llena, la ultima posicion cambia
    if(back == size - 1) back = -1;

    back++;
    this->queue[back] = buffer;
    if(front == -1) front++; 
}

template <typename T>
void CircularQueue<T>::remove(T &buffer){
    if(front == -1){
        cout<<"La cola esta vacia"<<'\n';        
    }

    buffer = this->queue[front];
    
    if(front == back){ //Si se va a eliminar el ultimo elemento de la cola, reiniciarla para que este vacia 
        front = back = -1;
    }
    else if(front == size-1){ //Si el frente va a alcanzar el tamaño maximo, pasarlo al comienzo (circulo)
        front = 0;
    }
    else{
        front++;
    }
}

template <typename T>
void CircularQueue<T>::print(){
    int mFront = front;
    int mBack = back;

    if(mFront<mBack){
        for (int i = mFront; i <= mBack && i<size; i++){
            cout<<queue[i]<<endl;
        }
    }
    else{
        for (int i = mFront; i < size; i++){
            cout<<queue[i]<<endl;
            if(i+1 == size){
                i = 0;
            }
            if(i == mBack) break;
        }
    }
    
}

#endif