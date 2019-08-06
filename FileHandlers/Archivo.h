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
    bool isTextFile = true;
    void(*toString)(T obj, char *dest) = NULL;
    T(*toObj)(char *str) = NULL;    


    public: 
        Archivo(){
            Archivo("");
        }

        Archivo(char *nombre, bool isTextFile = true){
            Archivo(nombre, NULL, NULL, isTextFile);
            setNombre(nombre);
        }

        Archivo(const char *nom, T(*toObject)(char *str), void(*toString)(T Obj, char *buffer),
                bool isTextFile){
            strcpy(this->nombre, nom);
            this->isTextFile = isTextFile;
            this->toObj = toObject;
            this->toString = toString;
            sizeT = sizeof(T);
        }

        void setNombre(char *nombre){
            strcpy(this->nombre, nombre);
        }

        void setToObj(T(*toObject)(char *str)){
            this->toObj = toObject;
        }
        
        void setToString(void(*toString)(T Obj, char *buffer)){
            this->toString = toString;
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
            if(!isTextFile){
                file.read((char*)&buffer, sizeT);
            }
            else{
                char temp[300];
                file.getline(temp, 300);
                if(toObj == NULL){
                    cout<<"Funcion puntero nula, no se puede hacer la conversion"<<endl;
                }
                else if(strcmp(temp, "") != 0) {
                    buffer = toObj(temp);
                }
            }
            return buffer;
        }

        void write(T &a){ //Escribe en la linea en la que este posicionada el archivo
            if(!isTextFile){
                file.write((char*)&a, sizeof(a));
            }
            else{
                char temp[300];
                if(toString == NULL){
                    cout<<"Funcion puntero nula, no se puede hacer la conversion"<<endl;
                }
                else{
                    toString(a, temp);
                    file<<temp<<endl;
                }
            }
        }

        void goToEnd(bool read = true){//Va al final del archivo
            if(read) file.seekg(0, ios::end); else file.seekp(0, ios::end); 
        }

        void goToBegin(bool read = true){//Va al comienzo del archivo
            file.clear();
            if(read) file.seekg(0, ios::beg); else file.seekp(0, ios::beg);
        }

        T getBuffer(){
            return buffer;
        }

        int getElements(bool read = true){ //Numero de elementos que hay en el archivo
            if(N == -1){
                if(!isTextFile){
                    goToEnd(read);
                    int s = file.tellg();
                    N = s/sizeof(buffer);
                    goToBegin(read);
                }
                else{
                    N = 0;
                    goToBegin(read);
                    char temp[300];
                    while (!fin()){
                        file.getline(temp, 300);
                        if(strcmp(temp, "") != 0){
                            N++;
                        } 
                    }
                    goToBegin(read);
                }
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