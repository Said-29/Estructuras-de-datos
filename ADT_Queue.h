#pragma once
#include <iostream>
#include "ADT_LinkedList.h"

using namespace std;

template <class T>
class Queue{
    private:
        LinkedList<T> datos;
    public:
        void push(T); //Inserta dato siguiendo las reglas de una fila
        T next(); //Siguiente en la fila
        T pop(); //Eliminar siguiente en la fila
        bool is_empty(); //True si esta vacio
        void show(); //Muestra la lista
        void fill(string); //Llena la lista
        bool buscar(T); //Busca un dato
        bool replace(int, T); // Reemplaza un dato en cierta posicion
};

template <class T>
void Queue<T>::push(T dato){
    datos.add(dato);
}

template <class T>
T Queue<T>::next(){
    return datos.get(0) -> info;
}

template <class T>
T Queue<T>::pop(){
    T v = datos.get(0) -> info;
    datos.del(v);
    return v;
}

template <class T>
bool Queue<T>::is_empty(){
    return datos.is_empty();
}

template <class T>
void Queue<T>::show(){
    datos.show();
}

template <class T>
void Queue<T>::fill(string file){
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
bool Queue<T>::buscar(T dato){
    return datos.buscar(dato);
}

template <class T>
bool Queue<T>::replace(int pos, T dato){
    return datos.replace(pos, dato);
}