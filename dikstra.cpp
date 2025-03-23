#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int findminimumdistance(vector<int> &distances, vector<bool>&visited, int n){
    int minvertex = -1;
    for(int i=0;i<n;i++){
        if(!visited[i] && (minvertex==-1 ||distances[i]<distances[minvertex])){
            minvertex=i;
        }
    }

    return minvertex;
}

void dijkstra(int**graph,int n,int source){
    vector<int> distances(n,INT_MAX);
    vector<bool>visited(n,false);

    distances[source]=0;

    for(int i=0;i<n-1;i++){
        int minvertex= findminimumdistance(distances, visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++){
            if(graph[minvertex][j] !=0 && !visited[j]){
                int newdist= distances[minvertex] + graph[minvertex][j];
                if(newdist<distances[j]){
                    distances[j]= newdist;                }
            }
        }
    }
    cout<<"Vertex\tDistance from source"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<"\t"<<distances[i]<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the number of vertices";
    cin>>n;

    int** graph= new int*[n]; //Allocate memory for rows
    cout<<"Enter the adjancency matrix for the graph"<<endl;

    for(int i=0;i<n;i++){
        graph[i]= new int[n];  //Allocate memory for columns
        for(int j=0;j<n;j++){
            cin>> graph[i][j];
        }
    }

    int source;
    cout<<"Enter the source vertex";
    cin>>source;

    dijkstra(graph,n,source);

    return 0;
}