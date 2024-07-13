# Breadth-First Search (BFS)

## Overview
Breadth-First Search (BFS) is an algorithm for traversing or searching tree or graph data structures. It explores all nodes at the present depth level before moving on to nodes at the next depth level.

## Algorithm
1. **Start at the root node** (or any arbitrary node for a graph).
2. Initialize a queue and enqueue the starting node.
3. **While the queue is not empty:**
   - Dequeue the front node.
   - Process the dequeued node (e.g., visit or print it).
   - Enqueue all adjacent nodes that haven't been visited yet.

## Example
Consider the following graph:
```
    A
   / \
  B   C
 / \   \
D   E   F
```


Starting BFS from node `A`:

1. Initialize the queue with `A`: Queue = [A]
2. Dequeue `A`, visit `A`, enqueue `B` and `C`: Queue = [B, C]
3. Dequeue `B`, visit `B`, enqueue `D` and `E`: Queue = [C, D, E]
4. Dequeue `C`, visit `C`, enqueue `F`: Queue = [D, E, F]
5. Dequeue `D`, visit `D`: Queue = [E, F]
6. Dequeue `E`, visit `E`: Queue = [F]
7. Dequeue `F`, visit `F`: Queue = []

Order of nodes visited: **A, B, C, D, E, F**

## Applications
- Shortest path in unweighted graphs
- Crawling the web
- Social network analysis

# Depth-First Search (DFS)

## Overview
Depth-First Search (DFS) is an algorithm for traversing or searching tree or graph data structures. It explores as far down as possible along each branch before backtracking.

## Algorithm
1. **Start at the root node** (or any arbitrary node for a graph).
2. Initialize a stack and push the starting node.
3. **While the stack is not empty:**
   - Pop the top node.
   - Process the popped node (e.g., visit or print it).
   - Push all adjacent nodes that haven't been visited yet onto the stack.

## Example
Consider the following graph:

```
    A
   / \
  B   C
 / \   \
D   E   F

```

Starting DFS from node `A`:

1. Initialize the stack with `A`: Stack = [A]
2. Pop `A`, visit `A`, push `C` and `B`: Stack = [C, B]
3. Pop `B`, visit `B`, push `E` and `D`: Stack = [C, E, D]
4. Pop `D`, visit `D`: Stack = [C, E]
5. Pop `E`, visit `E`: Stack = [C]
6. Pop `C`, visit `C`, push `F`: Stack = [F]
7. Pop `F`, visit `F`: Stack = []

Order of nodes visited: **A, B, D, E, C, F**

## Applications
- Pathfinding and maze solving
- Topological sorting
- Detecting cycles in a graph

# Comparison

- **BFS** explores level by level, making it suitable for finding the shortest path in unweighted graphs. It uses a queue, leading to broader but shallower searches.
- **DFS** explores as deep as possible along a branch before backtracking, making it useful for scenarios like pathfinding where you need to explore all possibilities. It uses a stack, leading to deeper but narrower searches.

Both algorithms have their strengths and are used based on the specific requirements of the problem at hand.
