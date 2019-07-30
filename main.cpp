//Archivo para correr código y testear las clases
#include <iostream>
#include "FilesHandler\Archivo.h"
#include "Custom Classes\Persona.h"
#include "Custom Classes/Str.h"
#include "Searching/busquedas.h"
#include "Searching/HashSearch.h"
#include "Collections/CircularQueue.h"
#include "Collections/Stack.h"
#include "Collections/Biqueue.h"
#include "Collections/LinkedList.h"
#include "Collections/CircularLinkedList.h"
using namespace std;

int main(int argc, char const *argv[]){
    CircularQueue<Str> queue(6);
    Str s("XD");
    queue.remove(s);
    Str textos[] = {"Hola", "Como", "Estas", "Una", "Prueba", "De", "Cadenas", "Para", "Probar", "Estructuras", "Datos", "equisde"};
    int n = sizeof(textos)/sizeof(Str);
    cout<<n<<endl;
    Str s1("Prueba1"), s2("Prueba2"), s3("Prueba4");

    CircularLinkedList<Str> list;
    list.insertAtStart(textos[0]);
    list.insertAtEnd(textos[1]);
    list.deleteAtEnd();
    list.print();
    list.peek(s);
    cout<<s<<endl;
    list.peek(s);
    cout<<s<<endl;
    for (int i = 0; i < n; i++){
        list.insertAtStart(textos[i]);
    }
    list.deleteAtEnd();
    list.deleteAtEnd();
    list.print();
    
    
    return 0;
}

void legacyMain(){
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
    HashSearch hs;
    hs.generateIntArray(n);
    int hashcode;
    cin>>hashcode;
    int value = hs.localizarHash(hashcode, n);
    cout<<"Datos:" << v[value]<<endl;
}
