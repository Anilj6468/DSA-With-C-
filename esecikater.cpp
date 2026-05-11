#include <iostream>
using namespace std;

// Base Class (Inheritance)
class StackBase {
protected:
    int top;
    int size;

public:
    StackBase(int s) {
        size = s;
        top = -1;
    }

    // Encapsulation
    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }
};

// Derived Class (Inheritance)
class Stack : public StackBase {
private:
    int *arr;

public:
    // Constructor
    Stack(int s) : StackBase(s) {
        arr = new int[size];
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Polymorphism (Virtual Function)
    virtual void push(int value) {
        if (isFull()) {
            cout << "Stack is Full!\n";
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
        } else {
            cout << arr[top--] << " popped from stack.\n";
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!\n";
        } else {
            cout << "Top Element: " << arr[top] << endl;
        }
    }

    void checkEmpty() {
        if (isEmpty())
            cout << "Stack is Empty.\n";
        else
            cout << "Stack is NOT Empty.\n";
    }

    void checkFull() {
        if (isFull())
            cout << "Stack is Full.\n";
        else
            cout << "Stack is NOT Full.\n";
    }
};

// Main Function
int main() {
    int stackSize;

    cout << "Enter Stack Size: ";
    cin >> stackSize;

    Stack s(stackSize);

    int choice, value;

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Display Top Element\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.checkEmpty();
            break;

        case 5:
            s.checkFull();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}