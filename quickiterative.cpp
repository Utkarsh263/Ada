#include <iostream>
#include <stack>
using namespace std;

void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}

int partition(int arr[],int l,int h){
    int pivot=arr[l];
    int i=l;
    int j=h;
    while(i<j){
        while(arr[i]<=pivot &&i<h ){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;
}



void quicksortiterative(int arr[],int l,int h){
    stack<int>s;

    s.push(l);
    s.push(h);//Push low and high index for function partition

    while(!s.empty()){
        h=s.top();
        s.pop();
        l=s.top();
        s.pop();

        int p=partition(arr,l,h);

        if(p-1>l){
            s.push(l);
            s.push(p-1);
        }
        if(p+1<h){
            s.push(p+1);
            s.push(h);
        }
    }
}

void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){
    int arr[5]={12,2,4,56,5};
    int n=5;
    quicksortiterative(arr,0,n-1);
    cout<<"Sorted array will be"<<endl;
    printarray(arr,n);


}