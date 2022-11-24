#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Grafo {
    private:
        int Vertices;                   // Cantidad de vertices
        int Arcos;
        vector<vector<int>> listAdj;    // No DAG como lista Adyacente

    public:
        Grafo(int v);                               // Constructor
        void loadGraph(int); // Crea la listAdj
        void add_edge(int, int);
        void imprimeListaAdj();                     // Imprime nuestro grafo ListAdj
        bool is_tree();
        void topological_sort();
        void topologicalSortUtil(int, bool[], stack<int>&);
        bool bipartite_graph();
};

Grafo::Grafo(int v) {
    Vertices = v;       // Numero de Vertices
    listAdj.resize(v);  // Crea el tamano de la lista adyacente
}

void Grafo::loadGraph(int conexiones){
    int v, a;
    for(int i = 0; i < conexiones; i++){
        v = 0;
        a = 0;

        cout << "Vertice: ";
        cin >> v;

        cout << "Adyacente: ";
        cin >> a;

        add_edge(v, a);
    }
}

void Grafo::add_edge(int vertice, int adyacente){
    listAdj[vertice].push_back(adyacente);
    Arcos++;
}

void Grafo::imprimeListaAdj() {
    for (int j = 0; j < Vertices; j++) {
        cout << j << ":";
        for (auto adyacente : listAdj[j]) { 
            cout << " --> " << adyacente;
        }
        cout << endl;
    }
}

bool Grafo::is_tree(){
    return((Arcos<Vertices) ? true: false);
}

void Grafo::topologicalSortUtil(int v, bool visited[], stack<int>& Stack){

    visited[v] = true;
 
    vector<int>::iterator i;
    for (i = listAdj[v].begin(); i != listAdj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    Stack.push(v);
}
 
void Grafo::topological_sort()
{
    stack<int> Stack;
 
    bool* visited = new bool[Vertices];
    for (int i = 0; i < Vertices; i++)
        visited[i] = false;
 

    for (int i = 0; i < Vertices; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
     
    delete [] visited;
}

bool Grafo::bipartite_graph(){

    vector<int> col(Vertices, -1);
 
    queue<pair<int, int> > q;
   
    for (int i = 0; i < Vertices; i++) {  
        if (col[i] == -1) {       
            q.push({ i, 0 });
            col[i] = 0;          
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                int v = p.first;
                int c = p.second;          
                for (int j : listAdj[v]) {
                    if (col[j] == c)
                        return 0;
                    if (col[j] == -1) {
                        col[j] = (c) ? 0 : 1;
                        q.push({ j, col[j] });
                    }
                }
            }
        }
    }
    return 1;
}