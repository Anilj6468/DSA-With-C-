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
xax-vfdd-hvk