// counting with edge not node

#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

int height(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    int leftheight = height(node->left);
    int rightheight = height(node->right);

    return max(leftheight, rightheight)+1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(5);

    cout << height(root);
}
