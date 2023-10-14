#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class CircularQueue {
private:
    int front, rear;
    int arr[MAX_SIZE];
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        // for circular queue full condition

        return (rear + 1 ) % MAX_SIZE == front;
       
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full." << endl;
        } else
            if(isEmpty()){
                front = 0;
              
            }
        else    
         rear = (rear + 1) % MAX_SIZE;
         arr[rear] = x;

    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        } else
            if(front == rear){
                front = -1;
                rear = -1;
            }else
                rear  = (rear - 1) % MAX_SIZE ; // to maintain circular loop

                
           front++;
           
            
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        } else {
            cout << "Elements in the queue: ";
            int i;
            for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
                cout << arr[i] << " ";
            }
            cout << arr[i] << endl;
        }
    }
};

int main() {
    CircularQueue q;
    q.enqueue(3);
    q.display();
    q.enqueue(4);
    q.display();
    q.enqueue(5);
    q.display();
    q.enqueue(6);
    q.display();
    // q.enqueue(7);


    
    q.dequeue();

    q.display();

    q.dequeue();

    q.display();

    q.enqueue(3);
    q.enqueue(4);
    q.display();
}