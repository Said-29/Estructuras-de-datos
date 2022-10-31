#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Nodo{
    private:
        T data;
        vector<Nodo*> origenes;
        vector<Nodo*> destinos;
    public:
        void set_data(T dato){data = dato;};
        T get_data(){return data;};
        vector<T> get_origenes(){return origenes;};
        void add_origen(Node<T> *nodo){origenes.push_back(nodo);};
        vector<T> get_destinos(){return destinos;};
        void add_destino(Node<T> *nodo){destinos.push_back(nodo);};
};

template <class T>
class Grafo{
    private:
        vector<T> Nodos;
    public:
        void agregar_nodo(Node<T>*);
        void borrar_nodo(Node<T>*);
        void BSF();
        void DFS();
};

template <class T>
void Grafo<T>::agregar_nodo(Node<T> *nodo){
    for(int i = 0; i < Nodos.size(); i++){
        if(Nodo[i] == nodo){
            cout << "Este nodo ya existe" << endl;
            return;
        }
    }
    Nodos.push_back(nodo);
}

template <class T>
void Grafo<T>::borrar_nodo(Node<T>* nodo){
    for(int i = 0; i < Nodos.size(); i++){
        if(Nodo[i] == nodo){
            Nodo.
        }
    }
}