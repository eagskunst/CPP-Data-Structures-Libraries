//Archivo para correr código y testear las clases
#include <iostream>
#include "GraphsAndTrees/BinaryAvlTree.h"


int main(int argc, char const *argv[]){
    BinaryTree<int> t;

    t.insert(90);
    t.insert(50);
    t.insert(150);
    t.insert(20);
    t.insert(75);
    t.insert(95);
    t.insert(175);
    t.insert(5);
    t.insert(25);
    t.insert(66);
    t.insert(80);
    t.insert(92);
    t.insert(111);
    t.insert(166);
    t.insert(200);

    t.printPretty();
    t.remove(95);
    cout<<"ARBOL 2: \n\n";
    t.printPretty();
    int level = t.getNodeLevel(175);
    cout<<"Nivel: "<<level<<endl;
    int altura = t.getHeight();
    cout<<"Altura: "<<altura<<endl;

    BinaryAvlTree<int> t2;

    t2.insert(9);
    t2.insert(5);
    t2.insert(10);
    t2.insert(0);
    t2.insert(6);
    t2.insert(11);
    t2.insert(-1);
    t2.insert(1);
    t2.insert(2);

    t2.printPreorder(t2.getRoot());

    t2.remove(10);
    cout<<"\nArbol despues de borrar el 10: "<<endl;

    t2.printPreorder(t2.getRoot());
    return 0;
}