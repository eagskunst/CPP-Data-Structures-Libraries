#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "NodeTree.h"
#include "../Collections/eagskunst/DynamicLinealStructure.h"

template <typename T>
class BinaryTree{
private:
    NodeTree<T>* root;
    NodeTree<T>* printNode;
public:
    BinaryTree(T);
    BinaryTree();
    NodeTree<T>* getRoot();
    void setRoot(NodeTree<T>*);
    bool insert(T data);
    void printInorder(NodeTree<T>*);
};

template <typename T>
BinaryTree<T>::BinaryTree():root(NULL){

}

template <typename T>
BinaryTree<T>::BinaryTree(T data){
    this->root = new NodeTree<T>(data);
}

template <typename T>
void BinaryTree<T>::setRoot(NodeTree<T>* nNode){
    this->root = nNode;
}

template <typename T>
NodeTree<T>* BinaryTree<T>::getRoot(){
    return this->root;
}

template <typename T>
bool BinaryTree<T>::insert(T data){
    if(root == NULL){
        root = new NodeTree<T>(data);
        return true;
    }
    DynamicLinealStructure<NodeTree<T>*> queue(QueueType);
    queue.push(root);

    NodeTree<T> *nNode = new NodeTree<T>(data);
    NodeTree<T> *driverNode;

    if(!nNode) return false;

    while (!queue.isEmpty()){
        queue.pop(driverNode);

        if(driverNode->left == NULL){
            driverNode->left = nNode;
            return true;
        }
        else{
            queue.push(driverNode->right);
        }

        if(driverNode->right == NULL){
            driverNode->right = nNode;
            return true;
        }
        else{
            queue.push(driverNode->right);
        }
    }

    return false;
}

template <typename T>
void BinaryTree<T>::printInorder(NodeTree<T>* tempNode){
    if(!tempNode){
        return;
    }
    printInorder(tempNode->left);
    cout<< tempNode->getData() << " ";
    printInorder(tempNode->right);
}

#endif