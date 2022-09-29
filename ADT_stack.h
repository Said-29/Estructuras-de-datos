#pragma once
#include <iostream>
#include <fstream>
#include "ADT_LinkedList.h"

using namespace std;

#define MAX 50

class Stack{
    private:
        Lista datos;
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