#pragma once
#include <iostream>
using namespace std;

class NodoLista {
    public:
        int info; // Variable donde guardaremos el dato que tendra este nodo
        NodoLista *next; // Apuntador de tipo clase hacia el siguiente nodo

        NodoLista(int dato) {
            info = dato; // Guarda el dato recibido en el nodo actual
            next = nullptr; // Se le asigna nullptr para que no apunte a una direccion basura
        }
};

// Clase Lista ligada
class Lista {
    private:
        NodoLista *primero; // Crea un pointer de clase NodoLista para el primer nodo
    public:
        Lista() {
            primero = nullptr; // Se le asigna nullptr para que no apunte a una direccion basura
        }

        // Funcion para buscar un dato en la lista 
        // Complejidad O(n)
        NodoLista *read(int dato) {
            NodoLista *actual; // Creamos un pointer de la clase NodoLista para la pos actual
            actual = primero; // Guarda la direccion del primer nodo de la lista en actual

            // Mientras la direccion de actual no sea null
            while(actual != nullptr) {

                // Si la info del nodo actual es igual al dato que buscamos
                if(actual -> info == dato) {
                    return actual; // Regresamos la direccion del nodo
                }
                else { // Avanzamos hacia el siguiente nodo
                    actual = actual -> next;
                }
            }
            // Si el elemento buscado no esta en la lista ligada, regresa un valor nulo
            return nullptr;
        }

        // Funcion create
        // Complejidad O(n)
        void create(int dato) {
            // Creamos un pointer tipo NodoLista y guardamos el dato a insertar en
            // memoria dinamica
            NodoLista *nuevoNodo = new NodoLista(dato);

            NodoLista *actual; // Creamos un pointer de la clase NodoLista para la pos actual
            actual = primero; // Guarda la direccion del primer nodo de la lista en actual

            if(primero == nullptr) { // La lista esta vacia
                primero = nuevoNodo; // El primero de la lista ahora tiene la direccion del nuevoNodo
            }
            else{
                // Mientras la direccion del siguiente nodo no sea null
                while(actual -> next != nullptr) {
                    actual = actual -> next; // Avanzamos al siguiente nodo
                    // Al terminal actual apunta al nodo final
                }
                // El nodo final ahora apunta al nuevoNodo
                actual -> next = nuevoNodo;
            }
        }

        // Funcion del
        // Complejidad: O(n)
        bool del(int dato) {
            // Creamos nuestro pointers tipo NodoLista
            // para el nodo actual y el que vamos a borrar
            NodoLista *actual, *elimina;
            actual = primero; // Guarda la direccion del primer nodo de la lista en actual

            // Si actual apunta a nada
            if (actual == nullptr) {
                return false; // La lista esta vacia
            }

            // Si actual tiene el dato que queremos borrar
            if (actual -> info == dato) {
                primero = actual -> next; // El primer nodo ahora es el siguiente del actual
                delete(actual); // Borramos el nodo con el dato buscado
                return true; // era el primero y se borra con exito
            }

            // Mientras que el nodo siguiente apunte algo diferente a null y este
            // dato sea diferente al dato a eliminar, se avanza en la lista
            while ((actual -> next != nullptr) && (actual -> next) -> info != dato) {
                actual = actual -> next; // Se detiene en el nodo previo al borrar
            }

            // Si se llega al final de la lista
            if (actual -> next == nullptr) {
                return false; // El dato no se encuentra en la lista
            }

            elimina = actual -> next; // Elimina apunta al nodo siguiente del actual
            actual -> next = elimina -> next; // El nodo actual apunta al siguiente del nodo a eliminar 
            delete(elimina); // Borramos el nodo a eliminar
            return true;
        }

        // Funcion update
        // Complejidad O(n)
        NodoLista *update(int original, int nuevo) {
            NodoLista *actual; // Creamos un pointer de la clase NodoLista para la pos actual
            actual = primero; // Guarda la direccion del primer nodo de la lista en actual

            // Mientras la direccion de actual no sea null
            while(actual != nullptr) {

                // Si la info del nodo actual es igual al dato que buscamos
                if(actual -> info == original) {
                    actual -> info = nuevo; // Reemplazamos el dato por el nuevo
                }
                else { // Avanzamos hacia el siguiente nodo
                    actual = actual -> next;
                }
            }
            // Si el elemento buscado no esta en la lista ligada, regresa un valor nulo
            return nullptr;
        }

        void imprimir() {
            NodoLista *actual; // Creamos un pointer de la clase NodoLista para la pos actual
            actual = primero; // Guarda la direccion del primer nodo de la lista en actual
            int i = 1; // Contador de elementos

            if(primero == nullptr) {
                exit(0);
            }

            while(actual != nullptr) {
                cout << "Elemento " << i  << ": " << actual -> info << endl;
                actual = actual -> next;
                i++;
            }
        }

        int get_first(){
            return primero->info;
        }

        void insertarInicio(int dato) {
            NodoLista *nuevoNodo = new NodoLista(dato);
            nuevoNodo -> next = primero;
            primero = nuevoNodo;
        }

        void insertarFinal(int dato) {
            NodoLista *nuevoNodo = new NodoLista(dato);
            NodoLista *actual;
            actual = primero;
            if(primero == nullptr) { // La lista esta vacia
                primero = nuevoNodo;
            }
            else{
                while(actual -> next != nullptr) {
                    actual = actual -> next;
                    // Al terminal actual apunta al nodo final
                }
                actual -> next = nuevoNodo;
            }
        }

        void insertarDespues(int dato, int k) {
            NodoLista *nuevoNodo = new NodoLista(dato);
            NodoLista *actual;
            actual = primero;
            
            while (actual -> info != k) {
                actual = actual -> next;
                // al terminar, actual apunta al nodo que contiene el valor k
            }
            nuevoNodo -> next = actual -> next; // Muy importante que esto se haga primero
            actual -> next = nuevoNodo;
        }

};