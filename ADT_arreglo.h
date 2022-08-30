#pragma once
#include <iostream>
#include <fstream>

using namespace std;

#define MAX 50

class Arreglo{
    private:
        int datos[MAX];
        int tam = 0;
    public:
        void insertar(int);
        int borrar();
        void imprimir();
        void intercambiar(int, int);
        void leer(string);
        void bubble_sort();
        void insertion_sort();
        void merge_sort(int, int);
        void mezcla(int, int, int);
};

void Arreglo::insertar(int dato){
    if (tam < MAX){
        datos[tam] = dato;
        tam++;
    }
    else{
        cout << "Este arreglo ya esta lleno, no se puede insertar el dato" << endl;
    }
}

int Arreglo::borrar(){
    int dato;
    if (tam>0){
        dato = datos[tam-1];
        tam--;
    }
    else{
        cout << "El arreglo esta vacio, no se puede borrar el elemento" << endl;

        dato = -1;
    }
    return dato;
}

void Arreglo::imprimir(){
    for(int i = 0; i < tam; i++){
        cout << datos[i] << " ";
    }
    cout << endl;
}

void Arreglo::intercambiar(int pos1, int pos2){
    int tmp;
    tmp = datos[pos1];
    datos[pos1]=datos[pos2];
    datos[pos2]=tmp;
}
void Arreglo::leer(string archivo){
    int n, numero;
    ifstream miArchivo(archivo);

    if(miArchivo.is_open()){
        miArchivo >> n;
        for(int i = 0; i < n; i++){
            miArchivo >> numero;
            insertar(numero);
        }
        miArchivo.close();
    }
    else cout << "No se puede abrir el archivo" << endl;
}

void Arreglo::bubble_sort(){
    bool interruptor = true;

    for(int i = 0;i < tam-1 && interruptor; i++){
        interruptor = false;

        for(int j = 0; j<tam-1-i; j++){

            if(datos[j+1]<datos[j]){
                intercambiar(j, j+1);
                interruptor = true;
            }

        }
    }
}

void Arreglo::insertion_sort(){
    int i, j, tmp;

    for(i = 0; i < tam ; i++){
        for(j = i; j >= 0 ; j--){
            if(datos[j] < datos[j-1]){
                intercambiar(j, j-1);
            } else {
                break;
            }
        }
    }
}

void Arreglo::merge_sort(int inicio, int fin){
    int mitad;
    if(inicio < fin){
        mitad = (inicio + fin) / 2;
        merge_sort(inicio, mitad);
        merge_sort(mitad+1, fin);
        mezcla(inicio, mitad, fin);
    }
}

void Arreglo::mezcla(int inicio, int mitad, int fin){
    int i, j, k;
    
    i = inicio;
    j = mitad + 1;
    k = inicio;

    while( i <= mitad && j <= fin){
        if(datos[i] < datos[j]){

        }
    }
}