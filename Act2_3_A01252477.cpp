#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "ADT_LinkedList.h"

using namespace std;

void intercambiar_p(vector<string> *a, vector<string> *b){
    vector<string> temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(vector<vector<string>> &barcos){
    bool interruptor = true;

    for(int i = 0;i < barcos.size()-1 && interruptor; i++){
        interruptor = false;

        for(int j = 0; j<barcos.size()-1-i; j++){

            if(barcos[j+1][0]<barcos[j][0]){
                intercambiar_p(&barcos[j], &barcos[j+1]);
                interruptor = true;
            }

        }
    }
}

void leer(string archivo, vector<vector<string>> &barcos){
    string strInput, fecha, hora, puerto, UBI;
    stringstream ss;
    vector<string> aux_vec;

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

        aux_vec = {UBI, fecha, hora, puerto};

        barcos.push_back(aux_vec);
    }

    //Cerrar archivo
    File.close();
}

void sort_by_date(vector<vector<string>> &aux_barcos) {
    // Usando selection sort
    int menor;
    for(int i = 0; i <= aux_barcos.size(); i++) {
        menor = i; // Asignamos la posicion actual como la menor

        // Este FOR se repite en j hasta el final del arreglo por cada i
        for(int j = i + 1; j < aux_barcos.size(); j++) {

            // Comparamos si el dato en la pos j es menor al dato menor actual
            // En caso de ser lo, la pos menor es ahora j
            if((aux_barcos[j][0] == aux_barcos[menor][0]) && (aux_barcos[j][1] < aux_barcos[menor][1])) {
                menor = j;
            }

        }
        // Cada vez que el for anidado da una vuelta se hace el intercambio
        // de elementos, sustituyendo el objeto en la pos i actual por uno menor 
        // que se ha encontrado
        vector<string> temp;
        temp = aux_barcos[i];
        aux_barcos[i] = aux_barcos[menor];
        aux_barcos[menor] = temp;
    }
}

void show(vector<vector<string>> &barcos){
    for(int i = 0; i < barcos.size(); i++){
        cout << "Clave: " << barcos[i][0] << " || Fecha: " << barcos[i][1] << " || Puerto: " << barcos[i][3] << endl;
    }
}

LinkedList<vector<string>> search_by_key(LinkedList<vector<string>> &barcos, string clave){
    LinkedList<vector<string>> aux_barcos;
    bool found = false;
    int count = 0;
    for (int i = 0; i < barcos.size(); i++){
        string barcos_key = (barcos.get(i) -> info)[0]; 
        barcos_key.resize(3);
        if(barcos_key == clave){
            aux_barcos.add(barcos.get(i) -> info);
            found = true;
        } else {
            found = false;
        }
        if(count > 0 && found == false){
            return aux_barcos;
        }
    }
    return aux_barcos;
}

void show_by_month(LinkedList<vector<string>> &barcos_M, LinkedList<vector<string>> &barcos_R){
    string clave;

    cout << "Clave: " << endl;
    cin >> clave;

    LinkedList<vector<string>> barcos_clave_M = search_by_key(barcos_M, clave);
    LinkedList<vector<string>> barcos_clave_R = search_by_key(barcos_R, clave);

    int total_barcos = barcos_clave_M.size() + barcos_clave_R.size();
    int count_M, count_R = 0;

    for(int i = 0; i < barcos_clave_M.size(); i++){
        string fecha = (barcos_clave_M.get(i)-> info)[1];
        string fecha_new = fecha.substr(3,2);
        if (fecha_new == "01"){
            count_M++;
        }       
    }

    for(int i = 0; i < barcos_clave_R.size(); i++){
        string fecha = (barcos_clave_R.get(i)-> info)[1];
        string fecha_new = fecha.substr(3,2);
        if (fecha_new == "01"){
            count_R++;
        }       
    }

    cout << "JAN " << total_barcos << " " << count_M << " " << count_R << endl; 
}

int main(){
    string archivo;
    vector<vector<string>> barcos;
    LinkedList<vector<string>> barcos_M, barcos_R; 

    cout << "Nombre del archivo: " << endl;
    cin >> archivo;

    leer(archivo, barcos);
    bubble_sort(barcos);
    sort_by_date(barcos);

    for(int i = 0; i < barcos.size(); i++){
        vector<string> aux;
        aux = barcos[i];
        if(aux[3] == "M"){
            barcos_M.add(aux);
        } else {
            barcos_R.add(aux);
        }
    }

    show_by_month(barcos_M, barcos_R);

    return 0;
}