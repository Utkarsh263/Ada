#include <iostream>
#include <vector>
#include <climits>

using namespace std;


const int INF= INT_MAX;

void allpairshortestpath(vector<vector<int>>&graph, int V){
    vector<vector<int>>dist= graph;

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                //condition of floydd warshall method
                if(dist[i][k] != INF && dist[k][j]!= INF && dist[i][k]+ dist[k][j] < dist[i][j]){
                    dist[i][j]= dist[i][k]+dist[k][j];
                }
            }
        }
    }

    cout<<"The all pair shortest path of the graph is"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]== INF){
                cout<<"INF";
            }else{
                cout<<dist[i][j]<<"\t";
            }
        }
        cout<<"\n";
    }
}



int main(){
    int V=4;
    vector<vector<int>>graph={
        {0,3,2,5},
        {2,0,INF,4},
        {INF,0,1,INF},
        {INF,INF,2,0}
    };

    allpairshortestpath(graph, V);

    return 0;
}
