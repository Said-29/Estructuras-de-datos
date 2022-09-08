#include <iostream>

using namespace std;

int main(){

    cout << "Ejercicio 1: " << endl;
    int a = 1, b=2;
    int *q = &b;
    int *p = &b;
    (*q)++;
    cout << b << " " << a << endl;

    cout << "Ejercicio 2: " << endl;
    a = 1, b = 2;
    p = &a;
    q = &b;
    (*q)++;
    cout << b << " " << a << endl;

    cout << "Ejercicio 3: " << endl;
    a = 10, b = 20;
    p = &a;
    q = p;
    *q += 30;
    cout << *p << " " << *q << endl;

    cout << "Ejercicio 4: " << endl;
    a = 10, b = 20;
    p = new int(5);
    q = &a;
    *q += 30;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete p;

    cout << "Ejercicio 5: " << endl;
    a = 10, b = 20;
    p = new int(5);
    q = p;
    *q += 30;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete q;

    cout << "Ejercicio 6: " << endl;
    a = 10, b = 20;
    p = new int(5);
    q = new int(10);
    *q += 30;
    b = *q + *p;
    cout << *p << " " << *q << " " << a << " " << b << endl;
    delete q;
    delete p;

    return 1;
}