#include <iostream>
using namespace std;

// ====================== Node Structure ============================
// Node for Doubly Linked List
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize node with value
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// ====================== Doubly Linked List ========================
class DoublyLinkedList {
private:
    Node* head;  // Pointer to the first node

public:
    // Constructor initializes empty list
    DoublyLinkedList() : head(nullptr) {}

    // ========== 1. Insert a new node at the end ==========
    void InsertAtEnd(int val) {
        Node* newNode = new Node(val);  // Create new node

        // If list is empty, newNode becomes head
        if (!head) {
            head = newNode;
            return;
        }

        // Otherwise, go to the last node
        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        // Link newNode at the end
        temp->next = newNode;
        newNode->prev = temp;
    }

    // ========== 2. Display the entire list ==========
    void Display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // ========== 3. Rearrange even and odd ==========
    void RearrangeEvenOdd() {
        // No rearrangement needed for 0 or 1 nodes
        if (!head || !head->next) return;

        Node* evenHead = nullptr, *evenTail = nullptr;
        Node* oddHead = nullptr, *oddTail = nullptr;
        Node* current = head;

        // Traverse list and separate even and odd nodes
        while (current) {
            Node* nextNode = current->next;
            current->next = current->prev = nullptr;

            if (current->data % 2 == 0) {
                // Add to even list
                if (!evenHead)
                    evenHead = evenTail = current;
                else {
                    evenTail->next = current;
                    current->prev = evenTail;
                    evenTail = current;
                }
            } else {
                // Add to odd list
                if (!oddHead)
                    oddHead = oddTail = current;
                else {
                    oddTail->next = current;
                    current->prev = oddTail;
                    oddTail = current;
                }
            }

            current = nextNode;
        }

        // Merge even and odd lists
        if (evenTail) {
            evenTail->next = oddHead;
            if (oddHead) oddHead->prev = evenTail;
            head = evenHead;  // New head is evenHead
        } else {
            head = oddHead;   // If no even nodes
        }
    }

    // ========== 4. Reverse the list using circular logic ==========
    void Reverse() {
        if (!head || !head->next) return;

        // Go to the last node (tail)
        Node* tail = head;
        while (tail->next)
            tail = tail->next;

        // Make the list temporarily circular
        tail->next = head;
        head->prev = tail;

        // Reverse the pointers in circular list
        Node* current = head;
        Node* temp = nullptr;

        do {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        } while (current != head);

        // Update head to new first node (previous tail)
        head = tail;

        // Break circularity
        head->prev->next = nullptr;
        head->prev = nullptr;
    }

    // ========== 5. Swap two nodes (not values) ==========
    void swapNodes(int val1, int val2) {
        if (val1 == val2) return;

        Node* node1 = nullptr;
        Node* node2 = nullptr;
        Node* temp = head;

        // Find both nodes by their values
        while (temp) {
            if (temp->data == val1) node1 = temp;
            else if (temp->data == val2) node2 = temp;
            temp = temp->next;
        }

        // Check if both nodes are found
        if (!node1 || !node2) {
            cout << "One or both values not found.\n";
            return;
        }

        // Fix previous node links
        if (node1->prev) node1->prev->next = node2;
        if (node2->prev) node2->prev->next = node1;

        swap(node1->prev, node2->prev);  // Swap prev pointers

        // Fix next node links
        if (node1->next) node1->next->prev = node2;
        if (node2->next) node2->next->prev = node1;

        swap(node1->next, node2->next);  // Swap next pointers

        // Update head if needed
        if (head == node1) head = node2;
        else if (head == node2) head = node1;
    }
};

// ============================== MAIN ==============================
int main() {
    DoublyLinkedList list;
    int choice;

    // Menu-based interaction
    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Insert Element\n";
        cout << "2. Display List\n";
        cout << "3. Rearrange Even and Odd\n";
        cout << "4. Reverse List (Circular Logic)\n";
        cout << "5. Swap Two Nodes (by Value)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int val;
                cout << "Enter value to insert: ";
                cin >> val;
                list.InsertAtEnd(val);
                break;
            }
            case 2:
                cout << "Current List:\n";
                list.Display();
                break;

            case 3:
                list.RearrangeEvenOdd();
                cout << "List after rearranging even and odd:\n";
                list.Display();
                break;

            case 4:
                list.Reverse();
                cout << "List after reversing:\n";
                list.Display();
                break;

            case 5: {
                int val1, val2;
                cout << "Enter first value to swap node: ";
                cin >> val1;
                cout << "Enter second value to swap node: ";
                cin >> val2;
                list.swapNodes(val1, val2);
                cout << "List after swapping:\n";
                list.Display();
                break;
            }

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
