#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "ADT_BST.h"

using namespace std;

template <class T>
class PQ{
    private:
        BST<T> tree;
    public:
        void push(T);
        bool pop();
        T top();
        bool empty();
        int size();
        int size_r(NodeT<T>*)
};

template <class T>
void PQ<T>::push(T){

}

template <class T>
bool PQ<T>::pop(){

}

template <class T>
T PQ<T>::top(){
    return tree.get_root() -> get_data();
}

template <class T>
bool PQ<T>::empty(){
    if(tree.get_root() == nullptr){
        return true;
    }
    return false;
}

template <class T>
int PQ<T>::size(){
    return size_r(tree.get_root());
}

template <class T>
int PQ<T>::size_r(NodeT<T> *p){
    if(p == nullptr){
        return 0;
    }
    return size_r(p -> get_left()) + 1 + size_r(p -> get_right());
}