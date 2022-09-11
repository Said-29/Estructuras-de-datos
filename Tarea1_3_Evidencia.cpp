#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iterator>
#include <Algorithm>

using namespace std;

int main(){
    //Definicion de variables
    string UBI, fecha, hora, puerto, archivo, strInput;
    map<string, string> dict_barcos;

    cout << "Nombre del archivo: " << endl;
    cin >> archivo;

    //Abrir archivo
    ifstream File(archivo);

    //Si archivo no existe, cerrar programa
    if(!File){
        cerr << "Archivo no encontrado" << endl;
        exit(1);
    }

    //Iterar sobre archivo
    while(File.is_open()){

        //Si se acaba el archivo cerrar loop
        if(File.eof()){
            break;
        }

        //Leer linea del archivo
        getline(File, strInput);

        //Separar linea leida, y guardar cada item en una variable
        stringstream ss(strInput);
        getline(ss, fecha, ' ');
        getline(ss, hora, ' ');
        getline(ss, puerto, ' ');
        getline(ss, UBI, ' ');

        //Guardar datos en diccionario/mapa
        dict_barcos[UBI] = fecha + " " + hora + " " + puerto;
    }

    //Cerrar archivo
    File.close();

    //Definir iterador de mapa en la posicion 0
    map<string, string>::iterator it = dict_barcos.begin();

    int count = 0;
    string dato1, dato2, dato3;
    map<string, string> aux_map;

    //Iterar sobre diccionario
    for(pair<string, string> item : dict_barcos){

        //Obtener clave 
        string word = item.first;

        //Obtener valor
        string datos = item.second;

        //Separar datos del valor
        stringstream ss(datos);
        getline(ss, dato1, ' ');
        getline(ss, dato2, ' ');
        getline(ss, dato3, ' ');

        //Mostrar datos
        cout << word << " :: " << dato1 << "," << dato2 << "," << dato3 << endl;
        count++;
    }

    return 0;
}