#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
    Node *head;

public:
    CircularLinkedList() {
        this->head = nullptr;
    }

    void insertAtHead(int data) {
        Node *n = new Node(data);
        if (head == nullptr) {
            head = n;
            head->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            n->next = head;
            temp->next = n;
            head = n;
        }
    }

    void insertAtTail(int data) {
        Node *n = new Node(data);
        if (head == nullptr) {
            head = n;
            head->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = n;
            n->next = head;
        }
    }

    void insertAtPosition(int data, int position) {
        if (position == 1) {
            insertAtHead(data);
            return;
        } else {
            Node *temp = head;
            int count = 1;
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
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "HEAD\n";
    }

    void deleteNodeAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (position == 1) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                Node *temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                Node *toDelete = head;
                temp->next = head->next;
                head = head->next;
                delete toDelete;
            }
            return;
        }

        Node *current = head;
        int count = 1;
        while (count < position - 1 && current->next != head) {
            current = current->next;
            count++;
        }

        if (current->next == head || count != position - 1) {
            cout << "Position out of range\n";
            return;
        }

        Node *toDelete = current->next;
        current->next = toDelete->next;
        delete toDelete;
    }
};

int main() {
    CircularLinkedList cll;
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
            cll.insertAtHead(data);
            break;

        case 2:
            cout << "Enter data: ";
            cin >> data;
            cll.insertAtTail(data);
            break;

        case 3:
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            int position;
            cin >> position;
            cll.insertAtPosition(data, position);
            break;

        case 4:
            cout << "Enter position: ";
            cin >> position;
            cll.deleteNodeAtPosition(position);
            break;

        case 5:
            cll.display();
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
