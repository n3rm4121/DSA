# Binary Tree Data Structure

## Introduction
A binary tree is a hierarchical data structure in which each node has at most two children, referred to as the left child and the right child. It is a widely used data structure in computer science and is particularly useful for representing hierarchical relationships between elements.

## Tree Types
There are different types of binary trees based on the structure and properties:

1. **Full Binary Tree**: A binary tree in which every node has either zero or two children.
2. **Complete Binary Tree**: A binary tree in which all levels are completely filled except possibly for the last level, which is filled from left to right.
3. **Perfect Binary Tree**: A binary tree in which all internal nodes have two children, and all leaves are at the same level.
4. **Balanced Binary Tree**: A binary tree in which the height of the left and right subtrees of any node differ by at most one.
5. **Degenerate (or Pathological) Tree**: A binary tree in which each parent node has only one child.

## Terminologies
- **Node**: Each element in a binary tree is called a node. It contains data and pointers to its left and right children.
- **Root**: The topmost node in a binary tree is called the root node. It is the starting point for tree traversal.
- **Parent Node**: A node in a binary tree that has one or more child nodes.
- **Child Node**: The nodes directly connected to a parent node.
- **Leaf Node**: A node in a binary tree that has no children. Also known as a terminal node.
- **Internal Node**: A node in a binary tree that has at least one child.
- **Height**: The length of the longest path from the root node to a leaf node. The height of an empty tree is considered -1.
- **Depth**: The depth of a node is the length of the path from the root node to that node.
- **Level**: The level of a node represents its depth in the tree. The root node is at level 0, its children are at level 1, and so on.

## Usage
### Installation
No specific installation steps are required as binary trees can be implemented using any programming language. Simply include the necessary code or library in your project.

### Creating a Binary Tree
A binary tree can be created by instantiating a node class and establishing connections between nodes.

### Operations
- **Insertion**: Add a new node to the binary tree.
- **Deletion**: Remove a node from the binary tree.
- **Traversal**: Visit all nodes in the binary tree in a specific order, such as inorder, preorder, or postorder traversal.
- **Search**: Find a specific element in the binary tree.
- **Balancing**: Balance the binary tree to ensure optimal performance in operations.

### Example
```cpp
#include <iostream>
using namespace std;

// Node class definition goes here...

// Function to perform inorder traversal
void inorderTraversal(Node* node) {
    if (node == nullptr)
        return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

int main() {
    // Create a binary tree
    // Node creation and tree traversal example...
    return 0;
}
```
## References
<ul>
  <li>[Binary tree - Wikipedia](https://en.wikipedia.org/wiki/Binary_tree)</li>
  <li>[Data Structures and Algorithms in C++ by Adam Drozdek](https://www.cengage.com/c/data-structures-and-algorithms-in-c-2e-drozdek)</li>
  <li>[Introduction to Algorithms by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein](https://mitpress.mit.edu/books/introduction-algorithms-third-edition)/li>
</ul>

