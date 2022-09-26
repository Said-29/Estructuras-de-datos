#pragma once
#include <fstream>
#include <iostream>

using namespace std;

////////////////////////////////////////////////////
// Implementacion de las clases NodoLista y Lista //
////////////////////////////////////////////////////

class NodoLista {
    public:
        int info;
        NodoLista *next;

        NodoLista(int dato) {
            info = dato;
            next = nullptr;
        }
};

class Lista {
    private:
        NodoLista *primero;
    public:
        Lista() {
            primero = nullptr;
        }

        NodoLista* buscar(int dato) {
            NodoLista *actual;
            actual = primero;

            while(actual != nullptr) {
                if(actual -> info == dato) {
                    return actual;
                }
                else {
                    actual = actual -> next;
                }
            }
            return nullptr;
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

        bool eliminar(int dato) {
            NodoLista *actual, *elimina;
            actual = primero;

            if (actual == nullptr) {
                return false; // La lista esta vacia
            }

            if (actual -> info == dato) {
                primero = actual -> next;
                delete(actual);
                return true; // era el primero y se borra con exito
            }

            while ((actual -> next != nullptr) && (actual -> next) -> info != dato) {
                actual = actual -> next;
            }

            if (actual -> next == nullptr) {
                return false; // El dato no se encuentra en la lista
            }

            elimina = actual -> next;
            actual -> next = elimina -> next;
            delete(elimina);
            return true;
        }

        bool elimina_inicio(){
            NodoLista *elimina;
            if(primero == nullptr){
                return false;
            } else {
                elimina = primero;
                primero = primero -> next;
                delete(elimina);
                return(true);
            }
        }

};