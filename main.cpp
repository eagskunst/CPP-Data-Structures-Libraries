//Archivo para correr código y testear las clases
#include <iostream>
#include "FilesHandler\Archivo.h"
#include "Custom Classes\Persona.h"
#include "Custom Classes/Str.h"
#include "Searching/busquedas.h"
#include "Searching/HashSearch.h"
#include "Collections/eagskunst/CircularQueue.h"
#include "Collections/eagskunst/Stack.h"
#include "Collections/eagskunst/Biqueue.h"
#include "Collections/eagskunst/LinkedList.h"
#include "Collections/eagskunst/CircularLinkedList.h"
#include "Collections/eagskunst/DoubleLinkedList.h"
#include "Collections/eagskunst/DynamicLinealStructure.h"
using namespace std;

int main(int argc, char const *argv[]){
 /*    CircularQueue<Str> queue(6);
    Str s("XD");
    queue.remove(s);
    Str textos[] = {"Hola", "Como", "Estas", "Una", "Prueba", "De", "Cadenas", "Para", "Probar", "Estructuras", "Datos", "equisde"};
    int n = sizeof(textos)/sizeof(Str);
    cout<<n<<endl;
    Str s1("Prueba1"), s2("Prueba2"), s3("Prueba4");

    DoubleLinkedList<Str> list;
    list.insertAtStart(textos[0]);
    list.insertAtEnd(textos[1]);
    list.deleteAtEnd();
    list.print();
    list.clear();
    list.print();
    for (int i = 0; i < n; i++){
        list.insertAtStart(textos[i]);
    }
    list.print();
    list.deleteAtEnd();
    list.deleteAtEnd();
    //list.insertAtPosition("Emmanuel",3);
    //list.deleteElement("Emmanuel");
    list.deleteElement("Datos");
    list.print();
    if(list.contains("Emmanuel")) cout<<"El elemento existe"<<endl;
    else cout<<"El elemento no existe"<<endl; */
    
    CircularLinkedList<int> sortTest;
    int numbers[] = {1,435,12,47,25,62,2,51,98,31,47};
    int numbersS = sizeof(numbers)/sizeof(int);
    for (int i = 0; i < numbersS; i++){
        sortTest.insertAtStart(numbers[i]);
    }
    sortTest.sort(false);
    sortTest.print();
    sortTest.clear();
    sortTest.print();
    sortTest.insertAtStart(19);
    sortTest.print();
    
   /*  DynamicLinealStructure<Str> dls(StackType);
    for (int i = 0; i < n; i++){
        dls.push(textos[i]);
    }
    dls.print();
    Str testeo;
    int size2 = dls.getSize();
    for(int i = 0; i<size2; i++){
        dls.pop(testeo);
        cout<<"Value: "<<testeo<<endl;
    }
    dls.push("Emmanuel");
    dls.push("Gabriel");
    dls.print(); */
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
