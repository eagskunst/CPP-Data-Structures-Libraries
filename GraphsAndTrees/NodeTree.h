#ifndef NODE_TREE_H
#define NODE_TREE_H

template <typename T>
class NodeTree{
private:
    T mData;
    NodeTree<T> *left;
    NodeTree<T> *right;
    int height;
public:
    NodeTree(T &data);
    T getData();
    NodeTree<T> *getLeft();
    NodeTree<T> *getRight();
    void setLeft(NodeTree<T>*);
    void setRight(NodeTree<T>*);
    void setData(T data);
    template<typename> friend class BinaryTree;
    template<typename> friend class BinaryAvlTree;
};

template <typename T>
NodeTree<T>::NodeTree(T &data):left(NULL),right(NULL){
    this->mData = data;
}

template <typename T>
void NodeTree<T>::setData(T data){
    this->mData = data;
}

template <typename T>
T NodeTree<T>::getData(){
    return this->mData;
}

template <typename T>
NodeTree<T>* NodeTree<T>::getLeft(){
    return this->left;
}

template <typename T>
NodeTree<T>* NodeTree<T>::getRight(){
    return this->right;
}

template <typename T>
void NodeTree<T>::setLeft(NodeTree<T>* nNode){
    this->left = nNode;
}

template <typename T>
void NodeTree<T>::setRight(NodeTree<T>* nNode){
    this->right = nNode;
}


#endif