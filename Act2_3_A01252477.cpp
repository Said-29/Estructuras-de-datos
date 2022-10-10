//Librerias
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "ADT_LinkedList.h"

using namespace std;

//Intercambiar la posicion de dos pointers
void intercambiar_p(vector<string> *a, vector<string> *b){
    vector<string> temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//O(n^2)
//Ordenamiento por el metodo de burbuja bandera
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

//Leer los datos de un archivo, e insertarlos en un vector
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

//Ordenamiento por fecha utilizando selection sort
void sort_by_date(vector<vector<string>> &aux_barcos) {
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

//Muestra los datos de los barcos
void show(vector<vector<string>> &barcos){
    for(int i = 0; i < barcos.size(); i++){
        cout << "Clave: " << barcos[i][0] << " || Fecha: " << barcos[i][1] << " || Puerto: " << barcos[i][3] << endl;
    }
}

//Busca barcos por clave y regresa una lista con ellos
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

//Muestra la cantidad de barcos con UBI x, por mes
void show_by_month(LinkedList<vector<string>> &barcos_M, LinkedList<vector<string>> &barcos_R){
    string clave; // variable para la UBI
    string mesesNum[] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"}; // numero de cada mes
    string meses[] = {"JAN", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DIC"}; // texto de cada mes
    int year = 20;

    cout << "Clave: ";
    cin >> clave; // Pide la clave a buscar

    // Busca todos los barcos que coincidan con esa clave por cada entrada (M y R)
    LinkedList<vector<string>> barcos_clave_M = search_by_key(barcos_M, clave);
    LinkedList<vector<string>> barcos_clave_R = search_by_key(barcos_R, clave);

    int total_barcos = barcos_clave_M.size() + barcos_clave_R.size(); // suma el total de barcos de cada entrada
    int count_M = 0, count_R = 0; // se inicializa un contador de los barcos de cada entrada por mes

    cout << setw(8) << "Mes" << setw(8) << "Year" << setw(8) << "cant-M" << setw(8) << "cant-R" << endl;

    // Se repite por cada mes del año 
    for (int k = 0; k < 12; k++)
    {
        count_M = 0;
        count_R = 0;
        
        // busca cada barco por mes y lo va sumando a su contador (entrada M)
        for(int i = 0; i < barcos_clave_M.size(); i++){
            string fecha = (barcos_clave_M.get(i)-> info)[1];
            string fecha_new = fecha.substr(3,2);
            if (fecha_new == mesesNum[k]){
                count_M++;
            }       
        }
        
        // busca cada barco por mes y lo va sumando a su contador (entrada R)
        for(int j = 0; j < barcos_clave_R.size(); j++){
            string fecha = (barcos_clave_R.get(j)-> info)[1];
            string fecha_new = fecha.substr(3,2);
            if (fecha_new == mesesNum[k]){
                count_R++;
            }       
        }

        // Imprime los datos del mes, anio, y cantidad de barcos por cada entrada ese mes
        cout << setw(8) << meses[k] << setw(8) << year << setw(8) << count_M << setw(8) << count_R << endl;
    }
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

    //Ordena los barcos por puerto en dos listas ligadas
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