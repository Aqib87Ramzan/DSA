#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Global front and rear pointers
Node* front = NULL;
Node* rear = NULL;

// Check if queue is empty
bool isEmpty() {
    return front == NULL;
}

// Enqueue (Insert)
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
        rear->next = front;  // Make it circular
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

// Dequeue (Delete)
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
        return;
    }

    Node* temp = front;

    // Only one node
    if (front == rear) {
        cout << "Deleted element: " << temp->data << endl;
        front = rear = NULL;
    } else {
        cout << "Deleted element: " << temp->data << endl;
        front = front->next;
        rear->next = front; // maintain circular link
    }

    delete temp;
}

// Peek (Front element)
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
        return;
    }

    cout << "Queue elements are: ";
    Node* temp = front;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
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
