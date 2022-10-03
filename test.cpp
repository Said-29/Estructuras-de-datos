#include <iostream>
#include "ADT_Stack.h"
#include "ADT_Queue.h"
using namespace std;

int main(){
    Stack<int> data;
    data.push(1);
    data.push(2);
    data.push(3);
    data.show();
    cout << "_____________" << endl;
    data.pop();
    data.show();
    return 0;
}