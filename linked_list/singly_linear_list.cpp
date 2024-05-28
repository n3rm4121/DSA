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
class list
{

    Node *head;
    Node *tail;

public:
    list()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void insertAtHead(int data)
    {
        Node *n = new Node(data);

        if (head == nullptr && tail == nullptr)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
    }

    void insertAtTail(int data)
    {
        Node *n = new Node(data);
        tail->next = n;
        tail = n;
    }

    void insertAtPosition(int data, int position)
    {
        if (position == 1)
        {
            insertAtHead(data);
            return;
        }
        else
        {
            int count = 1;
            Node *temp = head;
            while (count != position - 1 && temp != nullptr)
            {
                temp = temp->next;
                count++;
            }

            if (temp == nullptr)
            {
                cout << "Position out of range, inserting at the end\n";
                insertAtTail(data);
                return;
            }

            Node *n = new Node(data);
            n->next = temp->next;
            temp->next = n;
        }
    }

    void display()
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "list is empty";
            return;
        }
        while (temp != nullptr)
        {

            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteNodeAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = head;
        if (position == 1)
        {
            head = temp->next;
            delete temp;
            return;
        }
        int count = 1;
        Node *current = head;
        Node *prev = nullptr;
        while (count < position && current->next != nullptr)
        {
            prev = current;
            current = current->next;
            count++;
        }
        if (current == nullptr)
        {
            cout << "Position out of range, deleting last node\n";
            tail = prev;
            delete prev;
            return;
        }

        prev->next = current->next;
        delete current;
    }
};

int main()
{
    list l;
    while (true)
    {
        cout << "What do you want to do: " << endl;
        cout << "1. Insert at Head\n"
             << "2. Insert at Tail\n"
             << "3. Insert at any position\n"
             << "4. Delete at any position\n"
             << "5. Display list\n"
             << "6. Exit\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            int data;
            cin >> data;
            l.insertAtHead(data);
            break;

        case 2:
            cout << "Enter data: ";
            cin >> data;
            l.insertAtTail(data);
            break;

        case 3:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            int position;
            cin >> position;
            l.insertAtPosition(data, position);
            break;

        case 4:
            cout << "Enter position: ";
            cin >> position;
            l.deleteNodeAtPosition(position);
            break;

        case 5:
            l.display();
            break;

        case 6:
            cout << "Exiting...";
            return 0;

        default:
            cout << "Enter right choice\n";
            break;
        }
    }

    return 0;
}
