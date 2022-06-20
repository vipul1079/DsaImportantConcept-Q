#include <iostream>
#include <climits>

#include <string>
#include<bits/stdc++.h>

using namespace std;


long long Combine(int* arr,int low , int mid , int high){

    long long inv=0;
    int n1= mid-low +1;
    int n2 = high - mid;

    int a[n1]={0};
    int b[n2]={0};

    for(int i=0;i<n1;i++)a[i]=arr[low+i];
    for(int i=0;i<n2;i++)b[i]=arr[mid+i+1];

    int i=0;int j=0;int k=low;

    while(i<n1 && j< n2 ){
        if(a[i]<=a[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            inv+=n1-i;
            j++;
            k++;
        }
    }

    while(i<n1){
        arr[k]=a[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;k++;
    }

    return inv;

}

long long mergeSort(int * arr , int low , int high){
    long long inv=0;
    if(low< high){
        int mid=(low+high)/2;
        inv+=mergeSort(arr,low,mid);
        inv+=mergeSort(arr,mid+1,high);
        inv+=Combine(arr,low,mid,high);
    }
    return inv;
}



int main(){

    int n;cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<mergeSort(arr,0,n-1);

    return 0;
}