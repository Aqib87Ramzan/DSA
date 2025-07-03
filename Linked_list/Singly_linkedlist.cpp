#include <iostream>
using namespace std;

//======= Node structure========
class Node {
public:
    int data;
    Node* next;

    Node(int val = 0) {
        data = val;
        next = nullptr;
    }
};

// ======= Singly Linked List class ========
class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {} //Constructor to initialize the head to nullptr

    //for use in the main function to get and set the head of the list
    Node* GetHead() {
    return head;
    }
    void SetHead(Node* h) {
    head = h;
    }


// ==========================================================================
// (1)
// =============Insertion cases=================

//Insert at the beginning=======
void InsertAtBeginning(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Insert at the end=============
void InsertAtEnd(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {  // if the list is empty then head is newNode
        head = newNode;
    } else {              // if the list is not empty
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Insert at specific position=========
void InsertAtPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position! Position should be greater than 0." << endl;
        return;
    }

    Node* newNode = new Node(value);
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position is out of bounds." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next; // Link the new node to the next node
    temp->next = newNode;       // Link the previous node to the new node
}

// ====================================================================================================

//  (2)
// =============Deletion cases=================

// Delete from the beginning=========
void DeleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    } else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Delete from the end=========
void DeleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// Delete from specific position=========
void DeleteFromPosition(int position) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (position < 1) {
        cout << "Invalid position! Position should be greater than 0." << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    for (int i = 1; i < position && current != nullptr; i++) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    previous->next = current->next;
    delete current;
}

// ===============================================================================

//   (3)
// =============Reversing the list=================
void ReverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// ===============================================================================

//  (4)
// =============Merging the two sorted linked lists=================
Node* MergeSortedLists(Node* list1, Node* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    Node* mergedList = nullptr;

    if (list1->data < list2->data) {
        mergedList = list1;
        mergedList->next = MergeSortedLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = MergeSortedLists(list1, list2->next);
    }

    return mergedList;
}

// ===============================================================================

// (5)
// =============Removing Duplicates from the Sorted list=================
void RemoveDuplicates() {
    if (head == nullptr) {
        cout << "List is empty, nothing to remove." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

//=================================================================================

// (6)
// =================sort the linked list using merge sort=================
Node* MergeSort(Node* h) {
    if (h == nullptr || h->next == nullptr)
        return h;

    Node* slow = h;
    Node* fast = h->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr;

    Node* left = MergeSort(h);
    Node* right = MergeSort(mid);

    return MergeSortedLists(left, right);
}

void SortList() {
    head = MergeSort(head);
}

//================================================================================
// =============display the list=================
void DisplayList() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
};

int main() {
    SinglyLinkedList list;
    int choice, value, position;

    do {
        cout << "\n====== Singly Linked List Menu ======\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n";
        cout << "7. Display List\n8. Reverse List\n9. Remove Duplicates (sorted only)\n";
        cout << "10. Sort List (Merge Sort)\n11. Merge two sorted linked lists\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.InsertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.InsertAtEnd(value);
            break;

        case 3:
            cout << "Enter value and position to insert: ";
            cin >> value >> position;
            list.InsertAtPosition(value, position);
            break;

        case 4:
            list.DeleteFromBeginning();
            break;

        case 5:
            list.DeleteFromEnd();
            break;

        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            list.DeleteFromPosition(position);
            break;

        case 7:
            list.DisplayList();
            break;

        case 8:
            list.ReverseList();
            cout << "List reversed.\n";
            break;

        case 9:
            list.RemoveDuplicates();
            cout << "Duplicates removed (from sorted list).\n";
            break;

        case 10:
            list.SortList();
            cout << "List sorted using merge sort.\n";
            break;
        case 11: {
            cout << "Creating first sorted list:\n";
            SinglyLinkedList list1;
            int n1, val1;
            cout << "Enter number of elements for List 1: ";
            cin >> n1;
            for (int i = 0; i < n1; i++) {
                cout << "Enter value " << i + 1 << ": ";
                cin >> val1;
                list1.InsertAtEnd(val1);
            }
        
            cout << "Creating second sorted list:\n";
            SinglyLinkedList list2;
            int n2, val2;
            cout << "Enter number of elements for List 2: ";
            cin >> n2;
            for (int i = 0; i < n2; i++) {
                cout << "Enter value " << i + 1 << ": ";
                cin >> val2;
                list2.InsertAtEnd(val2);
            }
        
            // Get the heads
            Node* head1 = list1.GetHead();
            Node* head2 = list2.GetHead();
        
            // Merge the lists
            Node* mergedHead = list.MergeSortedLists(head1, head2);
        
            // Display merged list
            cout << "Merged List: ";
            Node* temp = mergedHead;
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
            break;
        }


        case 0:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
