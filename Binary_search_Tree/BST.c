#include <iostream>

struct Node {
    int data;
    struct Node *left, *right;
};

// Global root pointer
struct Node *root = NULL;

// Function to create a new node
struct Node *createnewnode(int gd) {
    struct Node *newNode = new Node();
    newNode->data = gd;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
void buildTree(int gd) {
    struct Node *newNode = createnewnode(gd);
    struct Node *curr, *prev;

    if (root == NULL) {
        root = newNode;
        return;
    }

    curr = root;
    while (curr != NULL) {
        prev = curr;
        if (gd < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (gd < prev->data)
        prev->left = newNode;
    else
        prev->right = newNode;
}

// Function to perform inorder traversal (LNR)
void inorderTraversal(struct Node *node) {
    if (node == NULL)
        return;

    inorderTraversal(node->left);
    std::cout << node->data << " ";
    inorderTraversal(node->right);
}

int main() {
    int num;
    
    std::cout << "Enter numbers to insert into BST (Enter -1 to stop):" << std::endl;
    
    while (true) {
        std::cin >> num;
        if (num == -1)  // Stop input when -1 is entered
            break;
        buildTree(num);
    }

    std::cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
