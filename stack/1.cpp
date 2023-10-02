// stack implementation in c++

#include <iostream>
#include <stack>
using namespace std;

int main(){

    // create a stack of integers

    std::stack<int> myStack;

    //push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // check if the stack is empty
    if(myStack.empty()){
        cout << "Stack is empty.\n";
    } else{
            cout << "Stack is not empty.\n";
    }

    // Get the size of the stack
    cout << "Size of stack: " << myStack.size() << endl;

    // access the top element of the stack
    cout << "Top element: " << myStack.top() << endl;

    // pop elements from stack 
    while (!myStack.empty())
    {
        cout << "Popped: " << myStack.top() << endl;
        myStack.pop();
    }
    
    // check if the stack is empty again
    if (myStack.empty()){
        cout << "Stack is empty.\n";
    } else{
        cout << "Stack is not empty.\n";
    }

    return 0;   
}