#pragma once
#include <iostream>
#include <fstream>
#include "ADT_LinkedList.h"

using namespace std;

#define MAX 50

class Stack{
    private:
        int datos[MAX];
        int tope;
    public:
        Stack();
        void push(int);
        int top();
        int pop();
        bool is_empty();
        bool is_full();
};

void Stack::push(int valor){
    tope++;
    datos[tope] = valor;
}

int Stack::pop(){
    int v = datos[tope];
    tope--;
    return v;
}

int Stack::top(){
    int v = datos[tope];
    return v;
}