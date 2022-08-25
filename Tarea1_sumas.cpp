#include <iostream>

using namespace std;

//Suma Iterativa
unsigned long long suma_iterativa(int n){
    int suma = 0;

    //Si n es mayor a 0, suma todos los numeros de 0 a n
    //mediante un for loop
    if(n > 0){
        for (int i = 0; i <= n; i++)
        {
            suma += i;
        }
        return suma;
    } else {
        return 0;
    }
}

//Suma recursiva
unsigned long long suma_recursiva(int n){

    //Caso base n==1, regresa 1
    if(n == 1){
        return 1;
    } else {
        //Recursividad. Si n > 1, suma n a la suma recursiva del numero anterior
        return n + suma_recursiva(n-1);
    }
}

//Suma directa
unsigned long long suma_directa(int n){
    int suma = 0;

    //Ecuacion de gauss para la suma de todos los numeros de 0 a n
    suma = (n*(n+1))/2;
    return suma;
}

//Funcion main
int main(){
    string ans;
    int n;
    int suma;

    //Menu de las diferentes sumas
    cout << "Sumas: " << endl;
    cout << "a) Suma Iterativa" << endl;
    cout << "b) Suma Recursiva" << endl;
    cout << "c) Suma Directa" << endl;

    //Lectura de datos de entrada
    cin >> ans;

    cout << "Numero: " << endl;
    cin >> n;

    //Ejecucion de sumas dependiendo de los datos de entrada
    if (ans == "a" || ans == "A"){
        suma = suma_iterativa(n);
    } else if(ans == "b" || ans == "B"){
        suma = suma_recursiva(n);
    } else if(ans == "c" || ans == "B"){
        suma = suma_directa(n);
    }

    //Muestra de resultado
    cout << "La suma es: " << suma << endl;

    return 0;
};