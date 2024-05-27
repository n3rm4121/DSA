## Insertion at Beginning

#### Algorithm InsertAtBeginning(value):

```
Input: value (the element to be inserted)
1. Create a new node newNode and set its data to value
2. Set newNode's next pointer to point to the current head of the list
3. Set the head of the list to newNode
4. Print "Element value inserted at the beginning successfully."
```

### Explanation:

  <li>The InsertAtBeginning algorithm inserts a node with the given value at the beginning of the singly linked list.</li>
  <li>It creates a new node with the given value, sets its next pointer to the current head of the list, and then updates the head of the list to point to the new node.</li> 

  ## Insertion at End

  #### Algorithm InsertAtEnd(value):
  ```
Input: value (the element to be inserted)
1. Create a new node newNode and set its data to value
2. If the list is empty (head is null), then
   2.1. Set the head of the list to newNode
   2.2. Return
3. Traverse the list until the last node
4. Set the next pointer of the last node to point to newNode
5. Print "Element value inserted at the end successfully."
```

### Explanation:
  <li>The InsertAtEnd algorithm inserts a node with the given value at the end of the singly linked list.</li>
   <li>If the list is empty, it simply sets the head of the list to the new node.</li> 
    <li>Otherwise, it traverses the list until the last node is reached, then sets the next pointer of the last node to point to the new node.</li>

## Insertion After Specific Position

#### Algorithm InsertAfterPosition(position, value):
```
Input: position (the position after which the element will be inserted), value (the element to be inserted)
1. Create a new node newNode and set its data to value
2. Initialize a variable current to point to the head of the list
3. Traverse the list to find the node at position - 1
4. If position is greater than the number of nodes in the list, then
   4.1. Print "Position is out of range. Cannot insert."
   4.2. Return
5. Set newNode's next pointer to point to the next node of current
6. Set the next pointer of current to point to newNode
7. Print "Element value inserted after position successfully."
```
### Explanation:

  <li>The InsertAfterPosition algorithm inserts a node with the given value after a specific position in the singly linked list.</li>
   <li>It traverses the list to find the node at position - 1, then inserts the new node after this node.</li> 
    
## Insertion Before Specific Position

#### Algorithm InsertBeforePosition(position, value):
```
Input: position (the position before which the element will be inserted), value (the element to be inserted)
1. Create a new node newNode and set its data to value
2. Initialize a variable current to point to the head of the list
3. If position is 1, then
   3.1. Set newNode's next pointer to point to the current head of the list
   3.2. Set the head of the list to newNode
   3.3. Print "Element value inserted before position successfully."
   3.4. Return
4. Traverse the list to find the node at position - 2
5. If position is greater than the number of nodes in the list, then
   5.1. Print "Position is out of range. Cannot insert."
   5.2. Return
6. Set newNode's next pointer to point to the next node of current
7. Set the next pointer of current to point to newNode
8. Print "Element value inserted before position successfully."
```

### Explanation:

  <li>The InsertBeforePosition algorithm inserts a node with the given value before a specific position in the singly linked list.</li>
  <li>If the position is 1, it inserts the new node at the beginning of the list.</li>
  <li>Otherwise, it traverses the list to find the node at position - 2, then inserts the new node after this node.</li>

## Insertion at Specific Position

#### Algorithm InsertAtPosition(position, value):
```
Input: position (the position at which the element will be inserted), value (the element to be inserted)
1. Create a new node newNode and set its data to value
2. If position is 1, then
   2.1. Set newNode's next pointer to point to the current head of the list
   2.2. Set the head of the list to newNode
   2.3. Print "Element value inserted at position successfully."
   2.4. Return
3. Initialize a variable current to point to the head of the list
4. Initialize a variable count to 1
5. Traverse the list until count is one less than the desired position
6. If current is null, then
   6.1. Print "Position is out of range. Cannot insert."
   6.2. Return
7. Set newNode's next pointer to point to the next node of current
8. Set the next pointer of current to point to newNode
9. Increment count
10. Print "Element value inserted at position successfully."
```

### Explanation:

<li>The InsertAtPosition algorithm inserts a node with the given value at a specific position in the singly linked list.</li>
   <li>If the position is 1, it inserts the new node at the beginning of the list.</li> 
   <li>Otherwise, it traverses the list until it reaches one node before the desired position.</li>
    <li>If the position is out of range (greater than the number of nodes in the list), it prints an error message and returns without performing any insertion.</li>
    <li>If the position is valid, it inserts the new node after the current node.</li>
    
    
