#pragma once
#include <iostream>
#include <fstream>

using namespace std;

//Clase Nodo

template <class T>
class Nodo{
    public:
        T info; //Dato guardado
        Nodo *next; //Nodo hijo
        Nodo(T);
};

template <class T>
Nodo<T>::Nodo(T dato){
    info = dato;
    next = nullptr;
}

//Clase lista ligada

template <class T>
class LinkedList{
    private:
        Nodo<T> *inicio; //Primer nodo de la lista
    public:
        LinkedList(); //Default Constructor
        void fill(string); //Default Constructor con archivo de datos
        void add(T); //Insertar dato al final de la lista
        void add_first(T); //Insertar dato al inicio de la lista
        Nodo<T> *buscar(T); //Busca un dato en la lista
        Nodo<T> *get(int); //Obtiene nodo en cierta posicion
        void show(); //Muestra la lista
        bool del(T); //Elimina dato de la lista
        bool replace_pos(int, T); //Reemplaza dato en cierta posicion
};

template <class T>
LinkedList<T>::LinkedList(){
    inicio = nullptr;
}

template <class T>
void LinkedList<T>::fill(string file){
    int n;
    T dato;
    ifstream miArchivo(file);

    if(miArchivo.is_open()){
        miArchivo >> n;
        for(int i = 0; i < n; i++){
            miArchivo >> dato;
            add(dato);
        }
        miArchivo.close();
    } else {
        cout << "No se puede abrir el archivo" << endl;
    } 
}

template <class T>
void LinkedList<T>::add(T dato){
        Nodo<T> *nuevo_nodo = new Nodo(dato); // Nodo a insertar

        Nodo<T> *aux; // Creamos un nodo auxiliar
        aux = inicio; // Guarda la direccion del primer nodo de la lista en el auxiliar

        if(inicio == nullptr) { // Si lista esta vacia
            inicio = nuevo_nodo; // El primero de la lista ahora tiene la direccion del nuevoNodo
        }
        else{
            // Recorre la lista hasta llegar al final
            while(aux -> next != nullptr) {
                aux = aux -> next; // Avanzamos al siguiente nodo
            }
            // El nodo final ahora apunta al nuevoNodo
            aux -> next = nuevo_nodo;
        }
}

template <class T>
void LinkedList<T>::add_first(T dato){
    Nodo<T> *nuevo_nodo = new Nodo(dato);
    nuevo_nodo -> next = inicio;
    inicio = nuevo_nodo;
}

template <class T>
Nodo<T> *LinkedList<T>::buscar(T dato){
    Nodo<T> *auxiliar;
    auxiliar = inicio;
    while (auxiliar != nullptr){
        if(auxiliar -> info == dato){
            return auxiliar;
        } else {
            auxiliar = auxiliar -> next;
        }   
    }

    return nullptr;
}

template <class T>
Nodo<T> *LinkedList<T>::get(int pos){
    Nodo<T> *aux;
    aux = inicio;
    for(int i = 0; i <= pos; i++){
        if(aux == nullptr){
            return nullptr;
        } else if (i == pos){
            return aux;
        }
        aux = aux -> next;
    }
    return nullptr;
}

template <class T>
void LinkedList<T>::show(){
    Nodo<T> *auxiliar;
    auxiliar = inicio;
    while (auxiliar != nullptr){
        cout << auxiliar -> info << endl;
        auxiliar = auxiliar -> next;
    }
}

template<class T>
bool LinkedList<T>::del(T dato){
    Nodo<T> *auxiliar, *elimina;
    auxiliar = inicio;

    if(auxiliar == nullptr){
        return false;

    } else if(auxiliar -> info == dato){
        inicio = auxiliar -> next;
        delete(auxiliar);
        return true;

    } else {
        while(auxiliar -> next != nullptr && (auxiliar -> next) -> info != dato){
            auxiliar = auxiliar -> next;
        }
        if(auxiliar -> next == nullptr){
            return false;
        } else {
            elimina = auxiliar -> next; // Elimina apunta al nodo siguiente del actual
            auxiliar -> next = elimina -> next; // El nodo actual apunta al siguiente del nodo a eliminar 
            delete(elimina); // Borramos el nodo a eliminar
            return true;            
        }
    }
}

template <class T>
bool LinkedList<T>::replace_pos(int pos, T dato){
    Nodo<T> *aux;
    aux = inicio;
    for(int i = 0; i <= pos; i++){
        if(aux == nullptr){
            return false;
        } else if (i == pos){
            aux -> info = dato;
            return true;
        }
        aux = aux -> next;
    }
    return false;
}