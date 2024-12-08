#include<bits/stdc++.h>
using namespace std;

class Queue
{
    int front, rear, size;
    int arr[100];  // Array to store queue elements

public:
    Queue(int queueSize)
    {
        size = queueSize;
        front = -1;   // Initialize front and rear pointers
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow!" << endl;  // Queue is full
        }
        else
        {
            if (front == -1) front = 0;  // If queue is empty, set front to 0
            arr[++rear] = value;  // Add element to the rear
            cout << value << " enqueued to the queue." << endl;
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow!" << endl;  // Queue is empty
        }
        else
        {
            cout << arr[front++] << " dequeued from the queue." << endl;  // Remove element from the front
        }
    }

    void peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty!" << endl;  // Queue is empty
        }
        else
        {
            cout << "Front element: " << arr[front] << endl;  // Display the front element
        }
    }
};

int main()
{
    int size;
    cout << "Enter the queue size: ";
    cin >> size;

    Queue q(size);

    q.enqueue(10);  // Enqueue 10
    q.enqueue(20);  // Enqueue 20
    q.enqueue(30);  // Enqueue 30

    q.peek();  // Show front element

    q.dequeue();  // Dequeue front element
    q.peek();  // Show front element again

    return 0;
}

