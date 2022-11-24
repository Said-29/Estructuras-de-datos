// Actividad 4_3
// Codigo creado por
// A01254229 Daniela Montserrat Ruiz Garcia
// A01254336 Kevin Alexis Valdez Zamora
// A01252477 Jordan Said Barba Lopez
// 20 de noviembre de 2022
// TC1031

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <string>
using namespace std;

class Grafo {
    private:
        int Vertices;                   // Cantidad de vertices
        vector<vector<int>> listAdj;    // No DAG como lista Adyacente

    public:
        Grafo(int v);                               // Constructor
        void loadGraph(int, vector<string>); // Crea la listAdj
        void add_edge(int, int);
        void imprimeListaAdj();                     // Imprime nuestro grafo ListAdj
        vector<bool> ruta(int, int);                // Recorrer n posiciones
        void ruta_recursivo(int, int, int, int, vector<bool>&);
};

Grafo::Grafo(int v) {
    Vertices = v;       // Numero de Vertices
    listAdj.resize(v);  // Crea el tamano de la lista adyacente
}

// Esta funcion se encarga de insertar los vertices y adyacentes 
// dado a nuestras listas
// Complejidad O(1) ya que es constante y no se basa en bucles
void Grafo::loadGraph(int conexiones, vector<string> puertos) {
    string vertice, adyacente;
    int vertice_i, adyacente_i = -1;
    string conexion;
    for(int i = 0; i < conexiones; i++){
        vertice_i = -1;
        adyacente_i = -1;
        cout << "Conexion: ";
        cin >> conexion;

        stringstream ss(conexion);
        getline(ss, vertice, '-');
        getline(ss, adyacente, '-');

        for(int i = 0; i < puertos.size(); i++){
            if(vertice == puertos[i]){
                vertice_i = i;
            } else if(adyacente == puertos[i]){
                adyacente_i = i;
            } 
        }

        if(vertice_i == -1 || adyacente_i == -1){
            cout << "Algun vertice es invalido" << endl;
            i--;
        } else {
            add_edge(vertice_i, adyacente_i);
            cout << "Added" << endl;
        }
    }
}

void Grafo::add_edge(int adyacente, int vertice){
    listAdj[vertice].push_back(adyacente);
    listAdj[adyacente].push_back(vertice);
}

// Imprimir la lista de adyacencia
void Grafo::imprimeListaAdj() {
    for (int j = 0; j < Vertices; j++) {
        cout << j << ":";
        for (auto adyacente : listAdj[j]) { 
            cout << " --> " << adyacente;
        }
        cout << endl;
    }
}

vector<bool> Grafo::ruta(int inicio, int MNP){
    vector<bool> visitado;
    visitado.resize(Vertices, false);

    ruta_recursivo(inicio,0,inicio,MNP, visitado);

    return visitado;
}

void Grafo::ruta_recursivo(int inicio, int count, int first, int MNP, vector<bool> &visitado){
    if(count != MNP){
        for(int i = 0; i <listAdj[inicio].size() ;i++){
            if(visitado[listAdj[inicio][i]] != true){
                cout << listAdj[inicio][i] << " ";
                visitado[listAdj[inicio][i]] = true;
            }
            ruta_recursivo(listAdj[inicio][i], count+1,first,MNP, visitado);
        }
    } 
}

int main() {
/* 
    0 alexandria 
    1 algeciras
    2 ambarli
    3 Antwerp
    4 balboa
    5 bandar
    6 barcelona
    7 bremen
    8 busan
    9 cai_Mep
    10 callao
    11 cartagena
    12 charleston

    Alexandria - Algeciras    0 - 1
    Algeciras - Ambarli       1 - 2
    Ambarli - Antwerp         2 - 3
    Alexandria - Balboa       0 - 4
    Balboa - Bandar           4 - 5
    Bandar - Barcelona        5 - 6
    Antwerp - Bremen          3 - 7
    Bremen - Busan            7 - 8
    Algeciras - Cai_Mep       1 - 9
    Cai_Mep - Callao          9 - 10
    Ambarli - Cartagena       2 - 11
    Barcelona - Callao        6 - 10
    Cai_Mep - Cartagena       9 - 11
    Callao - Charleston       10 - 12
    Cartagena - Charleston    11 - 12
    Charleston - Busan        12 - 8
 */

    Grafo objGrafo(13); // 13 Vertices
    vector<string> puertos = {"Alexandria", "Algeciras", "Ambarli",  "Antwerp", "Balboa", "Bandar", "Barcelona", "Bremen", "Busan", "Cai_Mep", "Callao", "Cartagena", "Charleston"};
    string puerto;
    int inicio;
    int conexiones;
    cout << "Conexiones: ";
    cin >> conexiones;

    objGrafo.loadGraph(conexiones, puertos);
    objGrafo.imprimeListaAdj();
    cout << endl;

    int NQ;
    cout << "NQ: ";
    cin >> NQ;

    vector<bool> visited;
    vector<string> ans;

    for(int i = 0; i < NQ; i++){
        cout << "\nDesde que puerto quiere comenzar el viaje?: ";
        cin >> puerto;

        for(int j = 0; j < 13; j++){
            if(puertos[j] == puerto){
                inicio = j;
                break;
            }
        }

        int MNP;
        cout << "\nMNP: ";
        cin >> MNP;

        cout << "\nViaje realizado desde el puerto " << puertos[inicio] << " con un MNP de " << MNP << " :\n";

        visited.resize(13, false);
        visited = objGrafo.ruta(inicio, MNP);

        int count = 0;
        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == false){
                count ++;
            }
        }
        cout << endl;

        string var = "Case " + to_string(i+1) + ": " + to_string(count) + " puertos no alcanzables desde el puerto " + puertos[inicio] + " con MNP = " + to_string(MNP);
        ans.push_back(var);
    }

    for(int i = 0; i < NQ; i++){
        cout << "\n" << ans[i];
    }

    return 0;
}