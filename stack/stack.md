# Stack

Stack is linear data structure that follows the principle of Last In First Out (LIFO) i.e. the last element inserted will be removed first.

`Think like the pile of plates on top of another.`

<hr>
Note: 

`Push -> putting an item on top of stack.`<br><br>
`Pop -> Removing an item.`

<hr>

### Basic operation of stack

- Push : Add an element to the top of stack.
- Pop : Remove 
- IsEmpty : Check if the stack is empty.
- IsFull : Check if the stack is Full.
- Peek(or Top) : Get the value of the top element without removing it.
- Size : To get the no. of elements in the stack.

#### Implementation:
 Stack can be implemented using arrays or linked lists.

<hr>

#### Example use cases:
- Function call stack
- Undo/Redo Functionality
- Expression Evaluation(eg. infix to postfix conversion)

<hr>

#### Stack Overflow and underflow
Happens if you attempt to pop from an empty stack-> stack underflow.
Happens if you attempt to push onto a stack that has reached its max size(array based implementation) -> stack overflow

#### Application:
- Managing function calls in programming languages,
- Parsing expressions,
- backtracking algorithms like depth-first search(DFS).

#### Complexity: 
Usually O(1)

### Working of stack data structure

1. A pointer called **TOP** is used to keep track of the top element in the stack.

2. When initializing the stack, we set its value to -1 so that we can check if the stack is empty by comparing ` Top == -1 `.

3. On pushing an element, we increase the value of `Top` and place the new element in the position pointed to by `Top`.

4. On popping an element, we return the element pointed to by `TOP` and reduce its value.

5. Before pushing, we check if the stack is already full.

6. Before popping, we check if the stack is already empty

<br>
Check out: 

[Stack Implementation in C++](1.cpp)

