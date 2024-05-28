#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
     Node(int data){
        this ->data = data;
        this->left = nullptr;
        this->right = nullptr;
     }
};
class binaryTree{
    Node* root;

    Node* insertRecursive(Node* root, int data){
        if(root == nullptr){
            return new Node(data);
        }
        if(data < root->data){
            root->left = insertRecursive(root->left, data);
        }else if(data > root -> data){
            root->right = insertRecursive(root->right, data);
        }
        return root;
    }

    void inorderTraversalRecursive(Node* root){
        if(root == nullptr){
            return;
        }
        inorderTraversalRecursive(root->left);
        cout << root->data << " ";
        inorderTraversalRecursive(root->right);
    }

    void preorderTraversalRecursive(Node* root){
        if(root == nullptr){
            return;
        }
        cout << root->data << " ";
        preorderTraversalRecursive(root->left);
        preorderTraversalRecursive(root->right);
    }

    void postorderTraversalRecursive(Node* root){
        if(root == nullptr){
            return;
        }
        postorderTraversalRecursive(root->left);
        postorderTraversalRecursive(root->right);
        cout << root->data << " ";
    }
   // Function to find the minimum node in a subtree

    Node* findMin(Node* node){
        Node* current = node;
        while(current->left != nullptr){
            current = current->left;
        }
        return current;
    }

    Node* removeRecursive(Node* root, int data){
        if(root == nullptr){
            return nullptr;
        }
        if(data < root->data){
            root->left = removeRecursive(root->left, data);
        }else if(data > root->data){
            root->right = removeRecursive(root->right, data);
        }
        // Node to be deleted found
        // Case 1: Node with no child or only one child
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }else{
        // case 2: node with 2 children
        Node* successor = findMin(root->right);
        root->data = successor ->data;
        root->right = removeRecursive(root->right, successor->data);
        }

        return root;
        
    }
    public:
        binaryTree(){
            root = nullptr;
        }

        void insert(int data){
            root = insertRecursive(root, data);
        }

        void inOrderTraversal(){
            inorderTraversalRecursive(root);
        }
        void preOrderTraversal(){
            preorderTraversalRecursive(root);
        }
        void postOrderTraversal(){
            postorderTraversalRecursive(root);
        }
        void remove(int data){
            root = removeRecursive(root, data);
        }
};  

int main(){
    binaryTree bt;
    int choice, data;
    while(true){
        cout << "1. Insert\n" 
            << "2. Preorder Traversal\n"
            << "3. Inorder Traversal\n"
            << "4. Postorder Traversal\n"
            << "5. Remove node\n"
            << "6. Exit\n";
        cout << "Enter your choice: " ;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert: " ;
            cin >> data;
            bt.insert(data);
            break;
        
        case 2:
            bt.preOrderTraversal();
            break;
        
        case 3: 
            bt.inOrderTraversal();
            break;
        
        case 4:
            bt.postOrderTraversal();
            break;

        case 5:
            cout << "enter data to remove: ";
            cin >> data;
            bt.remove(data);
            break;
        case 6:
            return 0;
            
        default:
            cout << "Enter valid choice\n";
            break;
        }
    }
}
