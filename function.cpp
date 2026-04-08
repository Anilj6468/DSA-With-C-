#include <iostream>
using namespace std;

int main(){
    int a=20, b=5;
    char ope;
    cout << "Enter Operator:";
    cin>>ope; //+
    
    switch(ope){
        case '+';
        cout << "Sum:" << a+b;
        break;
        case '-';
        cout << "Sub:" << a-b;
        break;
        case '*';
        cout << "Mul:" << a*b;
        break;
        case '/';
        cout << "Div:" << a/b;
        break;
        default:
        cout << "Invalid";
    }
    
    // int a=2;
    // switch(a){
    //     case 1:
    //     cout << "One:";
    //     break;
    //     case 2:
    //     cout << "Two:";
    //     break;
    //     case 3:
    //     cout << "Three:";
    //     break;
    //     case 4:
    //     cout << "Four:";
    //     break;
    //     default:
    //     cout << "Invalid";
        
    // }
        return 0;
}