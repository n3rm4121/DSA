#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool isfullbinarytree(Node* node){
    if(node == nullptr){
        return true;
    }

    if(node->left == nullptr && node->right == nullptr){
        return true;
    }
    if((node->left) && (node->right)){
        return (isfullbinarytree(node->left) && isfullbinarytree(node->right));
    }
    return false;
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    if(isfullbinarytree(root)){
        cout << "Tree is full binary tree\n";
    }else{
        cout << "Tree is not full binary tree\n";
    }
}