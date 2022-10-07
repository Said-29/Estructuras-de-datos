#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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

//Muestra todos los barcos
void show(vector<vector<string>> &barcos){
    for(int i = 0; i < barcos.size(); i++){
        cout << "Clave: " << barcos[i][0] << " || Fecha: " << barcos[i][1] << endl;
    }
}

//Muestra la clave y la fecha del barco en cierta posicion
void show_barco(vector<vector<string>> &barcos, int pos){
    cout << "Clave: " << barcos.at(pos)[0] << " || Fecha: " << barcos.at(pos)[1] << endl;
}

int binary_search(vector<vector<string>> &barcos, string CLAVE){
    int bajo, central, alto; 
    string valor_central;

    bajo = 0;
    alto = barcos.size() - 1;

    while(bajo <= alto){
        central = (bajo+alto)/2;
        valor_central = barcos[central][0];
        valor_central.resize(3);
        if(valor_central == CLAVE){
            return central;
        } else if (valor_central < CLAVE){
            bajo = central + 1;
        } else {
            alto = central - 1;
        }
    }
    
    return -1;
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

int main(){
    string archivo;
    vector<vector<string>> barcos;

    cout << "Nombre del archivo: " << endl;
    cin >> archivo;

    leer(archivo, barcos);
    bubble_sort(barcos);

    string clave, aux_clave;
    vector<vector<string>> aux_barcos;
    int count = 1;

    cout << "UBI (3 caracteres): " << endl;
    cin >> clave;

    int pos = binary_search(barcos, clave);

    cout << pos << endl;
    show(barcos);
    
    if(pos == -1){
        cout << "Barco no encontrado!" << endl;
        exit(0);
    }

    aux_barcos.push_back(barcos[pos]);

    if(pos != 0){
        aux_clave = barcos[pos-count][0];

        while(aux_clave.substr(0, 3) == clave){
            aux_barcos.push_back(barcos[pos-count]);
            count ++;
            aux_clave = barcos[pos-count][0];
        }
    }
    count = 1;
    aux_clave = barcos[pos+count][0];

    while(aux_clave.substr(0, 3) == clave){
        aux_barcos.push_back(barcos[pos+count]);
        count ++;
        aux_clave = barcos[pos+count][0];
    }

    bubble_sort(aux_barcos);
    sort_by_date(aux_barcos);

    for(int i = 0; i < aux_barcos.size(); i++){
        show_barco(aux_barcos, i);
    }

    return 0;
}