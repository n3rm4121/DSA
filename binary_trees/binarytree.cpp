#include <iostream>
#include <queue>
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

void levelOrder(Node* node){
    if(node == nullptr){
        return;
    }

    std::queue<Node*> q;
    q.push(node);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if(current->left){
            q.push(current->left);
        }
        if(current->right){
            q.push(current->right);
        }
    }
}
int main() {

    //                   1
    //                  / \
    //                 2   3
    //                / \   \
    //               4   5   6
   Node* root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left -> right = new Node(5);
   root->right->right = new Node(6);
    cout << "preOrder traversal: " << endl;
   preOrder(root);
   cout << endl;

   cout << "inOrder traversal: " << endl;
   inOrder(root);
   cout << endl ;

   cout << "postOrder: "<< endl;
   postOrder(root);
   cout << endl;

   cout << "levelOrder: "<< endl;
   levelOrder(root);
   cout << endl;
}