#ifndef HASHSEARCH_H
#define HASHSEARH_H
#include <stdlib.h>
#include <time.h>
#include <iostream>
#define LIB -1 //Posicion libre
#define BASE 97 // Posicion de inicio de la zona de colision

using namespace std;

class HashSearch{
    private:
    int randNumber = -1;
    int *v;
    int hashPlegamiento(int clave){
        int i, aux;
        do{
            i = 1;
            aux = 0;
            while(clave >= 1){
                aux += (clave%10 + clave/10%10)%10 * i;
                clave /= 100;
                i *=10;
            }
            clave = aux;
        }while(aux >=100);

        return aux;
    }

    int resolverColision(int hash, int n, int ban = 0){
        int i = BASE;
        int pos = -1;
        int E[2] = {LIB, hash};

        do{
            if( v[i%n] == E[ban]){
                if(ban == 0){
                    v[i%n] = hash;
                }
                pos = i%n;
            }
            i++;
        }while( pos == -1 && i%n != BASE);
        return pos;
    }

    void agregarHash(int hash, int n){
        int i = hashPlegamiento(hash);
        if(v[i] == LIB){
            v[i] = hash;
        }
        else{
            resolverColision(hash, n);
        }
    }
    public:
    HashSearch(){
        srand(time(NULL));
        randNumber = rand() % 200;
        while(randNumber == 0){
            randNumber = rand() % 200;
        }
    }

    void generateIntArray(int n){
        if(randNumber == -1) {
            return;
        }
        v = new int[n];
        for (int i = 0; i < n; i++){
            v[i] = LIB;
        }

        for (int i = 0; i < n; i++){
            int val = i == 0 ? randNumber + 1 : randNumber * i;
            agregarHash(val, n);
        }

        cout<<"Para el array generado, estos son sus hashes: "<<endl;

        for (int i = 0; i < n; i++){
            cout<<v[i]<<endl;
        }
        
        
    }

    int localizarHash(int hash, int n){
        int i = hashPlegamiento(hash);
        if(v[i] == hash){
            return i;
        }
        else{
            return resolverColision(hash, n, 1);
        }
    }

    ~HashSearch(){}
};

#endif