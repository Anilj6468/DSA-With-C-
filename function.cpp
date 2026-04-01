// Take Nothing Return something

#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a + b; 
}

int main() {
    int value = sum(3, 6);
    cout << "Addition is " << value << endl;
    return 0;
};

// Take Something Return something

#include <iostream>
using namespace std;

int sum(int a, int b) {  
    return a + b;        
}

int main() {
    int result = sum(5, 7);  
    cout << "Sum is: " << result << endl; 
    return 0;
};

// Take Nothing Return Nothing

#include <iostream>
using namespace std;

void display() {  
    cout << "Hello, C++!" << endl;
}

int main() {
    display(); 
    return 0;
};

// nested function

#include <iostream>
using namespace std;

void anil() {  
    cout << "I am Anil\n";
    cout << "I am Anil\n";
}
void shyam(){
    cout << "I am Shayam\n";
    anil();
    anil();
    anil();
}
int main(){
    shyam();
    return 0;
};

#include <iostream>
using namespace std;

void sum(int a, int b){
    cout << (a+b);
}
returntype int main(){
    cout << "Addition is" << a+b;
    return 0;
};