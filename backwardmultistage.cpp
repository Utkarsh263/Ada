#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void multistagebackward(vector<vector<int>> &graph, int n){
    vector<int>dp(n,INT_MAX);
    vector<int>stage(n,0);

    dp[0]=0;// distance of first node will be 0
    stage[0]=1;// source node will be at stage 1

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(graph[i][j]!=0){
                if(dp[i]>dp[j]+graph[i][j]){
                    dp[i]= dp[j]+graph[i][j];
                    stage[i]= stage[j]+1;
                }
            }
        }
    }
    cout<<"Vertex\tStage\tDistance to Destination"<<endl;
    for(int i=0;i<n;i++){
        cout << i << "\t" << stage[i] << "\t" << dp[i] << endl;
    }

}

int main(){
    int n=7;

    vector<vector<int>> graph = {
        {0, 1, 2, 0, 0, 0},
        {0, 0, 0, 2, 3, 0},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    multistagebackward(graph,n);
    return 0;
}