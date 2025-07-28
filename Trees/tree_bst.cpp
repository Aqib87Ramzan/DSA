#include <iostream>
using namespace std;

//=========struct bst==========
struct BST_node {
    int data;
    BST_node* left_child; //left side of root node
    BST_node* right_child; //right side of root node

    BST_node(int val) : data(val), left_child(nullptr), right_child(nullptr) {}
};

class BST {
private:
    BST_node* root; // root node

//============insertion in BST=================
    BST_node* insert(BST_node* node, int value) {
        if (!node){    //if root node is null
            return new BST_node(value);
        }
        //if new value is less than root node, then insert in left subtree    
        if (value < node->data){  
            node->left_child = insert(node->left_child, value);
        }
        //if new value is greater then root node then insert in right subtree
        else if (value > node->data){
            node->right_child = insert(node->right_child, value);
        }
        // duplicates not inserted
        return node;
    }

//============searching in BST=================
    bool search(BST_node* node, int value) {
        if (!node) { // if root node is null 
            return false;
        }
        //if search value is found in root
        if (node->data == value){ 
            return true;
        }
        //if search value is less then root, then searching in left subtree
        if (value < node->data){
             return search(node->left_child, value);
        }
        //if search value is greater than root, then searching in right subtree
        else{
             return search(node->right_child, value);
        }     
    }

//======================Traversals=====================================
//============inorder traversal (Left -> Root -> Right) ===============
    void inorderTraversal(BST_node* node) {
        if (!node) return;
        inorderTraversal(node->left_child); //left
        cout << node->data << " ";          //root
        inorderTraversal(node->right_child);//right
    }

//============preorder traversal (Root -> Left -> Right) ==============
    void preorderTraversal(BST_node* node) {
        if (!node) return;
        cout << node->data << " "; //root
        preorderTraversal(node->left_child);  //left
        preorderTraversal(node->right_child); //right
    }
    
//=============postorder traversal (Left -> Right -> Root)===========    
    void postorderTraversal(BST_node* node) {
        if (!node) return;
        postorderTraversal(node->left_child); //left
        postorderTraversal(node->right_child);//right
        cout << node->data << " ";            //root
    }

//========================================================================

//=============smallest value=================
    BST_node* findSmallest(BST_node* node) {
        if (!node) { //if root is null means tree is empty
            return nullptr;
        }
        while (node->left_child) { //finding min value in left subtree
            node = node->left_child;
        }
        return node;
    }

//=============largest value=================
    BST_node* findLargest(BST_node* node) {
        if (!node){ //IF TREE IS EMPTY
            return nullptr;
        }
        while (node->right_child){ //FINDING VALUE IN RIGHT SUBTREE 
             node = node->right_child;
        }
        return node;
    }

//============count all nodes=================
    int countAllNodes(BST_node* node) { 
        if (!node){ // if tree is empty == base case
             return 0;
        } //recursive case
        return 1 + countAllNodes(node->left_child) + countAllNodes(node->right_child);
    }

//=============count leaf nodes================
    int countLeafNodes(BST_node* node) {
        if (!node) { //if tree is empty
             return 0;
        }     
        if (!node->left_child && !node->right_child) { //if left and right subtree is null
            return 1;
        }
        //recurrsion case: calling the function to sum left and right nodes    
        return countLeafNodes(node->left_child) + countLeafNodes(node->right_child);
    }



//=============count internal nodes=============
    int countInternalNodes(BST_node* node) {
        //base case if node or left and right subtree == 0
        if (!node || (!node->left_child && !node->right_child)){ 
             return 0;
        }
        //recurrsion case     
        return 1 + countInternalNodes(node->left_child) + countInternalNodes(node->right_child);
    }

//=============height of BST===================
    int height(BST_node* node) {
        if (!node){ //if tree is empty
             return -1;
        }
        //left variable for left tree's height     
        int leftHeight = height(node->left_child);

        //right variable for right tree's height 
        int rightHeight = height(node->right_child);

        //recurrsion case:
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
    }

//============= Depth of a node by given value=========
    int depth(BST_node* node, int value, int currentDepth) {
        if (!node){ // if tree has no value
             return -1;  
        }
        if (node->data == value){  //for depth of root node
             return currentDepth;
        }
        // value to find depth is less than root node's value then find depth in left subtree
        if (value < node->data){  
            return depth(node->left_child, value, currentDepth + 1);
        }
        // value to find depth is greater than root node's value then find depth in right subtree
        else{
            return depth(node->right_child, value, currentDepth + 1);
        }
    }

public:
    BST() : root(nullptr) {}



//============empty condition==============
    bool isEmpty() {
        return root == nullptr;
    }

