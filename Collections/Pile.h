#include <iostream>
#include <string.h>
#include <conio.h>

#include "Searching/Search.h"

using namespace std;

//TODO: implement inheritance from Collection.
template <class T>
class Pile{
    public:
		Pile(int size, T sValue);
		//FIXME: not properly copying elements from input.
		Pile(T *v, int size);

        int add(T element);
		//FIXME: not properly copying elements from input.
        int add(T *elements);
		int get(T &buffer);
		T get();
		int find(const T element);
		void print();

		int checkErrors();

    protected:

    private:
		int size;
		T *v, sValue;
		int top;

		void init(int size);
};

template <typename T>
void Pile<T>::init(int size){
    this->size = size;
	top = -1;
	v = new T[size];
}

template <typename T>
Pile<T>::Pile(T *v, int size){
    if(!v){
        cout<<"Falla de Memoria"<<endl;
        return;
    }

    init(size);
    this->sValue = v[0];
    top = size;
    for(int i = 0; i < size; i++)
        this->v[i] = v[i];

}

template <class T>
Pile <T>::Pile(int size, T sValue){
	init(size);

	if(!v) cout<<"Falla de Memoria"<<endl;
	else {
	    this->sValue = sValue;
	    for ( int i = 0; i < size; i++)
	        v[i] = sValue;
    }
}

template<typename T>
int Pile<T>::checkErrors(){
    // v is of type T*, i.e. v can be NULL
    // NULL = 0 = false.
    if(!v) {
        cout<<"Falla de Memoria"<<endl;
        return -1;
    }

    //No space available.
    if(top == size-1){
        cout<<"Pila llena."<<endl;
        return -10;
    }

    //Nothing wrong.
    return 0;
}

template <class T>
int Pile<T>::add(T element){
	int err = checkErrors();
	if(err != 0) return err;

	//Add the element and increase the elements counter 'top'.
	v[top+1] = element;
	top++;
	return 0;
}

template <typename T>
int Pile<T>::add(T *elements){
    int err = checkErrors();
	if(err != 0) return err;

	int length = sizeof(elements)/sizeof(elements[0]);
	if(length > size){
        cout<<"No hay espacio suficiente en la pila."<<endl;
        return -10;
	}

	for(int i = 0; i < length ; i++)
        add(elements[i]);
    return 0;
}

template <class T>
int Pile <T>::get(T &buffer){
	int err = checkErrors();
	if(err != 0) return err;

	if(top > -1){
        //Copy the most recent element into the buffer and remove it from the pile.
        buffer = v[top];
        v[top] = sValue;
        top--;
	}else buffer = sValue;
	return 0;
}

template <typename T>
T Pile<T>::get(){
    T t;
    get(t);
    return t;
}

template <typename T>
int Pile<T>::find(const T element){
    int err = checkErrors();
    if(err != 0) return err;
    return Search<T>::linear(v, size, element);
}

template <class T>
void Pile <T>::print(){
    cout<<"Pile:\n";
	for(int i = 0; i <= top; i++)
		cout<<v[i]<<endl;
}
