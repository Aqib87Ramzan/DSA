#include <iostream>
using namespace std;

// Constants(size of dequeue)
#define MAX 5

// Global variables
int queue[MAX];
int front = -1;
int rear = -1;

// Check if queue is empty
bool isEmpty() {
    return (front == -1 && rear == -1);
}

// Check if queue is full
bool isFull() {
    return (rear == MAX - 1);
}

// Enqueue
void insert(int x) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear] = x;
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
        return;
    }

    cout << "Deleted element: " << queue[front] << endl;

    if (front == rear) {
        // Only one element was present
        front = rear = -1;
    } else {
        front++;
    }
}

// Peek front element
void peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Front element is: " << queue[front] << endl;
    }
}

// Display queue
void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

// Main function with menu
int main() {
    int choice, value;

    while (true) {
        cout << "\n==== Queue Menu ====\n";
        cout << "1. Insert (Enqueue)\n";
        cout << "2. Delete (Dequeue)\n";
        cout << "3. Peek Front\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
