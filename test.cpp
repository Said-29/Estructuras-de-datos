#include <iostream>
#include "ADT_BST.h"
using namespace std;

int main(){
    BST<int> data;
    int ans;
    data.add(50);
    data.add(30);
    data.add(65);
    data.add(10);
    data.add(45);
    data.add(70);
    data.add(60);
    cout << "Numero: " << endl;
    cin >> ans;
    cout << "El nivel de " << ans << " es: " << data.level(ans) << endl;
    return 0;
}