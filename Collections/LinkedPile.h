#ifndef LINKEDPILE_H
#define LINKEDPILE_H

#include "Collections/LinkedBase.h"

template <typename T>
class LinkedPile: LinkedBase<T>{
    public:
        LinkedPile(): LinkedBase<T>(){};
        LinkedPile(T data): LinkedBase<T>(data){};
};

#endif // LINKEDPILE_H
