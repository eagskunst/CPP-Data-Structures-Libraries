#ifndef BUSQUEDAS_H
#define BUSQUEDAS_H

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

#endif
