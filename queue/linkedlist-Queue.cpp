// implementation of queue using linked list

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
};

class Queue{
private:
    Node* front;
    Node* rear;

public:
    Queue(){
        front = rear = nullptr;
    }

    void push(int data){
        cout << "Inserted: " << data << endl;
        Node* n1 = new Node(data);

        if(rear == nullptr){
            front = rear = n1;
            return;
        }
       
        rear -> next= n1;
        n1 = rear;
    }
    void pop(){
        if(front == nullptr){
            cout <<"Queue is empty\n";
            return;
        }
        int data = front -> data;
        cout << "Deleted: " << data << endl;
        Node* temp = front;
        front = front->next;

        delete temp;
    }
    void display(){
        Node* current = front;
        if(current == nullptr){
            cout << "Queue is empty\n";
            return;
        }
        while(current != nullptr){
            cout << current -> data << " ";
            current = current -> next;
        }
        cout << endl;
    }
};

int main(){
    Queue  q;
    q.push(1);
    q.push(2);
    q.display();
    q.pop();
    q.display();
}