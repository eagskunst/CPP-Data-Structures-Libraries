#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "NodeTree.h"
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
class BinaryTree{
protected:
    const int LEFT = 0;
    const int RIGHT = 1;
    NodeTree<T>* root;
    void printPretty(const string, NodeTree<T>*, bool);
    NodeTree<T>* find(T, NodeTree<T>*);
    bool insert(T data, NodeTree<T>*, NodeTree<T>*, int);
    bool remove(T data, NodeTree<T>*&);
    int getNodeLevel(T, NodeTree<T>*, int);
    int max(const int, const int);
    virtual int getHeight(NodeTree<T>*);
public:
    BinaryTree(T);
    BinaryTree();
    NodeTree<T>* getRoot();
    void setRoot(NodeTree<T>*);
    bool contains(T data);
    T* getData(T);
    virtual bool insert(T data);
    virtual bool remove(T data);
    int getNodeLevel(T);
    int getHeight();
    void printInorder(NodeTree<T>*);
    void printPreorder(NodeTree<T>*);
    void printPretty();
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
NodeTree<T>* BinaryTree<T>::find(T data, NodeTree<T>* tempNode){
     if(!tempNode) return tempNode;

     T tempData  = tempNode->getData();
     if(tempData == data) return tempNode;
     else if(data > tempData) return find(data, tempNode->right);
     else return find(data, tempNode->left);
}

template <typename T>
bool BinaryTree<T>::contains(T data) {
     NodeTree<T>* node = find(data, this->root);
     return node != NULL;
}

template <typename T>
T* BinaryTree<T>::getData(T data){
     NodeTree<T> node = find(data, this->root);
     if(node != NULL) return node->getData();
     else return NULL;
}

template <typename T>
bool BinaryTree<T>::insert(T data, NodeTree<T>* tempNode, NodeTree<T>* father, int direction){
    if(tempNode == NULL){
        tempNode = new NodeTree<T>(data);
        if(direction == RIGHT) father->right = tempNode;
        else father->left = tempNode;
        return true;
    }

    T nodeData = tempNode->getData();
    NodeTree<T>* mFather = tempNode;
    if(data == nodeData) return false; //Delete this if you want to add duplicates
    else if(data <= nodeData) return insert(data, tempNode->getLeft(), mFather, LEFT);
    else return insert(data, tempNode->getRight(), mFather, RIGHT);
}

template <typename T>
bool BinaryTree<T>::insert(T data){
    if(root == NULL){
        root = new NodeTree<T>(data);
        return true;
    }

    return insert(data, this->root, this->root, -1);
}

template <typename T>
bool BinaryTree<T>::remove(T key, NodeTree<T>*& tempNode){

    T data = tempNode->getData();
    if(key < data) return remove(key, tempNode->left);
    else if (key > data) return remove(key, tempNode->right);
    else {
        
        NodeTree<T>** maxNodeLeft = &tempNode;
        bool firstCheck = false;
        while((*maxNodeLeft)->left != NULL){
            if(!firstCheck) {
                maxNodeLeft = &((*maxNodeLeft)->left);
                firstCheck = true;
            }
            else maxNodeLeft = &((*maxNodeLeft)->right);
        }

        data = (*maxNodeLeft)->getData();
        tempNode->setData(data);
        *maxNodeLeft = NULL;
        delete *maxNodeLeft;
        maxNodeLeft = NULL;
        delete maxNodeLeft;
        return true;
    }
}

template <typename T>
bool BinaryTree<T>::remove(T key){
    if(!contains(key)) return false;
    return remove(key, this->root);
}

//Returns -1 if not finded, else returns the node level of the given T data.
template <typename T>
int BinaryTree<T>::getNodeLevel(T data, NodeTree<T>* driverNode, int level){
    if(!driverNode) return -1;

    T nodeData = driverNode->getData();

    if(data == nodeData) return level;

    int downLevel = getNodeLevel(data, driverNode->left, level + 1);

    if(downLevel != -1) return downLevel;

    downLevel = getNodeLevel(data, driverNode->right, level + 1);

    return downLevel;
}

template <typename T>
int BinaryTree<T>::getNodeLevel(T data){
    if(!contains(data)) return -1;
    else return getNodeLevel(data, this->root, 1);
}

template <typename T>
int BinaryTree<T>::max(const int a, const int b){
    return ( (a > b) ? a : b );
}

template <typename T>
int BinaryTree<T>::getHeight(NodeTree<T>* driverNode){
    if(!driverNode) return 0;

    int leftHeight = getHeight(driverNode->left);
    int rightHeight = getHeight(driverNode->right);

    return 1 + max(leftHeight, rightHeight);
}

template <typename T>
int BinaryTree<T>::getHeight(){
    return getHeight(this->root);
}

template <typename T>
void BinaryTree<T>::printPretty(const string prefix, NodeTree<T>* node, bool isLeft){
     if(node != NULL) {
        cout << prefix;

        cout << (isLeft ? "L--" : "R--" );

        // print the value of the node
        cout << node->getData() << std::endl;

        // enter the next tree level - left and right branch
        printPretty( prefix + (isLeft ? "|   " : "    "), node->getLeft(), true);
        printPretty( prefix + (isLeft ? "|   " : "    "), node->getRight(), false);
     }
}

template <typename T>
void BinaryTree<T>::printPretty(){
    printPretty("", this->root, false);
}

template <typename T>
void BinaryTree<T>::printInorder(NodeTree<T>* tempNode){
    if(!tempNode){
        return;
    }
    printInorder(tempNode->right);
    cout<< tempNode->getData() << " ";
    printInorder(tempNode->right);
}

template <typename T>
void BinaryTree<T>::printPreorder(NodeTree<T>* node){
    if(node != NULL){
        cout<<node->getData()<<" ";
        printPreorder(node->getLeft());
        printPreorder(node->getRight());
    }
}

#endif