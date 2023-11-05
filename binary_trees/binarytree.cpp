#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node* buildTree(node* root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    node* root = new node(data);
    if(data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << ": ";
    root -> left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << ": ";
    root -> right = buildTree(root -> right);
    return root;

}

int main()
{
    node* root = NULL;
    root = buildTree(root);
}