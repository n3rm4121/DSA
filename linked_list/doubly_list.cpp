#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// traversing linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int data)
{
    // if list is empty

    if (head == nullptr)
    {
        Node *temp = new Node(data);
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, int data)
{
    if (tail == nullptr)
    {
        Node *temp = new Node(data);
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    // inserting in middle of linked list
    // temp will point to node before position
    Node *temp = head;

    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if (temp->next == nullptr)
    {
        insertAtTail(tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
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

    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = nullptr;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
    }
    else
    {
        Node *current = head;
        Node *previous = nullptr;
        int count = 1;
        while (count < position)
        {
            previous = current;
            current = current->next;
            count++;
        }
        current->prev = nullptr;
        previous->next = current->next;
        current->next = nullptr;

        // for deleting last element
        if (previous->next == nullptr)
        {
            tail = previous;
        }

        delete current;
    }
}
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    print(head);
    cout << "Length: " << getLength(head) << endl;

    insertAtHead(head, 9);
    insertAtHead(head, 8);

    print(head);

    insertAtTail(tail, 11);
    print(head);

    insertAtPosition(head, tail, 5, 0);
    cout << "head : " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    print(head);

    deleteAtPosition(head, tail, 5);
    print(head);

    cout << "head : " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
}