# Analysis and Design of Algorithms

## Index
- [x] Quicksort
    - sorting of an array using a pivot ensuring the elements to the left of the pivot are smaller than the pivot and elements right of pivot are larger than it
    - The pivot is put in the position where it it should be when the whole array is sorted
    - Uses a recursive structure to sort each side split along the index of the pivot\
- [x] Iterative Quicksort
    - Quicksort in iterative form
    - Reduces the size of stack used
- [x] peak - Peak finding algorights for 1D and 2D arrays
    - Finding an element which is >= to its neighbours
    - [x] 1D 
        - Implemented using algo similar to Binary Search
    - [x] 2D
        - Implemented using algo similar to Binary Search but works in a 2D array
- [x] Magic square(odd size) - Sum of all rows, columns and diagonals is equals
    - Creates a square matrix where the sum of all colums, rows and diagonals is equal
    - Follows a set pattern in where the numbers increase in a diagonal upwards to the left and goes down one when number is a multiple of the size
- [x] Cosine Similarity
    - Find out the similarity between two documents by checking the number of time each word occours in each file
    - Each files words are treated like a vector and the angle between the vectors created from the two file give the value for cosQ which tells us the similarity between the files
- [x] Fractional Knapsack
    - Problem involving the calculation of max(here price) that can be gotten from a set of values
    - We sort the array according to the metric we need(here we sort 3 time, according to profit, weight and ratio of profit/weight) and then pick the items in non-increasing manner
    - The fractional part allows us to pick out items in fraction
        - For example if we have a capacity of 10 and the item weights 20 we can take out 10 out the weight instead of leaving that item and going to the next
- [x] Job Scheduling
    - Schedule all jobs for the day ensuring maximum number of jobs are done
    - FCFS, SJF and sorting by final_time used
     - Time complexity of SJF is very high due to checking of availibility of that job
- [ ] Matrix multiplication
    - [x] Conventional Method
        - Using divide and conquer to break the matrix into smaller parts and multiplying them to get the resulting martix
    - [ ] Strassen's matrix multiplication
        - turn the O(n<sup>3</sup>) algo into a O(n<sup>2.81</sup>) algo
- [ ] Polygon Hull
    - [x] QuickHull
        - [x] Using aproch similar to quicksort we divide the problem into multiple triangles and seperately solve them\
- [ ] Find all possible triangles
- [ ] Find if point lies in a triangle
- [x] Kruskal Algorithm
  - Kruskal’s Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, connected, undirected graph. It sorts edges by weight and adds them one by one, ensuring no cycles form using Union-Find.
  - Sorting edges: O(E log E)
  - Union-Find operations: O(E log V)
  - Overall Complexity: O(E log E) ≈ O(E log V)
- [x] Prims Algorithm
      -Prim's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, connected, and undirected graph. It starts with a single vertex and iteratively adds the smallest edge that connects a new vertex to the growing MST.
- Finds the MST of a graph.
- Uses a priority queue (heap) for efficient edge selection.
- Works with adjacency matrix or adjacency list representations.
- O(V²) for adjacency matrix
- O(E log V) using a priority queue (better for sparse graphs)
 - [x] Dijkstra Algorithm
       - Dijkstra’s Algorithm is a graph-based shortest path algorithm that finds the minimum distance from a single source node to all other nodes in a weighted graph. It is widely used in network routing, GPS navigation, and AI pathfinding.
     - O(V²) using an adjacency matrix
     - O((V + E) log V) using a priority queue (better for sparse graphs)
- [x] All Pairs Shortest Path
     - The All-Pairs Shortest Path (APSP) algorithm finds the shortest path between every pair of nodes in a weighted graph.
     -  Computes shortest paths between all pairs of vertices
     - Supports negative edge weights (Floyd-Warshall & Johnson’s Algorithm)
     - Works for directed & undirected graph.
 - [x] Multistage Graph Algorithm
         - The Multistage Graph algorithm is used to find the shortest path in graphs with stages, where the vertices can be grouped into stages. It’s particularly useful in network routing, scheduling problems, and decision-making models where you need to move from one stage to the next.
       This algorithm works by dividing the graph into different stages, and finding the optimal path through these stages using dynamic programming.
 - [x] Longest common subsequence
 - [ ]  The LCS problem aims to find the longest subsequence common to two given sequences (not necessarily contiguous).Given two sequences X[0..m-1] and Y[0..n-1], find the length and the actual LCS that appears in both sequences in the same order, but not necessarily consecutively.
- [x] N Queens
- [ ] Place N queens on an N x N chessboard such that:

No two queens share the same row.

No two queens share the same column.

No two queens share the same diagonal.
- [x] M color problem
- [ ] he M-Coloring problem is a classic problem in graph theory where the goal is to determine if it's possible to color the vertices of a graph using at most M colors such that no two adjacent vertices share the same color.

Problem Statement
Given an undirected graph and an integer M, determine if the graph can be colored with at most M colors such that no two adjacent vertices have the same color.

Approach
This solution uses a backtracking approach:

Try assigning colors to each vertex starting from vertex 0.

For each vertex, try all colors from 1 to M.

Before assigning a color, check if it is safe (i.e., no adjacent vertex has the same color).

If safe, assign the color and recursively proceed to the next vertex.

If a solution is found, return True; otherwise, backtrack.
- [x] Hamiltonian cycle
- [ ] A Hamiltonian Cycle in an undirected or directed graph is a cycle that visits each vertex exactly once and returns to the starting vertex.

Problem Statement
Given an undirected graph, determine whether a Hamiltonian Cycle exists. If such a cycle exists, output one possible cycle; otherwise, report that no cycle is possible.

Approach
This solution uses a backtracking algorithm:

Start at an arbitrary vertex (usually vertex 0).

Recursively try to add vertices to the path, ensuring that:

The next vertex is adjacent to the current vertex.

The vertex hasn’t been visited before.

Once all vertices are included in the path, check if the last vertex connects back to the starting vertex to complete the cycle.

If a valid cycle is found, return it; otherwise, backtrack and try other possibilities.

- [x] Sum of subsets
- [ ] The goal is to find all subsets of a given set of positive integers whose sum equals a specified target value.

Problem Statement
Given a set of positive integers and a target sum W, find all subsets whose elements sum to W. Each element can be used only once.

Approach
The solution uses backtracking to explore all subset combinations:

Start with an empty subset and a running sum of 0.

At each step, choose whether to include the current element.

If the current subset’s sum equals the target, record it as a valid solution.

Prune the search space if the current sum exceeds the target.



       

 
