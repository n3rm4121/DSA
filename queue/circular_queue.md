# 1. Circular Queue

A circular queue is a data structure that allows you to efficiently add and remove elements from both ends of the queue. It is similar to a regular queue, but with the added feature that the last element is connected to the first element to form a circle.

In a circular queue, elements are stored in a fixed-size array, and two pointers are used to keep track of the front and rear of the queue. The front pointer points to the first element of the queue, and the rear pointer points to the last element of the queue.


When an element is added to the queue, it is inserted at the rear of the queue and the rear pointer is incremented. If the rear pointer reaches the end of the array, it is wrapped around to the beginning of the array to form a circle.


When an element is removed from the queue, it is removed from the front of the queue and the front pointer is incremented. If the front pointer reaches the end of the array, it is wrapped around to the beginning of the array to form a circle.

Circular queues are useful in situations where you need to maintain a fixed-size buffer of elements that can be efficiently accessed from both ends. They are commonly used in operating systems, network protocols, and other applications where data needs to be buffered and processed in a circular fashion.

Here's an example of how you can implement a circular queue in C++ using an array:

Here, we have defined a CircularQueue class that uses an array to implement a circular queue. The front and rear pointers are initialized to -1 in the constructor to indicate that the queue is empty.

The isFull function checks if the queue is full by checking if the front and rear pointers are at the beginning and end of the array, respectively, or if the rear pointer is one position behind the front pointer.

The isEmpty function checks if the queue is empty by checking if the front pointer is -1.

The enqueue function adds an element to the rear of the queue by incrementing the rear pointer and wrapping it around to the beginning of the array if necessary.

The dequeue function removes an element from the front of the queue by incrementing the front pointer and wrapping it around to the beginning of the array if necessary.

The display function displays the elements of the queue from front to rear by iterating over the array using the front pointer and wrapping it around to the beginning of the array if necessary.

[circular queue](circular_queue.cpp)

