#pragma once
#include <iostream>

using namespace std;

template <class T>
class NodeT{
    private:
        T data;
        NodeT<T> *left, *right;
    public:
        NodeT();
        NodeT(T);
      	T get_data(){return data;};
        void set_data(T v){data = v;};
        NodeT<T> *get_left(){return left;};
        void set_left(NodeT<T> *n){left = n;};
        NodeT<T> *get_right(){return right;};
        void set_right(NodeT<T> *n){right = n;};
};

template <class T>
NodeT<T>::NodeT(){
    left = right = nullptr;
}

template <class T>
NodeT<T>::NodeT(T v){
    data = v;
    left = right = nullptr;
}

template <class T>
class BST{
    private:
        NodeT<T> *root;
    public:
        BST();
        BST(T);
        bool search(T);
        void add(T);
        void show();
        NodeT<T> *get_root();
        void fill(string);
};

template <class T>
NodeT<T>* BST<T>::get_root(){
    return root;
}

template <class T>
BST<T>::BST(){
    root = nullptr;
}

template <class T>
BST<T>::BST(T v){
    root = new NodeT<T>(v);
}

template <class T>
bool BST<T>::search(T v){
    NodeT<T> *p;
    p = root;
    while(p != nullptr){
        if(p -> get_data() == v){
            return true;
        } else {
            if (p -> get_data() > v){
                p = p -> get_left();
            } else {
                p = p -> get_right();
            }
        }
    }
    return false;
}

template <class T>
void BST<T>::add(T v){
    NodeT<T> *nuevo = new NodeT(v);
    NodeT<T> *aux;
    aux = root;

    if(aux == nullptr){
        root = nuevo;
        return;
    }
    
    while (aux != nullptr && aux -> get_data() != v){
        if (aux -> get_data() < v){
            if(aux -> get_right() == nullptr){
                aux -> set_right(nuevo);
                T value = aux -> get_right() -> get_data() ;
                return;
            } else {
                aux = aux -> get_right();        
            }            
        } else {
            if(aux -> get_left() == nullptr){
                aux -> set_left(nuevo);
                T value = aux -> get_left() -> get_data() ;
                return;
            } else {
                aux = aux -> get_left();  
            }
        }        
    }

    cout << "Este dato ya existe" << endl;
}

template <class T>
void BST<T>::fill(string file){
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