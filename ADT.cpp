#include <iostream>
#include <fstream>

using namespace std;

#define MAX 50

class Arreglo{
    private:
        int datos[MAX];
        int tam = 0;
    public:
        void insertar(int dato){
            if (tam < MAX){
                datos[tam] = dato;
                tam++;
            }
            else{
                cout << "Este arreglo ya esta lleno, no se puede insertar el dato" << endl;
            }
        }
        int borrar(){
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
        void imprimir(){
            for(int i = 0; i < tam; i++){
                cout << datos[i] << " ";
            }
            cout << endl;
        }
        void leer(string archivo){
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
};

int main(){
    Arreglo miArreglo;
    int dato;
    
    miArreglo.leer("numeros.txt");
    cout << "Los numeros leidos son: ";
    miArreglo.imprimir();
    dato = miArreglo.borrar();
    cout << "El elemento buscado es: " << dato << endl;
    cout << "El nuevo arreglo es: ";
    miArreglo.imprimir();
}