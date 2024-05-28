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
            head->prev = n;
            head = n;
        }
    }

    void insertAtTail(int data)
    {
        Node *n = new Node(data);
        tail->next = n;
        n->prev = tail;
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
            n->prev = temp;
            temp->next = n;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }

    void deleteNodeAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        int count = 1;
        Node *current = head;

        while (count < position && current->next != nullptr)
        {
            current = current->next;
            count++;
        }
        if (current == nullptr)
        {
            cout << "Position out of range\n";
            return;
        }
        if (current == head)
        {
            head = current->next;
        }
        else
        {
            current->prev->next = current->next;
        }
        if (current == tail)
        {
            tail = current->prev;
        }
        else
        {
            current->next->prev = current->prev;
        }

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
