// stack implementation using array

#include <iostream>

const int MAX_SIZE = 5;  // Maximum size of the stack

class Stack {
private:
    int top;             // Index of the top element
    int arr[MAX_SIZE]={}; // Array to store elements

public:
    Stack() {
        top = -1;        // Initialize the top index to -1 (empty stack)
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int data) {
        if (isFull()) {
            std::cout << "Stack overflow. Cannot push " << data << std::endl;
            return;
        }
        arr[++top] = data;
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack underflow. Cannot pop from an empty stack." << std::endl;
            return -1;  // Return a sentinel value (you can choose a different approach)
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot peek." << std::endl;
            return -1;  // Return a sentinel value (you can choose a different approach)
        }
        return arr[top];
    }

    void showarray(){
        for (int i = 0; i < top; i++)
        {
            std::cout << arr[i] << " " ;
        }
        
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.showarray();
    std::cout << "Top element: " << stack.peek() << std::endl;

    while (!stack.isEmpty()) {
        std::cout << "Popped: " << stack.pop() << std::endl;
    }
    stack.showarray();
    return 0;
}
