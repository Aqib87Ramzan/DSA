#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Global pointers for front and rear
Node* front = nullptr;
Node* rear = nullptr;

// Check if queue is empty
bool isEmpty() {
    return (front == nullptr);
}

// Insert (Enqueue)
void insert(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Inserted: " << x << endl;
}

// Delete (Dequeue)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow (Empty)" << endl;
        return;
    }

    Node* temp = front;
    cout << "Deleted: " << temp->data << endl;
    front = front->next;
    delete temp;

    if (front == nullptr) {
        rear = nullptr;  // Queue became empty
    }
}

// Peek front element
void peek() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Front element is: " << front->data << endl;
    }
}

// Display all elements
void display() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

// Main function with menu
int main() {
    int choice, value;

    while (true) {
        cout << "\n==== Queue (Linked List) Menu ====\n";
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
