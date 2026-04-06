#include <iostream>
using namespace std;

#define MAX 50
int arr[MAX], n = 0;

void insert() {
    int value, pos;
    cout << "Enter Value:";
    cin>>value;
    cout<< "Enter Position:";
    cin>>pos;//2
    if(pos<0||pos>n)//2<0 ||2>5
    {
        cout << "Invalid Position" << endl;
        return;
    }

    for (int i = n; i > pos;i--)
    {
     arr[i] = arr[i - 1]; 
    }
    arr[pos] = value;
    n++;
}

void display(){
    if(n==0){
        cout << "Array is empty" << endl;
    }
    cout << "Elements:" << endl;
    for (int i = 0; i < n; i++){
        cout << endl << arr[i] << endl;
    }
}

void update(){
    int value, pos;
    cout << "Enter value:";
    cin >> value;
    arr[pos] = value;
    cout << "Update Successfully" << endl;
}

void deleteElement(){
    int pos;

    cout << "Enter Position:";
    cin >> pos;

    if(pos<0 || pos>=n){
        cout << "Invalid Index" << endl;
        return;
    }

    for (int i = 0; i < n - 1;i++){
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Delete Success" << endl;
}

int main(){
    int choice;

    while(1){
        cout << "1.Insert" << endl;
        cout << "2.Display" << endl;
        cout << "3.Update" << endl;
        cout << "4.Delete" << endl;
        cout << "5.Insert" << endl;
        cout << "Enter Choice:" << endl;
    }

    switch(choice){
        case 1:
        insert();
        break;

        case 2:
        display();
        break;

        case 3:
        update();
        break;

        case 4:
        deleteElement();
        break;

        case 5:
        return 0;
        break;
        default:
            cout << "Invalid Choice" << endl;
    }

return 0;

};
