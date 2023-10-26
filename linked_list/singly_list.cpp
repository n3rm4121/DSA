#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // pointer that points to next node

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void display(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtEnd(Node *&tail, int data)
{
    Node *temp = new Node(data);

    tail->next = temp;
    tail = temp;
    cout << data << " is inserted at end\n";
}

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
    cout << data << " is inserted at head\n";
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    Node *temp = head;

    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == nullptr)
    {
        insertAtEnd(tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    cout << data << " is inserted at position " << position << endl;
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{

    // deleting from empty list
    if (head == nullptr)
    {
        cout << "list is empty\n";
        return;
    }
    // deleting from invalid position
    if (position < 1)
    {
        cout << "invalid position\n";
        return;
    }
    // deleting from invalid position
    if (position > 1 && head->next == nullptr)
    {
        cout << "invalid position\n";
        return;
    }
    // deleting first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        cout << temp->data << " is deleted\n";
        delete temp;
        return;
    }
    else
    {

        // deleting any middle or last node
        Node *current = head;
        Node *previous = nullptr;
        int count = 1;
        while (count < position)
        {
            previous = current;
            current = current->next;
            count++;
        }

        previous->next = current->next;
        current->next = nullptr;

        // for deleting last element
        if (previous->next == nullptr)
        {
            tail = previous;
        }
        cout << current->data << " is deleted\n";
        delete current;
    }
}
int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    display(head);

    // ******** insert at end ****************
    insertAtEnd(tail, 11);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    display(head);

    insertAtEnd(tail, 12);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    display(head);

    // ******************************************

    // ********** insert at head ****************

    insertAtHead(head, 9);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    display(head);

    insertAtPosition(head, tail, 5, 13);
    // head, tail, position, data
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    display(head);

    deleteAtPosition(head, tail, 1);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    display(head);
}
