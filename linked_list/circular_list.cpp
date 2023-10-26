#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void insert(Node *&tail, int element, int data)
{

    // assuming element is present in list
    // for empty list
    if (tail == nullptr)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // if the list is not empty
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = tail->next;
        }
        // element found at curr
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
        
    }
}

// deletion on the basis of value not position
void deleteNode(Node* &tail, int value){
    if(tail == nullptr){
        // empty list  
        cout << "List is empty!\n";
        return ;
    }
    
    else{
        // non-empty list and asssuming value is present in list
        Node* prev = tail;
        Node* curr = prev -> next;
        

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }

        // current node found
        prev -> next = curr -> next;
        curr -> next = nullptr;

        // 1 node linked list
        if(curr == tail){
            tail = nullptr;
        }

        // >=2 node linked list
        else if(tail == curr){
            tail = prev;
        }
        delete curr;
    }

}

void print(Node* &tail){
    Node* temp = tail;

    if(tail == nullptr){
        cout << "List is empty\n";
        return ;
    }
    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    }while(tail != temp);
}
int main()
{
    Node *tail = nullptr;
    insert(tail, 3, 1);
    // insert(tail,1,2);
    // print(tail);
 
    deleteNode(tail, 1);
    print(tail);
}