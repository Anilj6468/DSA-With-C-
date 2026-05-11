2:47 PM
Done
2:51 PM
Madem aaj itna hi

Sarika Talaviya
2:56 PM
#include <iostream>
using namespace std;
#define MAX 5
class Queue
{
private:
    int front, rear, size;
    int *arr;
    int capacity;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[this->capacity];
        this->front = -1;
        this->rear = -1;
        this->size = 0;
    }
    ~Queue()
    {
        delete[] arr;
    }

    void enqueEle(int element)
    {
        if (this->rear == this->capacity - 1) // 0==4
        {
            cout << "Queue is Full" << endl;
        }
        else if (this->rear == -1 && this->front == -1) // 0==-1 && 0==-1
        {
            this->front = 0;
            this->rear = 0;
            this->arr[this->rear] = element; // 10 9
            this->size++;
        }
        else
        {
            this->rear++; // 0 1
            this->arr[this->rear] = element;
            this->size++;
        }
    }

    void deQueue()
    {
        if (this->rear == -1 && this->front == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        else if (this->front == this->rear)
        {
            this->front == -1;
            this->rear == -1;
            this->size--;
        }
        else
        {
            this->front++;
            this->size--;
        }
    }

    void getRear()
    {
        if (this->rear == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "Rear Element:" << this->arr[this->rear] << endl;
        }
    }

    void getfRONT()
    {
        if (this->front == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "fRONT  Element:" << this->arr[this->front] << endl;
        }
    }

    void isFull()
    {
        if (this->rear == this->capacity - 1)
        {
            cout << "Queue is Fill" << endl;
        }
        else
        {
            cout << "Queue is Not Full" << endl;
        }
    }

    void isEmpty()
    {
        if (this->front == -1 && this->rear == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "Queue is Not EMPTY" << endl;
        }
    }

    void getSize()
    {
        cout << "Size is:" << this->size << endl;
    }

    void display()
    {
        if (this->front == -1 && this->rear == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            for (int i = this->front; i <= this->rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
main()
{
    Queue q(MAX);
    int choice, element;

    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Rear" << endl;
        cout << "5. Display" << endl;
        cout << "6. isEmpty" << endl;
        cout << "7. isFull" << endl;
        cout << "8. Size" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Element:";
            cin >> element;
            q.enqueEle(element);
            break;
        case 2:
            q.deQueue();
        case 3:
            q.getfRONT();
        case 4:
            q.getRear();
        case 5:
            q.display();
        case 6:
            q.isFull();
        case 7:
            q.isEmpty();
        case 8:
            q.getSize();
        default:
            cout << "Invalid";
            break;
        }

    } while (choice != 0);
}
xax-vfdd-hvk