#include <iostream>
using namespace std;

const int n = 5;
class Queue{
    int arr[n];
    int rear,front;

    public: 
    
        Queue() : rear(-1), front(-1){}

        // checking if queue is full
        bool isFull(){
            if(rear == n-1){
                return true;
            }else
            return false;
        }

        // checking if queue is empty
        bool isEmpty(){
            if(front > rear || front == -1){
                return true;
            }else{
                return false;
            }
        }

        // function to implement enqueue operation
        void enqueue(int item){
            if(isFull()){
                cout << "Overflow!" << endl;
                return;
            }else{
                if(front == -1 && rear == -1){
                    front = 0;
                    rear = 0;
                }else{
                    rear++;
                 
                }
                cout << "Element inserted! at index: " << rear << endl;
                arr[rear] = item;
                
            }
        }

        // function to implement dequeue operation
        void dequeue(){
            if(isEmpty()){
                cout << "Underflow!";
                return;
            }else
                {
                    int item = arr[front];
                    cout << "Item being deleted: " << item << endl;
                    if(front == rear){
                        front = -1;
                        rear = -1;
                    }else
                        front++;
                }
        }
        
        void front_element(){
            cout <<"front element is: "<<  arr[front] << endl;
        }

        // function to display elements of queue
        void display(){
            if(front == -1 || isEmpty()){
                cout << "\nThe array is empty\n";
            }else{
                cout << "The elements are: " << endl;
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
                cout << endl;
            }
        }
       

};

int main(){
    Queue d1;
    d1.enqueue(1);
    d1.enqueue(2);
    d1.enqueue(3);
    d1.enqueue(4);
    d1.enqueue(5);
    d1.enqueue(6);
    d1.front_element();
    d1.display();

    d1.dequeue();
    d1.dequeue();
    d1.dequeue();
    d1.dequeue();
    d1.dequeue();
    d1.dequeue();
    
    d1.display();
    return 0;
}