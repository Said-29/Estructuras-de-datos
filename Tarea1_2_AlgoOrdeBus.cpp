#include <iostream>
#include <fstream>
#include "ADT_arreglo.h"

using namespace std;

int main(){
    int ans;
    string archivo_datos;
    Arreglo arr;

    cout << "Opciones: " << endl;
    cout << "1) Ordenar" << endl;
    cout << "2) Buscar" << endl;

    cin >> ans;

    cout << "Ingrese la direccion al archivo con los datos: " << endl;
    cin >> archivo_datos;
    arr.leer(archivo_datos);

    if(ans == 1){
        cout << "Opciones: " << endl;
        cout << "1) Insertion sort" << endl;
        cout << "2) Bubble sort" << endl;
        cout << "3) Merge sort" << endl;

        cin >> ans;

        switch (ans)
        {
        case 1:
            arr.insertion_sort();
            break;
        case 2:
            arr.bubble_sort();
            break;
        case 3:
            arr.merge_sort(0, arr.get_tam() - 1);
            break;
        default:
            break;
        }  
        cout << "Lista de datos ordenados: " << endl;
        arr.imprimir();

    } else if(ans == 2){
        int num, pos, num_busq;

        cout << "Cantidad de busquedas: " << endl;
        cin >> num_busq;

        while(num_busq > 0){
            cout << "Numero a buscar: " << endl;
            cin >> num;

            cout << "Opciones: " << endl;
            cout << "1) Sequential search" << endl;
            cout << "2) Binary search" << endl;

            cin >> ans;

            switch (ans)
            {
            case 1:
                pos = arr.sequential_search(num);
                cout << "Lista de datos: " << endl;
                arr.imprimir();
                cout << "Posicion: " << endl;            
                cout << pos+1 << endl;
                break;
            case 2:
                arr.merge_sort(0, arr.get_tam()-1);
                pos = arr.binary_search(num);
                cout << "Lista de datos: " << endl;
                arr.imprimir();
                cout << "Posicion: " << endl;
                cout << pos+1 << endl;
                break;
            default:
                break;
            }
            num_busq--;
        }
    }

    return 0;
}