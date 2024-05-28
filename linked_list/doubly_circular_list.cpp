#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class list {
    Node *head;
    Node *tail;

public:
    list() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtHead(int data) {
        Node *n = new Node(data);

        if (head == nullptr && tail == nullptr) {
            head = n;
            tail = n;
            head->next = tail;
            head->prev = tail;
            tail->next = head;
            tail->prev = head;
        } else {
            n->next = head;
            n->prev = tail;
            head->prev = n;
            tail->next = n;
            head = n;
        }
    }

    void insertAtTail(int data) {
        Node *n = new Node(data);

        if (head == nullptr && tail == nullptr) {
            head = n;
            tail = n;
            head->next = tail;
            head->prev = tail;
            tail->next = head;
            tail->prev = head;
        } else {
            tail->next = n;
            n->prev = tail;
            n->next = head;
            head->prev = n;
            tail = n;
        }
    }

    void insertAtPosition(int data, int position) {
        if (position == 1) {
            insertAtHead(data);
            return;
        } else {
            int count = 1;
            Node *temp = head;
            while (count != position - 1 && temp->next != head) {
                temp = temp->next;
                count++;
            }

            if (temp->next == head && count != position - 1) {
                cout << "Position out of range, inserting at the end\n";
                insertAtTail(data);
                return;
            }

            Node *n = new Node(data);
            n->next = temp->next;
            n->prev = temp;
            temp->next->prev = n;
            temp->next = n;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node *current = head;
        do {
            cout << current->data << " <-> ";
            current = current->next;
        } while (current != head);
        cout << "Head\n";
    }

    void deleteNodeAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        int count = 1;
        Node *current = head;

        while (count < position && current->next != head) {
            current = current->next;
            count++;
        }
        if (count != position) {
            cout << "Position out of range\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else if (current == head) {
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete current;
        } else if (current == tail) {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete current;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }
};

int main() {
    list l;
    while (true) {
        cout << "What do you want to do: " << endl;
        cout << "1. Insert at Head\n"
             << "2. Insert at Tail\n"
             << "3. Insert at any position\n"
             << "4. Delete at any position\n"
             << "5. Display list\n"
             << "6. Exit\n";
        int choice;
        cin >> choice;
        switch (choice) {
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
