#include<bits/stdc++.h>
using namespace std;

class Stack {
    int top;           // Tracks the top index of the stack
    int arr[100];      // Array to store stack elements
public:
    Stack() {
        top = -1;      // Initialize stack as empty
    }

    void push(int value) {
        if (top == 99) {
            cout << "Stack Overflow!" << endl; // Stack is full
        } else {
            arr[++top] = value;  // Increment top and push the value
            cout << value << " pushed to the stack." << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl; // Stack is empty
        } else {
            cout << arr[top--] << " popped from the stack." << endl; // Remove top element
        }
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl; // Stack is empty
        } else {
            cout << "Top element: " << arr[top] << endl; // Show top element
        }
    }
};

int main() {
    Stack stack;

    stack.push(10);  // Push 10
    stack.push(20);  // Push 20
    stack.push(30);  // Push 30

    stack.peek();    // Show the top element

    stack.pop();     // Pop top element
    stack.peek();    // Show the top element again

    return 0;
}

