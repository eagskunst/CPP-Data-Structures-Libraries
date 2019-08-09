#ifndef EAGS_PRIORITY_QUEUE
#define EAGS_PRIORITY_QUEUE
#include "DynamicLinealStructure.h"

using namespace std;

template <typename T>
class PriorityQueue {
    private:
        DynamicLinealStructure<int> prioritiesList;
        DynamicLinealStructure<DynamicLinealStructure<T>*> queueList = DynamicLinealStructure<DynamicLinealStructure<T>*>(ListType);
    public:
        PriorityQueue();
        PriorityQueue(int);
        PriorityQueue(int[]);
        bool push(int, T);
        bool pop(T&);
        void print();
        //bool pop(int priority);
        bool isEmpty();
};

template <typename T>
PriorityQueue<T>::PriorityQueue(){

}

template <typename T>
PriorityQueue<T>::PriorityQueue(int startingPriority){
    DynamicLinealStructure<T>* newQueue = new DynamicLinealStructure<T>(QueueType);
    queueList.push(newQueue);
    prioritiesList.push(startingPriority);
}

template <typename T>
PriorityQueue<T>::PriorityQueue(int priorities[]){
    const int n = sizeof(priorities)/sizeof(int);
    DynamicLinealStructure<T>* newQueue;
    for (int i = 0; i < n; i++){
        prioritiesList.push(priorities[i]);
        newQueue = new DynamicLinealStructure<T>(QueueType);
        queueList.push(newQueue);
    }   
}

template <typename T>
bool PriorityQueue<T>::push(const int priority, T data){
    DynamicLinealStructure<T>* newQueue;
    if(!prioritiesList.contains(priority)){
        prioritiesList.push(priority);
        newQueue = new DynamicLinealStructure<T>(QueueType);
        newQueue->push(data);
        queueList.push(newQueue);
        return true;
    }
    const int pos = prioritiesList.find(priority);
    queueList.getAt(pos, newQueue);
    return newQueue->push(data);
}

template <typename T>
bool PriorityQueue<T>::pop(T &data){
    DynamicLinealStructure<T>* newQueue;
    queueList.getAt(0, newQueue);
    if(newQueue == NULL) return false;
    if(newQueue->isEmpty()) return false;
    const bool didPop = newQueue->pop(data);
    if(newQueue->isEmpty()){
        DynamicLinealStructure<T>* temp;
        queueList.pop(temp);
    }
    return didPop;
}

template <typename T>
bool PriorityQueue<T>::isEmpty(){
    return queueList.getSize() == 0;
}

template <typename T>
void PriorityQueue<T>::print(){
    const int count = queueList.getSize();
    DynamicLinealStructure<T>* bufferQueue;
    for (int i = 0; i < count; i++){
        queueList.getAt(i, bufferQueue);
        bufferQueue->print();
    }
    
}

#endif