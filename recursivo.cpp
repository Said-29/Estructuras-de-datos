#include <iostream>
using namespace std;

unsigned long long factorial(int n){
    if (n == 0){
        return 1;
    }
    else{
        return (n*factorial(n-1));
    }
}

int main(){
    unsigned long long factor;
    factor = factorial(20);

    cout << "El factorial de 5 es: " << factor << endl;

    return 0;
}