3:04 PM
Done
Code Send Me

Sarika Talaviya
3:05 PM
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

main()
{

    Node *ptr = NULL;
    // create a First Node
    Node *HEAD = new Node();
    HEAD->data = 10;
    HEAD->next = NULL;

    ptr = HEAD;
    Node *current = new Node();
    current->data = 20;
    current->next = NULL;
    HEAD->next = current;

    current = new Node();
    current->data = 30;
    current->next = NULL;
    HEAD->next->next = current;

    current = new Node();
    current->data = 40;
    current->next = NULL;
    HEAD->next->next->next = current;

    while (ptr != NULL)
    {
        cout << ptr->data << endl; // 10
        ptr = ptr->next;
    }

    // cout << "Head" << HEAD << endl;
    // cout << "First Node:" << HEAD->data << " " << HEAD->next << endl;
    // cout << "Second Node:" << current->data << " " << HEAD->next->next << endl;
    // cout << "Third Node:" << current->data << " " << HEAD->next->next->next << endl;

    return 0;
}

// head  10 1000 20 null 30
//  20 2000  30 3000 40 NULL



#include <iostream>
using namespace std;
class stack
{
public:
    int capacity;
    int *arr;
    int top;
    int count;
    stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[this->capacity];
        top = -1;
        this->count = 0;
    }
    ~stack()
    {
        delete[] arr;
    }

    void push(int element)
    {
        if (this->top == this->capacity - 1) // 4==4
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            this->top++;                    // 01
            this->arr[this->top] = element; // 10 20 30
            this->count++;                  // 1
        }
    }
    void pop()
    {
        if (this->top == -1)
        {
            printf("Stack is Empty");
        }
        else
        {
            this->top--;
            cout << "Element poped" << endl;
            this->count--;
        }
    }
    void Display()
    {
        if (this->top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    void peek()
    {

        if (this->top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Peek:" << arr[this->top] << endl;
        }
    }
    void isEmpty()
    {
        if (this->top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack is not Empty" << endl;
        }
    }
    void isFull()
    {
        if (this->top == this->capacity - 1)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            cout << "Stack is not full" << endl;
        }
    }
    void size()
    {
        cout << "Stack size:" << this->count << endl;
    }
};
main()
{
    int choice, size, element;
    cout << "Enter Size:";
    cin >> size;
    stack s(size);
    do
    {
        cout << "1.push" << endl;
        cout << "2.pop" << endl;
        cout << "3.peek" << endl;
        cout << "4.display" << endl;
        cout << "5.isEmpty" << endl;
        cout << "6.isFull" << endl;
        cout << "7.size" << endl;
        cout << "0.exit" << endl;
        cout << "Enter Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element:";
            cin >> element;
            s.push(element); // 10
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.Display();
            break;
        case 5:
            s.isEmpty();
            break;
        case 6:
            s.isFull();
            break;
        case 7:
            s.size();
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }

    } while (choice != 0);
}