//Archivo para correr código y testear las clases
#include <iostream>
#include "FilesHandler\Archivo.h"
#include "Custom Classes\Persona.h"
#include "Searching/busquedas.h"
using namespace std;

int main(int argc, char const *argv[]){
    cout<<"Hola mundo"<<endl;
    Persona p = Persona::transform("Emma-20");
    cout<<"Nombre: "<<p.nombre<<" Edad "<<p.edad<<endl;
    p.nombre = "Gabriel";
    p.edad = 15;
    char aux[30];
    Persona::toString(p, aux);
    cout<<aux<<endl;
    Archivo<Persona> personasFile("personas.txt", Persona::transform, Persona::toString, true);
    personasFile.abrir(ios::out);
    personasFile.write(p);
    p.nombre = "Carlos";
    p.edad = 19;
    personasFile.write(p);
    p.nombre = "Johan";
    p.edad = 18;
    personasFile.write(p);
    personasFile.cerrar();
    Archivo<Persona> personasFile2("personas.txt", Persona::transform, Persona::toString, true);
    if(!personasFile2.abrir(ios::in)) cout<<"FAIL"<<endl;
    cout << "Elements: "<<personasFile2.getElements()<<endl;
    for (int i = 0; i < personasFile2.getElements(); i++){
        cout<<personasFile2.read()<<endl;
    }
    personasFile2.cerrar();
    Persona v[] = {Persona("Emmanuel", 19),
                   Persona("Johan", 19),
                   Persona("Gabriel", 19),
                   Persona("Carlos", 19),
                   Persona("Rafael", 19),
                   Persona("Andrea", 19),
                   Persona("Angelica", 19),
                   Persona("Klisman", 19),
                   Persona("Maria Daniela", 19),
                   Persona("Bertha", 19)};
    int n = sizeof(v)/sizeof(Persona);
    cout<<"Pos: "<<busquedaPorBloques(v,n,Persona("Bertha", 19))<<endl;
    cout<<"Pos: "<<busquedaPorBloques(v,n,Persona("Ivan", 19))<<endl;

    return 0;
}
