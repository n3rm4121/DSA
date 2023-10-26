# Graph

Table of Contents:

1. [Graph Operation](#graph-operation) <br>
        i. [Minimum Spanning tree](#min-spanning-tree)
2. [Spanning Tree](#spanning-tree)


<h2 id="graph-operation">Graph Operation</h2>

- check if the element is present in graph
- Graph Traversal
- Add elements (vertex, edges) to graph
- Finding the path from one vertex to another


<h2 id = "spanning-tree">Spanning Tree </h2>
In the context of graph theory, a spanning tree of a undirected connected graph is a subgraph that includes all the vertices of the original graph while satisfying two key properties:

Connected: A spanning tree must be a connected subgraph, meaning there is a path between any pair of vertices in the tree.

Acyclic: A spanning tree must be acyclic, which means there are no cycles in the subgraph. In other words, you can't start at a vertex and follow edges to return to the same vertex without revisiting other edges along the way.

Key Points:

- A graph can have multiple spanning trees.
- Spanning trees are useful for network design, ensuring connectivity while avoiding redundancy.
- They are commonly used in algorithms for finding minimum spanning trees (e.g., Prim's and Kruskal's algorithms), which find the subset of edges in a weighted graph that connects all vertices with the minimum possible total edge weight.
- Spanning trees help simplify complex networks by creating hierarchical structures.
- In the context of computer networks, a spanning tree can be used to prevent loops, ensuring that packets don't circulate endlessly.
- If a vertex is missed, then it is not a spanning tree.
- The edges may or may not have weights assigned to them.



> Here's an analogy to help understand spanning trees: Imagine a city with various roads forming a connected network. A spanning tree represents a subset of these roads that allows you to travel to any part of the city without going in circles, while ensuring all areas are accessible.


In summary, a spanning tree is a tree-like subgraph of a connected graph, and it plays a crucial role in various graph-related problems, including network design, optimization, and preventing cycles in graphs.

> Total no. of spanning trees with `n` vertices that can be created from a complete graph is equals to n<sup>(n-2)</sup> 

If we have `n = 4`, the maximum number of possible spanning trees is equal to 4<sup>4-2</sup> = 16. Thus, `16` spanning trees can be formed from a complete graph with 4 vertices.

<h2 id = "min-spanning-tree">Minimum Spanning Tree</h2>

A minimum spanning tree is a spanning tree in which the sum of the weight of the edges is as minimum as possible.


<h2>Strongly Connected Components</h2>

A strongly connected component is the portion of a directed graph in which there is a path from each vertex to another vertex. It is applicable only on a `directed graph`.

