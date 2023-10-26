// stack implementation using linked list

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

class stack
{
private:
    Node *head;

public:
    stack()
    {
        head = nullptr;
    }
    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        cout << data << " is pushed into the stack\n";
    }

    bool isEmpty()
    {
        return head == nullptr ? true : false;
    }

    void top()
    {
        if (isEmpty())
        {
            cout << "stack is empty";
        }
        else
        {
            cout << "Top element is: " << head->data << endl;
        }
    }

    void pop()
    {
        Node *temp;
        if (isEmpty())
        {
            cout << "Underflow! The stack is empty\n";
            return;
        }
        else
        {
            
            temp = head;
            cout << temp -> data << " is popped\n";
            head = head->next;
            delete (temp);
        }
    }

    void display(){
        if(isEmpty()){
            cout << "Underflow! Stack is empty\n";
            return ;
        }else{
           Node* temp = head;
           while(temp!=nullptr){
            cout << temp -> data;
            temp = temp-> next;
           }
           cout << endl;
        }
    }
};

int main()
{
    stack s;
    s.push(3);
    s.push(4);
    s.top();
    s.display();
    s.pop();
    s.display();
    

}
