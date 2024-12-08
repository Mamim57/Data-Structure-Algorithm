#include<bits/stdc++.h>
using namespace std;

class CircularQueue
{
    int front, rear, size;
    int* arr;

public:
    CircularQueue(int capacity)
    {
        size = capacity;
        front = rear = -1;
        arr = new int[size];
    }

    void enqueue(int value)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full!" << endl;
        }
        else
        {
            if (front == -1) front = 0;
            rear = (rear + 1) % size;
            arr[rear] = value;
            cout << value << " enqueued." << endl;
        }
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << arr[front] << " dequeued." << endl;
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            int i = front;
            cout << "Queue elements: ";
            while (i != rear)
            {
                cout << arr[i] << " ";
                i = (i + 1) % size;
            }
            cout << arr[rear] << endl;
        }
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}

