# Queue

 It is a linear data structure where elements are inserted at the rear (also known as the "enqueue" operation) and removed from the front (the "dequeue" operation). Think of it like a queue of people waiting in line; the person who arrives first is the first one to leave.
 It is a template class that allows you to create instances of a queue data structure for different data types (e.g., 
 ```
 Queue<int> for integers or Queue<std::string> for strings).
 ```
 
 
 ## Operation
 
- Enqueue: Adding an element to the rear of the queue.
- Dequeue: Removing the element from the front of the queue.
- Peek/Front: Viewing the element at the front of the queue without removing it.
- IsEmpty: Checking if the queue is empty.
- IsFull : Checking if the queue is full.

## Working

- Two pointers `Front` and `rear` 
- `Front` tracks the first element and `rear` tracks the last element
- Initially set value of `front` and `rear` to -1.

## Enqueue Operation

- check if the queue is full
- for the first element, set the value of `front` to 0
- increase `rear` index by 1
- add the new element in the position pointed by `rear`

## Dequeue Operation
- check if the queue is empty
- return the value pointed by `font`
- increase `font` index by 1
- for the last element, reset the values `front` and `rear` to -1


## Use Cases:

- Task scheduling: Queue data structures are used in operating systems to manage processes or tasks waiting to be executed.
- Print spooling: Print jobs are placed in a queue and processed in the order they are received.
- Breadth-First Search (BFS) in graphs: Queues are essential for traversing graphs in a breadth-first manner.
- Simulations: Queues are often used to model scenarios where entities need to wait their turn.


## Implementation: 

Queues can be implemented using various data structures, including arrays, linked lists, and, in some cases, specialized data structures like a priority queue.