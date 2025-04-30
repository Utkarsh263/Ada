#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for (int k = 0; k < n; k++) {
        if (graph[node][k] && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, bool graph[101][101], int m, int n, int color[]) {
    if (node == n)
        return true;  

    for (int col = 1; col <= m; col++) {
        if (isSafe(node, color, graph, n, col)) {
            color[node] = col;
            if (solve(node + 1, graph, m, n, color))
                return true;
            color[node] = 0;  
        }
    }

    return false;  
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int color[101] = {0};

    return solve(0, graph, m, n, color);
}

int main() {
    int n = 4; 
    int m = 3;

    
    bool graph[101][101] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (graphColoring(graph, m, n))
        cout << "Solution exists: Coloring is possible.\n";
    else
        cout << "Solution does not exist: Coloring is not possible.\n";

    return 0;
}
