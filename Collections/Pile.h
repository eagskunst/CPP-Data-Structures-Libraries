#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

template <class T>
class Pile{
	private:

		int size;
		T *v, sValue;
		int counter;

		static enum Errors{
			MEMORY_FAIL = -1,
			NO_SPACE_AVAILABLE = 1;
		}

	public:
		Pile(int size, T sValue);
		int add(T element);
		int remove(T &element);
		int remove(int index);
		void print();

		int checkErrors(){
			//what does !v do? ;-;
			if(!v) return -1;

			//No space available.
			if(counter == size-1) return 1;

			//Nothing wrong.
			return 0;
		}
};

template <class T>
Pile <T>::Pile(int size, T sValue){
	this->size = size;
	counter = -1;
	v = new T[size];

	//what does !v do? ;-;
	if(!v) cout<<"Falla de Memoria"<<endl;
	else {
	    this->sValue = sValue;
	    for ( int i = 0; i < size; i++)
	        v[i] = sValue;
    }
}

template <class T>
int Pile <T>::add(T element){
	int err = checkErrors();
	if(err != 0) return err;
	
	//Add the element and increase the elements counter.
	v[counter+1] = element;
	counter++;
	return 0;
}

template <class T>
int Pile <T>::remove(T &element){
	int err = checkErrors();
	if(err != 0) return err;

	//Remove the element ?
	element = v[counter];
	v[counter] = sValue;
	counter--;
	return 0;
}

template <typename T>
int Pile<T>::remove(int index){
	
}

template <class T>
void Pile <T>::print(){
    cout<<"Pile:\n";
	for(int i = 0; i <= counter; i++)
		cout<<v[i]<<endl;
}
