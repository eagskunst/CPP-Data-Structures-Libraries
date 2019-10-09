#ifndef BINARY_AVL_TREE_H
#define BINARY_AVL_TREE_H
#include "BinaryTree.h"
#include <string>

using namespace std;

/*This heavily depends on overloads of the following operators in the T class:
    operator ==
    operator >
    operator <=
    operator <
    operator =
*/

template <typename T>
class BinaryAvlTree : public BinaryTree<T> {
private:
    int getHeight(NodeTree<T>*);
    int getBalance(NodeTree<T>*);
    NodeTree<T>* insert(NodeTree<T>*, T data);
    NodeTree<T>* rightRotation(NodeTree<T>*);
    NodeTree<T>* leftRotation(NodeTree<T>*);
    NodeTree<T>* minValueNode(NodeTree<T>*);
    NodeTree<T>* remove(NodeTree<T>*, T);
public:
    BinaryAvlTree();
    BinaryAvlTree(T);
    bool insert(T);
    bool remove(T);
};

template <typename T>
BinaryAvlTree<T>::BinaryAvlTree():BinaryTree<T>(){
}

template <typename T>
BinaryAvlTree<T>::BinaryAvlTree(T data):BinaryTree<T>(data){
}

template <typename T>
int BinaryAvlTree<T>::getBalance(NodeTree<T>* node){
    if(!node) return 0;

    return getHeight(node->left) - getHeight(node->right);
}

template <typename T>
int BinaryAvlTree<T>::getHeight(NodeTree<T>* node){
    if(!node) return 0;
    return node->height;
}

template <typename T>
NodeTree<T>* BinaryAvlTree<T>::rightRotation(NodeTree<T>* node){
    NodeTree<T>* temp1 = node->left;
    NodeTree<T>* temp2 = temp1->right;

    temp1->right = node;
    node->left = temp2;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    temp1->height = max(getHeight(temp1->left), getHeight(temp1->right)) + 1;

    return temp1;
}

template <typename T>
NodeTree<T>* BinaryAvlTree<T>::leftRotation(NodeTree<T>* node){
    NodeTree<T>* temp1 = node->right;
    NodeTree<T>* temp2 = temp1->left;

    temp1->left = node;
    node->right = temp2;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    temp1->height = max(getHeight(temp1->left), getHeight(temp1->right)) + 1;

    return temp1;
}

template <typename T>
NodeTree<T>* BinaryAvlTree<T>::insert(NodeTree<T>* node, T data){
    if(!node){
        node = new NodeTree<T>(data);
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return node;
    }

    T nodeData = node->getData();

    if(data < nodeData)
        node->left = insert(node->getLeft(), data);
    else if (data > nodeData)
        node->right = insert(node->getRight(), data);
    else
        return node;
    
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balanceFactor = getBalance(node);

    //Left Left case
    if (balanceFactor > 1 && data < node->left->getData()){
        return rightRotation(node);
    }
    
    //Right Right case
    if (balanceFactor < -1 && data > node->right->getData()){
        return leftRotation(node);
    }

    //Left Right case
    if (balanceFactor > 1 && data > node->left->getData()){
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    if (balanceFactor < -1 && data < node->right->getData()){
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
}

template <typename T>
bool BinaryAvlTree<T>::insert(T data){
    this->root = insert(this->root, data);
    return this->root != NULL;
}

template <typename T>
NodeTree<T>* BinaryAvlTree<T>::minValueNode(NodeTree<T>* node){
    NodeTree<T>* driverNode = node;
    while(driverNode->left != NULL)
        driverNode = driverNode->left;

    return driverNode;
}

template <typename T>
NodeTree<T>* BinaryAvlTree<T>::remove(NodeTree<T>* node, T data){
    if(!node) return node;

    T nodeData = node->getData();

    if(data < nodeData) 
        node->left = remove(node->left, data);
    else if(data > nodeData)
        node->right = remove(node->right, data);
    
    else {
        //Caso con nodo con un solo hijo o sin hijos
        if( (node->left == NULL)  || (node->right == NULL) ){
            NodeTree<T>* tempNode = node->left ? 
                    node->left : node->right;
            if(tempNode == NULL){ //Sin hijos
                tempNode = node;
                node = NULL;
            }
            else{ //Con hijo
                *node = *tempNode; //Copia el puntero del nodo de este scope al nodo del scope de la funcion
            }
            free(tempNode);
        }

        else {
            //Nodo con dos hijos, busca el sucesor de forma inOrder (el mas pequeño hacia la derecha)
            NodeTree<T>* tempNode = minValueNode(node->right);
            //Copia la data del sucesor al nodo global
            node->setData(tempNode->getData());

            //Eliminar el sucesor
            node->right = remove(node->right, tempNode->getData());
        }
    }

    //Si solo hay un nodo
    if(!node) return node;

    //Actualizar altura del nodo
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balanceFactor = getBalance(node);

    //Left left case
    if(balanceFactor > 1 && getBalance(node->left) >= 0){
        return rightRotation(node);
    }

    //Left Right case
    if(balanceFactor > 1 && getBalance(node->left) < 0){
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    //Right right case
    if(balanceFactor < -1 && getBalance(node->right) > 0){
        return leftRotation(node);
    }

    //Right Left case
    if(balanceFactor < -1 && getBalance(node->right) > 0){
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
}

template <typename T>
bool BinaryAvlTree<T>::remove(T data){
    this->root = remove(this->root, data);
    return this->root != NULL;
}


#endif