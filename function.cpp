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