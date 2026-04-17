#include <iostream>
using namespace std;

void sum(int a, int b){
    cout << "Sum is: " << (a + b) << endl;
}

void sub(int a, int b){
    cout << "Sub is:" << (a-b) << endl;
}

int main(){
    int a = 20, b = 25;
    sum(a, b);
    sub(a, b);
    return 0;
}

