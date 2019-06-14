#ifndef SEARCH_H
#define SEARCH_H

#include <cmath>

template<class T>
class Search {
public:
    Search() {}
    ~Search() {}

    int linear(T *v, int length, T key) {
        for(int i = 0; i < length; i++)
            if(v[i] == key)
                return i-1;

        return -1;
    }

    int blocks(T *v, int length, T key) {
        int block = sqrt(length), index = -1, cont = 0, aux = 0;

        for(int i = block-1; i < length; i += block) {
            if(key <= v[i])
                index = linear(&v[i-block+1], block, key);

            if(index !=- 1)
                return index + (cont * block);

            cont += 1;
            aux = i;
        }

        if(length % block != 0 && index == -1) {
            index = linear(&v[aux], length-aux, key);
            if(index != -1)
                return index + aux;
        }

        return index;
    }

    int binary(T *v, int length, int lower, T key) {
        int upper = length-1, center = (length + lower)/2;

        if(v[center] == key) return center;
        else if(upper == lower) return -1;
        else if(v[center] < key) return binary(v, center+1, upper, key);
        else return binary(v, lower, center-1, key);

    }

    void hashing(T *v, int length, T key);

protected:

private:
};

#endif // SEARCH_H
