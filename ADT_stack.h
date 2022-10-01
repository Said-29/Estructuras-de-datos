#pragma once
#include <iostream>
#include <fstream>
#include "ADT_LinkedList.h"

using namespace std;

class Stack{
    private:
        Linked_list datos;
    public:
        Stack();
        void push(int);
        int top();
        int pop();
        bool is_empty();
        bool is_full();
};

void Stack::push(int valor){
    datos.insertarInicio(valor);
}

int Stack::pop(){
    int v = datos.get_first();
    datos.del(v);
    return v;
}

int Stack::top(){
    int v = datos.get_first();
    return v;
}

bool Stack::is_empty(){
    if(datos.get_first_p() == nullptr){
        return true;
    } else {
        return false;
    }
}