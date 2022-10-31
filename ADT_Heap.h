#pragma once
#include <iostream>
#include "ADT_BST.h"
#include <vector>

using namespace std;

template <class T>
class HEAP{
    private:
        BST<T> tree;
    public:
        void push(T);
        bool pop();
        T top();
        bool empty();
        int size();
        int size_r(NodeT<T>*)
        void balance();
        vector<T> inorder(NodeT<T>*, vector<T>*);
};

template <class T>
void HEAP<T>::push(T dato){
    tree.add(dato);
}

template <class T>
vector<T> HEAP<T>::inorder(NodeT<T> *root, vector<T> *list){
    if(root == nullptr){
        return;
    }
    inorder(root -> get_left());
    list->push_back(root -> get_data());
    inorder(root -> get_right());
}