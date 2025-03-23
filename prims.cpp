#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int findminvertex(vector<int>&weights,vector<bool>&visited,int n){
    int minvertex=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] &&(weights[i]<weights[minvertex])){
            minvertex=i;
        }
    }
    return minvertex;
}

void primsalgorithm(int **graph,int n){
    vector<int>parent(n,-1);
    vector<int>weights(n,INT_MAX);
    vector<bool>visited(n,false);

    weights[0]=0;

    for(int i=0;i<n;i++){
        int minvertex = findminvertex(weights,visited,n);
        visited[minvertex]=true;

        for(int j=0;j<n;j++){
            if(graph[minvertex][j] !=0 && !visited[j]){
                if(graph[minvertex][j]< weights[j]){
                    weights[j]=graph[minvertex][j];
                    parent[j]= minvertex;
                }
            }
        }
        
    }
    cout<<"Minimum Spanning tree"<<endl;
    for(int i=1;i<n;i++){
        cout<<parent[i]<<"-"<<i<<" (Weight: " << weights[i] << ")" << endl;
        
    }
}

int main(){
    int n;
    cout<<"Enter the number of vertices";
    cin>>n;

    int** graph= new int*[n];
    for(int i=0;i<n;i++){
        graph[i]= new int [n];
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }

    primsalgorithm(graph,n);
    return 0;

}




