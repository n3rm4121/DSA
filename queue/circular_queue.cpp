#include <iostream>
using namespace std;

const int maxSize = 5;

class Queue {
    int arr[maxSize]{};
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isFull() {
        if ((rear + 1) % maxSize == front) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        }
        return false;
    }

    void push(int data) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % maxSize;
        }
        arr[rear] = data;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return;
        }
        else if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % maxSize;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty Queue\n";
            return;
        }
        int i = front;
        cout << "Queue: ";
        do {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize);
        cout << endl;

        cout << "Front index: " << front << "\nRear index: " << rear << endl;
    }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.display();

    return 0;
}
