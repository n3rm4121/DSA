// checking if binary tree is complete binary tree
// method 2: level Traversing
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


bool isCompleteBT(Node* root){
    if(root == nullptr){
        return true;
    }
    queue<Node*> q;
    q.push(root);
    bool reachedNull = false;
    
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        
        if(current == nullptr){
            reachedNull = true;
            continue;
        }
        
        // if current is not full node and we already reached nullptr then it is not complete binary tree
        if(reachedNull){
            return false;
        }
        q.push(current->left);
        q.push(current->right);
    }

    return true;
}

int main(){
//          1
//        /   \
//       2     3                                                                               
//      / \   / \
//     4   5 6   7
//    / \
//   8   9
   Node* root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->left->left = new Node(8);
   root->left->left->right = new Node(9);
   root->left -> right = new Node(5);
   root->right->left = new Node(6);
   root->right->right = new Node(7);

   if (isCompleteBT(root))
        cout << "The tree is a complete binary tree." << endl;
    else
        cout << "The tree is not a complete binary tree." << endl;

    return 0;
}