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
            this -> right = nullptr;
            this-> left = nullptr;
        }
};

Node* insertBst(Node* root, int data){
    if(root == nullptr){
        root = new Node(data);
        return root;
    }
    else if(data > root->data){
        root->right = insertBst(root->right, data);
    }
    else if(data < root->data){
        root->left = insertBst(root->left, data);
    }
    return root;
}

void inputData(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertBst(root, data);
        cin >> data;
    }
}

void levelOrder(Node* root){
    if(root == nullptr){
        return;
    }
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int level = q.size();
        for(int i = 0; i < level; ++i){
            
            Node* current = q.front();
            q.pop();
            cout << current->data << " " ;
            
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }   
        }
        cout << endl;
       
    }
  
}
int main()
{
    // 10 8 21 7 27 5 4 3
    Node* root = nullptr;
    cout << "Enter numbers to create binary tree: ";
    cout << "Note: Enter '-1' when you are done" << endl;
    inputData(root);
    cout << "printing using level order: " << endl;
    levelOrder(root);
    return 0;
}