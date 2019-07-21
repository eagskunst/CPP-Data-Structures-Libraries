#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

template <class T>
class Archivo {

    char nombre[40]; //Nombre del archivo
    fstream file; //Handler del archivo
    int N = -1; //Numero de lineas/elementos
    T buffer; //Ultimo elemento leido
    int sizeT; //sizeof del tipo de Objeto


    public:
        Archivo(){
            strcpy(this->nombre, "");
            sizeT = sizeof(T);
        }
        Archivo(char *nombre){
            strcpy(this->nombre, nombre);
            sizeT = sizeof(T);
        }

        void setNombre(char *nombre){
            strcpy(this->nombre, nombre);
        }

        bool abrir(const _Ios_Openmode &openmode){
            file.open(nombre, openmode);
            if(file.fail()){
                return false;
            }
            return true;
        }

        void cerrar(){
            file.close();
        }

        T read(){ //Lee la linea siguiente del archivo y la pasa al buffer
            file.read((char*)&buffer, sizeT);
            return buffer;
        }

        void write(T &a){ //Escribe en la linea en la que este posicionada el archivo
            file.write((char*)&a, sizeof(a));
        }

        void goToEnd(){//Va al final del archivo
            file.seekg(0, ios::end);
        }

        void goToBegin(){//Va al comienzo del archivo
            file.seekg(0, ios::beg);
        }

        T getBuffer(){
            return buffer;
        }

        int getElements(){ //Numero de elementos que hay en el archivo
            if(N == -1){
                goToEnd();
                int s = file.tellg();
                N = s/sizeof(buffer);
                goToBegin();
            }
            return N;
        }

        void writeGoto(int i){//Posicion en la que se va a escribir
            file.seekp(i*sizeof(T),ios::beg);
        }

        void readGoto(int i){ //Posicion en la que se va a leer
            file.seekg(i*sizeof(T),ios::beg);
        }

        bool fin(){
			return file.eof();
		}

};
#endif
