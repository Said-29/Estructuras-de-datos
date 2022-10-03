#pragma once
#include <iostream>
#include "ADT_LinkedList.h"

using namespace std;

template <class T>
class Stack{
    private:
        LinkedList<T> datos;
    public:
        void push(T); //Inserta un dato siguiendo las reglas de un Stack
        T top(); //Dato hasta arriba del stack
        T pop(); //Elimina dato hasta arriba del stack
        bool is_empty(); //True si esta vacio
        void show(); //Muestra el stack
        void fill(string); //Llena el stack con datos
        bool buscar(T); //Busca un valor en el stack
        bool replace(int, T); //Reemplaza dato en cierta posicion
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
    T v = datos.get(0) -> info;
    return v;
}

template <class T>
bool Stack<T>::is_empty(){
    return datos.is_empty();
}

template <class T>
void Stack<T>::show(){
    datos.show();
}

template <class T>
void Stack<T>::fill(string file){
    int n;
    T dato;
    ifstream miArchivo(file);

    if(miArchivo.is_open()){
        miArchivo >> n;
        for(int i = 0; i < n; i++){
            miArchivo >> dato;
            push(dato);
        }
        miArchivo.close();
    } else {
        cout << "No se puede abrir el archivo" << endl;
    } 
}

template <class T>
bool Stack<T>::buscar(T dato){
    return datos.buscar(dato);
}

template <class T>
bool Stack<T>::replace(int pos, T dato){
    return datos.replace(pos, dato);
}