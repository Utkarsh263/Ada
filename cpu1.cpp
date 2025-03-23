#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int sjf(float finish[],float arrival[],int n){
    // Bubble sort for sorting
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){ //O(n^2)
            if(finish[j]>finish[j+1]){
                swap(finish[j],finish[j+1]);
                swap(arrival[j],arrival[j+1]);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(finish[i]<arrival[i+1]){
            cnt++;
        }
    }
    return cnt;
}

// void printtime(float arrival[],float finish[],int n){
//     for(int i=0;i<n;i++){
//         cout<<"Arrival time="<<arrival[i]<<endl;
//         cout<<"Departure time="<<finish[i]<<endl;
//     }
// }

int main(){
    int n;
    cout<<"input size =";
    cin>>n;
    float *arrival=new float[n];
    float *finish=new float[n];
    for(int i=0;i<n;i++){
        cout<<"Enter arrival time for"<<i<<"=";
        cin>>arrival[i];
        cout<<"Enter finish time for"<<i<<"=";
        cin>>finish[i];
    }
    cout<<sjf(finish,arrival,n);
    // printtime(arrival,finish,n);

    return 0;
    
}