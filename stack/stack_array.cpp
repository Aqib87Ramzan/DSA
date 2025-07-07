#include <iostream>
using namespace std;

#define MAX 10
int stacksize = 0;

// Stack define
struct Stack {
    int item[MAX];
    int top;
};

typedef struct Stack st; // alias for struct Stack

// Create an empty stack
void createEmptyStack(st *s) {
    s->top = -1;
}

// Check if stack is empty
bool isEmpty(st *s) {
    return (s->top == -1);
}

// Check if stack is full
bool isFull(st *s) {
    return (s->top == MAX - 1);
}

// Push element in stack
void push(st *s, int newitem) {
    if (isFull(s)) {
        cout << "Stack is full, cannot push " << newitem << endl;
        return;
    } else {
        s->top++;
        s->item[s->top] = newitem;
        stacksize++; // only increment when push is successful
    }
    //can't used size here because even is stack is full it continues to increase size
}

// Pop element from stack
void pop(st *s) {
    if (isEmpty(s)) {
        cout << "Stack is empty, cannot pop" << endl;
        return;
    } else {
        cout << "Item popped: " << s->item[s->top] << endl; // Optional message
        s->top--;
        stacksize--; //  decrement when pop is successful
    }
}

// Peek element from stack
void peek(st *s) {
    if (isEmpty(s)) {
        cout << "Stack is empty, cannot peek" << endl;
        return;
    } else {
        cout << "Top element is: " << s->item[s->top] << endl;
    }
}

// Display stack elements
void display(st *s) {
    if (isEmpty(s)) {
        cout << "Stack is empty, nothing to display" << endl;
        return;
    } else {
        cout << "Stack elements are: ";
        for (int i = s->top; i >= 0; i--) {
            cout << s->item[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    st *s = new st; // create a new stack
    createEmptyStack(s); // initialize the stack
    int choice, value;

    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Peek Element\n";
        cout << "4. Display Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(s, value);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                peek(s);
                break;
            case 4:
                display(s);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    delete s; // Free the allocated memory
    return 0;
}
