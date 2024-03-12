// searching in BST

#include <iostream>
#include <queue>
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

Node* search(int num, Node* root){

    if(root->data = num || root == nullptr){
        return root;
    }

    if(num < root->data){
        return search(num, root->left);
    }
        
    return search(num, root->right);
    
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
   root->left -> right = new Node(6);
   root->right->right = new Node(14);
   root->left->right->left = new Node(4);
   root->left->right->right = new Node(7);
   root->right->left = new Node(6);
   root->right->right = new Node(7);
    
    int key = 4;
   if(search(key, root) == nullptr){
    cout << "key: " << key << " not found\n";
   }else{
    cout << "key: " << key << " found\n";
   }

}

