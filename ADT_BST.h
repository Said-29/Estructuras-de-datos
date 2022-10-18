#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template <class T>
class NodeT{
    private:
        T data;
        NodeT<T> *left, *right;
    public:
        NodeT();
        NodeT(T);
      	T get_data(){return data;};
        void set_data(T v){data = v;};
        NodeT<T> *get_left(){return left;};
        void set_left(NodeT<T> *n){left = n;};
        NodeT<T> *get_right(){return right;};
        void set_right(NodeT<T> *n){right = n;};
        void show();
};

template <class T>
NodeT<T>::NodeT(){
    left = right = nullptr;
}

template <class T>
NodeT<T>::NodeT(T v){
    data = v;
    left = right = nullptr;
}

template <class T>
void NodeT<T>::show(){
    cout << data << endl;
}

template <class T>
class BST{
    private:
        NodeT<T> *root;
    public:
        BST();
        BST(T);
        bool search(T);
        void add(T);
        void show();
        NodeT<T> *get_root();
        void del(T);
        void fill(string);
        void visit();
        int height();
        int height_r(NodeT<T>*);
        void ancestors(T);
        bool ancestors_r(NodeT<T>*, T);
        int level(T);
        int level_r(NodeT<T>*, T, int);
        void preorden(NodeT<T>*);
        void inorden(NodeT<T>*);
        void postorden(NodeT<T>*);
        void Level_by_level();
        void Level_by_level_r(NodeT<T>*, int);
};

template <class T>
NodeT<T>* BST<T>::get_root(){
    return root;
}

template <class T>
BST<T>::BST(){
    root = nullptr;
}

template <class T>
BST<T>::BST(T v){
    root = new NodeT<T>(v);
}

template <class T>
void BST<T>::del(T dato){

}

template <class T>
bool BST<T>::search(T v){
    NodeT<T> *p;
    p = root;
    while(p != nullptr){
        if(p -> get_data() == v){
            return true;
        } else {
            if (p -> get_data() > v){
                p = p -> get_left();
            } else {
                p = p -> get_right();
            }
        }
    }
    return false;
}

template <class T>
void BST<T>::add(T v){
    NodeT<T> *nuevo = new NodeT<T>(v);
    NodeT<T> *aux;
    aux = root;

    if(aux == nullptr){
        root = nuevo;
        return;
    }
    
    while (aux != nullptr && aux -> get_data() != v){
        if (aux -> get_data() < v){
            if(aux -> get_right() == nullptr){
                aux -> set_right(nuevo);
                return;
            } else {
                aux = aux -> get_right();        
            }            
        } else {
            if(aux -> get_left() == nullptr){
                aux -> set_left(nuevo);
                return;
            } else {
                aux = aux -> get_left();  
            }
        }        
    }

    cout << "Este dato ya existe" << endl;
}

template <class T>
void BST<T>::fill(string file){
    int n;
    T dato;
    ifstream miArchivo(file);

    if(miArchivo.is_open()){
        miArchivo >> n;
        for(int i = 0; i < n; i++){
            miArchivo >> dato;
            add(dato);
        }
        miArchivo.close();
    } else {
        cout << "No se puede abrir el archivo" << endl;
    } 
}

template <class T>
void BST<T>::visit(){
    int ans;
    cout << "1) Preorder\n2) Inorder\n3) Postorder\n4) Level by level\n" << endl;
    cin >> ans;

    switch (ans){
    case 1:
        preorden(root);
        break;
    case 2:
        inorden(root);
        break;
    case 3:
        postorden(root);
        break;
    case 4:
        Level_by_level();
        break;
    default:
        break;
    }
}

template <class T>
int BST<T>::height(){
    return height_r(root);
}

template <class T>
int BST<T>::height_r(NodeT<T> *node){
    if(node == NULL){
        return 0;
    }
  	else{
    	int leftHeight = height_r(node->get_left());  
    	int rightHeight = height_r(node->get_right());
      	
		if(leftHeight > rightHeight){
            return (leftHeight + 1);
        }
        else {
            return(rightHeight + 1);
        }
    }
}

template <class T>
void BST<T>::ancestors(T dato){
    ancestors_r(root, dato);
}

template <class T>
bool BST<T>::ancestors_r(NodeT<T> *p, T dato){
    if (p == nullptr) {
        return false;
    }

    if (p-> get_data() == dato) {
        return true;
    }

    bool left = ancestors_r(p->get_left(), dato);

    bool right = false;
    if (!left) {
        right = ancestors_r(p->get_right(), dato);
    }
 
    if (left || right) {
        cout << p->get_data() << " ";
    }
 
    return left || right;
}

template <class T>
int BST<T>::level(T dato){
    int ans;
    ans = level_r(root, dato, 1);
    if(ans == 0){
        return -1;
    }
    return ans;
}

template <class T>
int BST<T>::level_r(NodeT<T> *p, T dato, int level){
    if (p == NULL){
        return 0;
    }

    if (p->get_data() == dato){
        return level;
    }

    int downlevel = level_r(p->get_left(), dato, level + 1);
    if (downlevel != 0){
        return downlevel;
    }

    downlevel = level_r(p->get_right(), dato, level + 1);

    return downlevel;
}

template <class T>
void BST<T>::preorden(NodeT<T> *p){
    if(p != nullptr){
        cout << p->get_data() << " ";
        preorden(p->get_left());
        preorden(p->get_right());
    }
}

template <class T>
void BST<T>::inorden(NodeT<T> *p){
    if (p == nullptr){
        return;
    }

    inorden(p -> get_left());

    cout << p -> get_data() << " ";

    inorden(p -> get_right());
}

template <class T>
void BST<T>::postorden(NodeT<T> *p){
    if (p == nullptr){
        return;
    }

    postorden(p -> get_left());
    postorden(p -> get_right());

    cout << p -> get_data() << " ";
}

template <class T>
void BST<T>::Level_by_level(){
    int altura = height(); 
    // El nivel de la raiz es cero
    for(int i = 0; i < altura; i++){ 
        Level_by_level_r(root, i); 
    }
}

template <class T>
void BST<T>::Level_by_level_r(NodeT<T> *p, int level){
    if(p == nullptr){
        return;
    }
    if(level == 0){
        cout << p->get_data() << " ";
    }
    else if(level > 0){
    	Level_by_level_r(p-> get_left(), level -1);
    	Level_by_level_r(p-> get_right(), level -1);
  }
}