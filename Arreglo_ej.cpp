#include <iostream>
#include <fstream>
#include "ADT_arreglo.h"

using namespace std;

int main(){

    Arreglo arr;
    arr.leer("numeros.txt");
    arr.insertion_sort();
    arr.imprimir();
    return 0;
}