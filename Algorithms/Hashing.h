#ifndef HASHING_H
#define HASHING_H

#include <iostream>

// NOTE: if type T does not have any getId() method that retrieves 
// an integer representation of itself 
// then this whole class is useless.
class Hashing{
	public:
		Hashing(){
			size = 10, base = 5;
			sValue = NULL;
		}

		Hashing(int size, int base, T sValue){
			this->size = size;
			this->base = base;
			this->sValue = sValue;
		}

		static int moduleHash(int key, int size){ return key%size; }
		static int trunckateHash(int key){ return (key/100%10*10 + key/10000%10); }		
		static int centralDigitsHash(int key){ return ( (key * key) /10000 %100); }
		static int foldingHash(int key, int size){ 
			int i, aux;
			do {
				i = 1; aux = 0;
				while ( key >= 1 ){
					aux += (key % 10 + key/10%10)%10 * i;
					key /= 100;
					i *= 10;
				}
				key = aux;
			} while ( aux >= 100 );
			return aux;
		}

		template <typename T>
		void add(T key, T *v, int &cont, int(*pf)(int) ){
			if(!pf) return;
			int i = pf(key.getId() );

			if(!v[i]) v[i] = key;
			else{
				solveColition(key, v);
				cont++;
			}
		}

		template <typename T>
		int find(T key, T *v, int(*pf)(int) ){
			if(!pf) return -1;

			int i = pf(key.getId() );

			//May replace with if-else statement if necessary.
			return v[i] == key? i: solveColition(key, v , 1);
		}

		template <typename T>
		int solveColition(T key, T *v, int flag = 0){
			int i = size, pos = -1;
			T aux[2] = {sValue, key};

			do{
				if( v[i % size] == aux[flag] ){
					if(!flag)
						v[i % size] = key;
					pos = i % size;
				}	
				i++;		
			}while(pos == -1 && (i % size != base) );

			return pos;
		}

		template <typename T>
		void print(T *v){
			for(int i = 0; i < size; i++)
				std::cout<<v[i]<<std::endl;
		}

	private:
		const int size, int base;
		const T sValue;
}

#endif //HASHING_H