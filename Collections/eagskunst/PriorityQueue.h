#ifndef EAGS_PRIORITY_QUEUE
#define EAGS_PRIORITY_QUEUE
#include "DynamicLinealStructure.h"

using namespace std;

template <typename T>
class PriorityQueue : BaseStructure<DynamicLinealStructure<T>> {
    private:
        DynamicLinealStructure<int> prioritiesList;
        /*Override BaseStructure methods not needed */
        bool insertAtEnd(T data){return false;}
        bool insertAtPosition(T data, int pos);
        bool insertAtStart(T data){return false;}
        bool deleteAtEnd(){return false;}
        bool deleteAtStart(){return false;}
        bool deleteElement(T data){return false;}
    public:
        PriorityQueue();
        PriorityQueue(int);
        bool add(int priority, T data);
        bool addPriority(int);
        bool pop(int priority);
        PriorityQueue(int[]);
};

template <typename T>
PriorityQueue<T>::PriorityQueue() : BaseStructure<DynamicLinealStructure<T>>(){
    prioritiesList(ListType);
    DynamicLinealStructure<T> queue(QueueType);
    Node<T>* newQueue = new Node<DynamicLinealStructure<T>>(queue);
    this->head = newQueue;
    prioritiesList.push(0);
}

template <typename T>
PriorityQueue<T>::PriorityQueue(int startingPriority) : BaseStructure<DynamicLinealStructure<T>>(){
    prioritiesList(ListType);
    DynamicLinealStructure<T> queue(QueueType);
    Node<T>* newQueue = new Node<DynamicLinealStructure<T>>(queue);
    this->head = newQueue;
    prioritiesList.push(startingPriority);
}

template <typename T>
PriorityQueue<T>::PriorityQueue(int priorities[]) : BaseStructure<DynamicLinealStructure<T>>(){
    queueList(ListType);
    prioritiesList(ListType);
    const int n = sizeof(priorities)/sizeof(int);
    Node<T>* newQueue;
    for (int i = 0; i < n; i++){
        DynamicLinealStructure<T> queue(QueueType);
        newQueue = new Node<DynamicLinealStructure<T>>(queue);
        if(i == 0) this->head = newQueue;
        newQueue = newQueue->next;
        prioritiesList.push(priorities[i]);
    }
}

#endif