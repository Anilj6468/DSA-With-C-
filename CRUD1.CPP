#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Linked List Class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Append (Insert at end)
    void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Display List
    void display() {
        Node* temp = head;

        if (temp == NULL) {
            cout << "List is empty\n";
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Insert at Beginning
    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);

        newNode->next = head;
        head = newNode;
    }

    // Search element
    void search(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element found at position: " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Element not found\n";
    }

    // Delete by value
    void delete_node(int key) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        // If head node itself holds the key
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted: " << key << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value not found\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Deleted: " << key << endl;
    }

    // Reverse Linked List
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while (current != NULL) {
            next = current->next; 
            current->next = prev;  
            prev = current;        
            current = next;      
        }

        head = prev;
        cout << "List reversed successfully\n";
    }
};

// Main Function (Driver Code)
int main() {
    LinkedList list;

    // Append elements
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Initial List:\n";
    list.display();

    // Insert at beginning
    list.insert_at_beginning(5);
    cout << "\nAfter inserting at beginning:\n";
    list.display();

    // Search element
    cout << "\nSearching 20:\n";
    list.search(20);

    // Delete node
    cout << "\nDeleting 20:\n";
    list.delete_node(20);
    list.display();

    // Reverse list
    cout << "\nReversing List:\n";
    list.reverse();
    list.display();

    return 0;
}