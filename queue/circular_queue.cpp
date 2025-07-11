#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Check if queue is empty
bool isEmpty() {
    return (front == -1);
}

// Check if queue is full
bool isFull() {
    return ((rear + 1) % MAX == front);
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
        rear = (rear + 1) % MAX;
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
        // Only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
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
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        cout << endl;
    }
}

// Main menu
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
