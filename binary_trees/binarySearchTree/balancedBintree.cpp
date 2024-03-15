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
        
        ~Node() {
            delete left;
            delete right;
    }
};

int height(Node* root){
    // base case
    if(root == nullptr){
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

bool isBalanced(Node* root){
    // base case
    if(root==nullptr){
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);

    
    return abs(lh-rh) <=1;
}
int main(){
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
    // root->left->right->right->right  = new Node(8);
    
    if(isBalanced(root)){
        cout << "Balanced";
    }else   
        cout << "not Balanced";
    
    delete(root);
    return  0;

}