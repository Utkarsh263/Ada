#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void findstages(vector<vector<int>> &graph ,int n){
    vector<int>stage(n,0);//Array to store the stages
    vector<int>dp(n,INT_MAX); //Array to store the dp array which has been initialised with infinity at start

    stage[n-1]=1; // Last node stage will be at 1st stage
    dp[n-1]=0; // Last node distance to its own will be zero

    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(graph[i][j]!=0){  // There is an edge between i and j
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
    int n=6;
    vector<vector<int>> graph = {
        {0, 1, 2, 0, 0, 0},
        {0, 0, 0, 2, 3, 0},
        {0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    findstages(graph,n);
}