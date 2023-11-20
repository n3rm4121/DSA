#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data){
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }
};

// preorder traversal
void preOrder(Node* node)
{
    
    if(node==nullptr){
        return;
    }
    cout << node->data << "->";
    preOrder(node->left);
    preOrder(node->right);
}

// inOrder traversal
void inOrder(Node* node)
{
    if(node==nullptr){
        return;
    }
    inOrder(node->left);
    cout << node->data << "->";
    inOrder(node->right);
    
}

void postOrder(Node* node){
    if(node== nullptr){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    cout << node-> data << "->";
}
int main() {
   Node* root = new Node(1);
   root->left = new Node(12);
   root->right = new Node(9);
   root->left->left = new Node(5);
   root->left -> right = new Node(6);
    cout << "preOrder traversal: " << endl;
   preOrder(root);
   cout << endl;
   cout << "inOrder traversal: " << endl;
   inOrder(root);
   cout << endl ;
   cout << "postOrder: "<< endl;
   postOrder(root);
   cout << endl;
}