    void insertWithoutDuplication(int value) {
        if (search(root, value)) {
            cout << "Value " << value << " already exists, duplication not allowed." << endl;
        }
        else {
            root = insert(root, value);
            cout << "Inserted " << value << " successfully." << endl;
        }
    }

    void searchValue(int value) {
        if (search(root, value))
            cout << value << " found in the tree." << endl;
        else
            cout << value << " not found in the tree." << endl;
    }

    void inorderTraversal() {
        cout << "Inorder traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    void preorderTraversal() {
        cout << "Preorder traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    void postorderTraversal() {
        cout << "Postorder traversal: ";
        postorderTraversal(root);
        cout << endl;
    }

    void smallestValue() {
        BST_node* smallest = findSmallest(root);
        if (smallest) cout << "Smallest value: " << smallest->data << endl;
        else cout << "Tree is empty." << endl;
    }

    void largestValue() {
        BST_node* largest = findLargest(root);
        if (largest) cout << "Largest value: " << largest->data << endl;
        else cout << "Tree is empty." << endl;
    }

    void printLeafNodes() {
        cout << "Leaf nodes: ";
        printLeafNodes(root);
        cout << endl;
    }

    void printLeafNodes(BST_node* node) {
        if (!node) return;
        if (!node->left_child && !node->right_child) {
            cout << node->data << " ";
        }
        printLeafNodes(node->left_child);
        printLeafNodes(node->right_child);
    }

    void countAllNodes() {
        cout << "Total nodes: " << countAllNodes(root) << endl;
    }

    void countLeafNodes() {
        cout << "Leaf nodes count: " << countLeafNodes(root) << endl;
    }

    void countInternalNodes() {
        cout << "Internal nodes count: " << countInternalNodes(root) << endl;
    }

    void heightOfBST() {
        cout << "Height of BST: " << height(root) << endl;
    }

    void depthOfValue(int value) {
        int d = depth(root, value, 0);
        if (d == -1)
            cout << "Value " << value << " not found in the tree." << endl;
        else
            cout << "Depth of value " << value << " is: " << d << endl;
    }
};

//============main function==============
int main() {
    BST tree;
    int choice, value;

    do {
        cout << "\n====BST Menu(all cases) ====\n";
        cout << "1. Check if empty\n";
        cout << "2. Search value\n";
        cout << "3. Insert without duplication\n";
        cout << "4. Preorder traversal\n";
        cout << "5. Postorder traversal\n";
        cout << "6. Inorder traversal\n";
        cout << "7. Find smallest value\n";
        cout << "8. Find largest value\n";
        cout << "9. Print leaf nodes\n";
        cout << "10. Count all nodes\n";
        cout << "11. Count leaf nodes\n";
        cout << "12. Count internal nodes\n";
        cout << "13. Find height\n";
        cout << "14. Find depth of a value\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (tree.isEmpty()) cout << "Tree is empty." << endl;
            else cout << "Tree is not empty." << endl;
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            tree.searchValue(value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insertWithoutDuplication(value);
            break;
        case 4:
            tree.preorderTraversal();
            break;
        case 5:
            tree.postorderTraversal();
            break;
        case 6:
            tree.inorderTraversal();
            break;
        case 7:
            tree.smallestValue();
            break;
        case 8:
            tree.largestValue();
            break;
        case 9:
            tree.printLeafNodes();
            break;
        case 10:
            tree.countAllNodes();
            break;
        case 11:
            tree.countLeafNodes();
            break;
        case 12:
            tree.countInternalNodes();
            break;
        case 13:
            tree.heightOfBST();
            break;
        case 14:
            cout << "Enter value to find depth: ";
            cin >> value;
            tree.depthOfValue(value);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }

    } while (choice != 0);

    return 0;
}

