#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(int value) {
    if (head == NULL) return;

    if (head->data == value) {
        head = head->next;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next != NULL)
        temp->next = temp->next->next;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


void merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[100];

    while (i <= m && j <= r) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (int i = l; i <= r; i++)
        arr[i] = temp[i - l];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}


int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert in Linked List\n";
        cout << "2. Delete from Linked List\n";
        cout << "3. Display Linked List\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Binary Search\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 4 && choice <= 6) {
            int n, arr[100];
            cout << "Enter number of elements: ";
            cin >> n;

            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            if (choice == 4) {
                mergeSort(arr, 0, n - 1);
                cout << "Sorted using Merge Sort:\n";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
            }

            else if (choice == 5) {
                quickSort(arr, 0, n - 1);
                cout << "Sorted using Quick Sort:\n";
                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
            }

            else if (choice == 6) {
                mergeSort(arr, 0, n - 1);
                int key;
                cout << "Enter value to search: ";
                cin >> key;

                int result = binarySearch(arr, n, key);

                if (result != -1)
                    cout << "Element found at index: " << result;
                else
                    cout << "Element not found";
            }
            cout << endl;
        }

        else if (choice == 1) {
            int value;
            cout << "Enter value: ";
            cin >> value;
            insert(value);
        }

        else if (choice == 2) {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(value);
        }

        else if (choice == 3) {
            display();
        }

    } while (choice != 0);

    return 0;
}