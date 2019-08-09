//Archivo para correr código y testear las clases
#include <iostream>
#include "FilesHandler\Archivo.h"
#include "Custom Classes\Persona.h"
#include "Custom Classes/Str.h"
#include "Searching/busquedas.h"
#include "Searching/HashSearch.h"
#include "Collections/eagskunst/CircularQueue.h"
#include "Collections/eagskunst/Stack.h"
#include "Collections/eagskunst/Biqueue.h"
#include "Collections/eagskunst/LinkedList.h"
#include "Collections/eagskunst/CircularLinkedList.h"
#include "Collections/eagskunst/DoubleLinkedList.h"
#include "Collections/eagskunst/DynamicLinealStructure.h"
#include "Collections/eagskunst/PriorityQueue.h"
using namespace std;

int main(int argc, char const *argv[]){
    PriorityQueue<int> queues;
    queues.push(0, 3);
    queues.push(0, 4);
    queues.push(1, 6);
    queues.push(0, -20);
    queues.push(2, 1);
    queues.push(1, 22);
    cout<<"Print:"<<endl;
    queues.print();
    cout<<"Pop:"<<endl;
    while(!queues.isEmpty()){
        int num;
        queues.pop(num);
        cout<<num<<endl;
    }
    return 0;
}

