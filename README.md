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
       

 
