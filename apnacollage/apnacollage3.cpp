#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void countSort(int * arr,int s){

    int k=arr[0];

    for(int i=0;i<s;i++)k=max(k,arr[i]);

  

    int count[k+1]={0};

    for(int i=0;i<s;i++)
        count[arr[i]]++;

    int cummulative_count[k+1]={0};
    

    cummulative_count[0]=count[0];
    cummulative_count[1]=count[1];

    for(int i=2;i<=k;i++)
        cummulative_count[i]=cummulative_count[i-1]+count[i];

    

    int ans_arr[s]={0};

    for(int i=(s-1);i>=0;i--){
        ans_arr[cummulative_count[arr[i]]-1]=arr[i];
        cummulative_count[arr[i]]--;
    }
        

    for(int i=0;i<s;i++){
        cout<<ans_arr[i]<<" ";
    }
    
}

int main(){
    int arr[]={1,3,2,3,4,1,6,4,3};
    int s=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<s;i++)cout<<arr[i]<<" ";
    cout<<"\n";
    countSort(arr,s);


    
}