#include <iostream>
#include <string>
#include <stack>  // For reverse_string
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
};

// Stack using linked list
class Stack {
private:
    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        size++;
        cout << "✅ " << value << " pushed onto the stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "❌ Stack is empty, cannot pop.\n";
            return;
        }
        cout << "✅ Popped element: " << top->data << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "❌ Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    int getSize() {
        return size;
    }
};

// Function to reverse a string using STL stack
string reverse_string(string str) {
    stack<char> s;
    for (char ch : str) {
        s.push(ch);
    }
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    return reversed;
}

int main() {
    Stack stack;
    int choice, value;
    string str;

    cout << "\n🌟 Welcome to the Stack Program (Linked List Based) 🌟\n";

    do {
        cout << "\n========== MENU ========== \n";
        cout << "1.  Push Element\n";
        cout << "2.  Pop Element\n";
        cout << "3.  Peek Top Element\n";
        cout << "4.  Display Stack Size\n";
        cout << "5.  Reverse String using Stack\n";
        cout << "6.  Exit\n";
        cout << "=============================\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        cout << "-----------------------------\n";
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                value = stack.peek();
                if (value != -1) {
                    cout << "🔝 Top element is: " << value << endl;
                }
                break;
            case 4:
                cout << "Current stack size: " << stack.getSize() << endl;
                break;
            case 5:
                cin.ignore();  // Fix input issue
                cout << "Enter a string to reverse: ";
                getline(cin, str);
                cout << "🔁 Reversed string: " << reverse_string(str) << endl;
                break;

            case 6:
                cout << " Exiting... Thank you!\n";
                break;
            default:
                cout << " Invalid choice! Please enter 1-6.\n";
        }
        cout << "-----------------------------\n";

    } while (choice != 6);

    return 0;
}
