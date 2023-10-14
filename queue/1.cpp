#include <iostream>
using namespace std;
const int maxSize = 5;

class queue {
private:
    int arr[maxSize]{};
    int rear;
    int front;

public:
    queue() {
        rear = -1;
        front = -1;
    }

    bool isFull() {
        return rear == maxSize-1;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "\nOverflow!" << endl;
            return;
        } else {
            if (front == -1 && rear == -1) {
                front = rear = 0;
            } else {
                rear++;
            }
            cout << "\nElement inserted : " << item;
            arr[rear] = item;
        }
    }

    bool isEmpty() {
        return front == -1;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "\nUnderflow!" << endl;
            return;
        } else {
            cout << "\nElement deleted: " << arr[front] << endl;
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    void display() {
        cout << "\nFront index -> " << front << endl;
        cout << "rear index -> " << rear << endl;
        if (!isEmpty()) {
            cout << "Elements are: \n";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            cout << "queue is empty\n";
        }
    }
};
int main() {
    queue q;
    cout << "\nPerforming enqueue operation\n";
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(3);
    q.display();
    cout << "\nPerforming dequeue operation\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.display();
    
    q.dequeue();
    q.enqueue(2);
    q.display();
}
