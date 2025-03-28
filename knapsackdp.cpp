#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W,vector<int>&weights,vector<int>& values,int n){
    vector<int>dp(W+1,0);

    for(int i=0;i<n;i++){
        for(int w=W; w>= weights[i];w--){
            dp[w]= max(dp[w], values[i]+ dp[w-weights[i]]);
        }
    }
    return dp[W];
}

int main(){
    int n=3;
    vector<int>values={60,100,120};
    vector<int>weights={10,20,30};
    int W=50;

    cout<<"Maximum value:"<<knapsack(W,weights,values,n)<<endl;
    return 0;
}