#include <iostream>
#include <climits>

#include <string>
#include<bits/stdc++.h>

using namespace std;

void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void waveSort(int arr[], int s){

    for(int i=1;i<s;i+=2){
        if(arr[i]>arr[i-1])swap(arr,i,i-1);
        if(arr[i]>arr[i+1] && i<=(s-2))swap(arr,i,i+1);
    }

}

int main(){
    int arr[]={1,3,4,7,5,6,2};
    for(int i : arr)cout<<i<<" ";
    cout<<"\n";
    int s=sizeof(arr)/sizeof(arr[0]);
    waveSort(arr,s);
    for(int i : arr)cout<<i<<" ";
    return 0;
}