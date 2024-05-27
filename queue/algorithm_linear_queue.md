# Enqueue Operation

### Algorithm Enqueue(value):

```
Input: value (the element to be inserted)
1. If rear == MAX_SIZE - 1, then
   1.1. Print "Queue is full. Cannot enqueue."
   1.2. Exit
2. Increment rear by 1
3. Set queue[rear] = value
4. If front is -1, then
   4.1. Set front = 0
5. Print "Element value enqueued successfully."
```

## Explanation:

   <li>The `Enqueue` algorithm inserts an element into the linear queue.</li> 
    <li>It first checks if the rear pointer has reached the maximum capacity of the queue.</li>
    <li>If the queue is not full, it increments the rear pointer, assigns the value to that position, and updates the rear.</li>
    <li>If the queue was empty before enqueue, it sets the front to the first position in the queue.</li>


# Dequeue Operation

#### Algorithm Dequeue():
```
1. If front == -1 or front > rear, then
   1.1. Print "Queue is empty. Cannot dequeue."
   1.2. Exit
2. Set value = queue[front]
3. Increment front by 1
4. If front > rear, then
   4.1. Set front = rear = -1
5. Print "Element value dequeued successfully."
6. Return value

```

## Explanation:
<br>
    <li>The `Dequeue` algorithm removes and returns the front element from the linear queue.</li> 
    <li>It first checks if the queue is empty by checking if the front is equal to -1 or if the front pointer is greater than the rear pointer.</li>
    <li>If the queue is not empty, it retrieves the value at the front position, increments the front pointer, and checks if the queue becomes empty after dequeueing the element.</li>
    <li>If the queue becomes empty, it resets both front and rear to -1.</li>
    <li>Finally, it returns the dequeued value.</li>
