#include <iostream>
using namespace std;

// declaring array of maximum capacity

int arr[10];
int n = 10;

// declaring front and rear and initializing both with -1
int front = -1;
int rear = -1;

// function to perform enqueue operation
void enqueue(int item){
    // checking overflow condition
    if(rear == n-1){
        cout << "Overflow!" << endl;
        return;
    }
    else{
        // front and rear are at -1 then
        // set front and rear at 0 otherwise increment rear
        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
        }else{
            rear++;
        }
        arr[rear] = item;
        cout << "Element inserted" << endl;
    }
}

// function to implement dequeue opeartion
void dequeue(){
    // checking underflow condition
    if(front == -1 || front > rear){
        cout << "Underflow" << endl;
        return;
    }
    else{
        int item = arr[front];
        //displaying deleted element
        cout << "Element deleted from queue is : " << item << endl;
        // if front and rear reach at the end then initialize it at -1
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            // increment the front
            front++;
        }
    }

}


