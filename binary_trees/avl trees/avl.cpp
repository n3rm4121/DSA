#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left, *right;
    int height;

    Node(int val) {
        key = val;
        left = right = nullptr;
        height = 1;
    }
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* N) {
    return (N == nullptr) ? 0 : N->height;
}

Node* rightRotate(Node* y) {
    cout << "right rotated from : " << y->key << endl;
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

Node* leftRotate(Node* x) {
    cout << "left rotated from : " << x->key << endl;
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

int getBalance(Node* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    // Update height of this node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // If the node becomes unbalanced, perform rotations
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    cout << "Preorder traversal of the constructed AVL tree is:\n";
    preOrder(root);
    cout << endl;
    root = insert(root, 20);
    cout << "Preorder traversal of the constructed AVL tree is:\n";
    preOrder(root);
    cout << endl;
    root = insert(root, 30);
    cout << "Preorder traversal of the constructed AVL tree is:\n";
    preOrder(root);
    cout << endl;
    root = insert(root, 40);
    cout << "Preorder traversal of the constructed AVL tree is:\n";
    preOrder(root);
    cout << endl;
    root = insert(root, 50);
    cout << "Preorder traversal of the constructed AVL tree is:\n";
    preOrder(root);
    cout << endl;
    root = insert(root, 25);

    cout << "Preorder traversal of the constructed AVL tree is:\n";
    preOrder(root);

    return 0;
}
