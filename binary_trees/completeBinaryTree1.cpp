// checking if binary tree is complete binary tree
// method 1:
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

int count(Node* node){
    if(node == nullptr){
        return 0;
    }
    int left_count = count(node->left);
    int right_count = count(node->right);

    return left_count + right_count + 1;
}
bool check(Node* node, int index, int nodeNumber){
    if(node == nullptr){
        return true;
    }
    if (index >= nodeNumber)
    {
       return false;
    }
    
   
   bool left_check = check(node->left, 2 * index + 1, nodeNumber);
    bool right_check = check(node->right, 2 * index + 2, nodeNumber);

    return left_check && right_check;

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


    int node_count = count(root);
    int index = 0;
    if(check(root, index, node_count))
        cout << "Is complete binary tree\n";
    else    
        cout << "Is not complete binary tree\n";
}
