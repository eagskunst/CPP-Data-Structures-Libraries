#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include <iostream>
#include <time.h>
using namespace std;

//TODO: Probar con arrays largos

template <class T>
void burbuja(T &a, T &b){
    T aux = a;
    a = b;
    b = aux;
}

template <class T>
void bubbleSort(T list[], int n){
    bool band = true;
    for(int i = 0; i < n-1 && band; i++){
        band = false;
        for(int j = 0; j < n-i-1; j++){
            if(list[j] > list[j+1]){
                burbuja(list[j], list[j+1]);
                band = true;
            }
        }
    }
}

template <class T>
void inserccionDirecta(T list[], int n){
    T current;
    for(int i = 0; i < n; i++){
        current = list[i];
        int j = i-1;
        while(j>=0 && current<list[j]){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = current;
    }
}

template <class T>
void seleccionDirecta(T list[], int n){
    for(int i = 0; i < n-1; i++){
        int aux = i;
        for(int j = i+1; j < n; j++){
            if(list[j]<list[aux]){
                aux = j;
            }
        }
        burbuja(list[aux], list[i]);
    }
}

template <class T>
void shellSort(T list[], int n){
    T current;
    for(int gap = n/2; gap > 0; gap/=2){
        for(int i = gap; i < n; i++){
            current = list[i];
            int j;
            for(j = i; j >= gap && current<list[j-gap]; j-=gap)
            {
                list[j] = list[j-gap];
            }
            list[j] = current;
        }
    }
}

template <class T>
int particion(T list[], int low, int high){
    int i = low-1;
    T pivot;
    T aux;

    pivot = list[high];
    for(int j = low; j < high; j++){
        if(list[j]<pivot){
            i++;
            burbuja(list[i], list[j]);
        }
    }

    aux = list[i+1];
    list[i+1] = list[high];
    list[high] = aux;

    return (i+1);
}

template <class T>
void quickSort(T list[], int low, int high){
    if(low < high){
        int index = particion(list, low, high);
        quickSort(list, low, index-1);
        quickSort(list, index+1, high);
    }
}

template <class T>
void printList(T list[], int n){
    for(int i = 0; i < n; i++)
    {
        cout << list[i]<<" ";
    }
    cout << ""<<endl;
}

double sortDuration(clock_t start){
    clock_t tiempo = clock() - start;
    return tiempo / (double) CLOCKS_PER_SEC;
}

#endif
