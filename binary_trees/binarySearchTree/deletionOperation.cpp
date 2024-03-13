#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

Node* minNode(Node* root) {
    Node* temp = root;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val) {
    if (root == nullptr) {
        return root;
    }
    if (val < root->data) {
        root->left = deleteFromBST(root->left, val);
    } else if (val > root->data) {
        root->right = deleteFromBST(root->right, val);
    } else {
        // Node to be deleted found

        // Case 1: No child or one child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Two children
        Node* temp = minNode(root->right); // Find inorder successor (smallest node in the right subtree)
        root->data = temp->data; // Copy the inorder successor's content to this node
        root->right = deleteFromBST(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

void levelOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int level = q.size();
        for (int i = 0; i < level; ++i) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
}

int main() {
//          8
//        /   \
//       3     10                                                                               
//      / \     \
//     1   6     14
//        / \
//       4   7 
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);


    int val = 3;
    root = deleteFromBST(root, val); // Assign the result of deletion back to root
    levelOrder(root); // Print the modified BST
    return 0;
}