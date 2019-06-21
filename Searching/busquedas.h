#ifndef BUSQUEDAS_H
#define BUSQUEDAS_H
#include <cmath>

template <class T>
int busquedaSecuencial(T list[], int lenght, T input){
    for (int i = 0; i < lenght; i++){
        if(list[i] == input){
            return i;
        }
    }
    return -1;
}

template <class T>
int busquedaBinaria(T list[], T input, int low, int high){
    if(high >= low){
        int medio = (low + (high - 1) ) / 2;
        if(list[medio] == input) return medio;
        if(list[medio]>input) return busquedaBinaria(list, input, low, medio-1);
        return busquedaBinaria(list, input, medio+1, high);
    }
    return -1;
}

template <class T>
int busquedaPorBloques(T list[], int lenght, T input){
    int pos = 0;
    int increment = sqrt(lenght);

    doSearch:
    for (int i = pos; i < lenght ; i+=increment){
        if(list[i] == input){
            return i;
        }
    }
    pos++;

    if(pos < ((lenght - 1)/2) - 1){
        goto doSearch;
    }
    return -1;
}

#endif
