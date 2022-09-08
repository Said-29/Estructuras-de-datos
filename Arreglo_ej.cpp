#include <iostream>
#include <fstream>
#include "ADT_arreglo.h"

using namespace std;

int main(){
    Arreglo arr;
    arr.leer("numeros.txt");
    arr.imprimir();
    arr.quick_sort(0, arr.get_tam() - 1);
    arr.imprimir();
    return 0;
}