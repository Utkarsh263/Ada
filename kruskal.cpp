#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge{
public:
    int source, destination,weight;
};

bool compare(Edge e1,Edge e2){
    return e1.weight <e2.weight;
}

int findparent(int vertex, vector<int>&parent){
    if(vertex==parent[vertex]){
        return vertex;
    }
    return findparent(parent[vertex],parent);
}

void kruskal(int n, vector<Edge> &edges){
    //Sorting 
    sort(edges.begin(),edges.end(),compare);

    //Parent array
    vector<int>parent(n);

    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    vector<Edge>mst;
    int totalweight=0;

    for(Edge edge: edges){
        int sourceparent= findparent(edge.source, parent);
        int destinationparent= findparent(edge.destination, parent);

        if(sourceparent != destinationparent){
            mst.push_back(edge);
            totalweight += edge.weight;

            parent[sourceparent]= destinationparent;
        }

        if(mst.size()==n-1){
            break;
        }
    }
    cout << "Minimum Spanning Tree:" << endl;
    for (Edge edge : mst) {
        cout << edge.source << " - " << edge.destination << " (Weight: " << edge.weight << ")" << endl;
    }
    cout << "Total Weight of MST: " << totalweight << endl;
}

int main(){
    int n,e;
    cout<<"Enter the number of vertex and edges";
    cin>>n>>e;

    vector<Edge> edges(e);

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    kruskal(n,edges);

    return 0;
}