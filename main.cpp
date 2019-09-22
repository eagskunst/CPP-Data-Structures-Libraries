//Archivo para correr código y testear las clases
#include <iostream>
#include "GraphsAndTrees/BinaryTree.h"

using namespace std;

int main(int argc, char const *argv[]){
    BinaryTree<int> t;

    for (int i = 0; i < 3; i++){
        t.insert(i);
    }

    t.printInorder(t.getRoot());
    
    return 0;
}

