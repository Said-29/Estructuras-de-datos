#pragma once
#include <iostream>
#include <fstream>
#include "ADT_LinkedList.h"

using namespace std;

template <class T>
class Stack{
    private:
        LinkedList<T> datos;
    public:
        Stack();
        void push(T);
        T top();
        T pop();
        bool is_empty();
};

template <class T>
void Stack<T>::push(T valor){
    datos.add_first(valor);
}

template <class T>
T Stack<T>::pop(){
    T v;
    v = datos.get(0) -> info;
    datos.del(v);
    return v;
}

template <class T>
T Stack<T>::top(){
    T v = datos.get(0);
    return v;
}

template <class T>
bool Stack<T>::is_empty(){
    if(datos.get(0) == nullptr){
        return true;
    } else {
        return false;
    }
}