#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void Partition(int * , int , int , int);

void MergeSort(int* a,int low,int high){

    if(low<high){
        int mid= low+((high-low)/2);
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Partition(a,low,mid,high);
    }
}

void Partition(int* arr , int low , int mid , int high ){

    int n1=mid-low+1;
    int n2=high-mid;
    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[low+i];
    }
    for(int j=0;j<n2;j++){
        b[j]=arr[mid+j+1];
    }
    

    int k= low;
    int i=0;
    int j = 0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }else{
            arr[k]=b[j];
            j++;k++;
        }
        
    }
     while(i<n1){
            arr[k]=a[i];
            i++;
            k++;
        }

        while(j<n2){
            arr[k]=b[j];
            j++;
            k++;
        }
}

int main(){
    int n;cin>>n;
    int* arr= new int[n];
    for(int i= 0; i< n;i++){
        cin>>arr[i];
    }
    

    MergeSort(arr,0,n-1);

     for(int i= 0; i< n;i++){
        cout<<arr[i]<<" ";
    }
    
   
    
    
    
}


// void helper(vector<int> arr,vector<vector<int>> &ans,int idx){
//      if(idx==arr.size()){
//         ans.push_back(arr);
//         return;
//     }

//     for(int i=idx;i<arr.size();i++){
//         if(i != idx && arr[i] == arr[idx])continue;

//         swap(arr[i],arr[idx]);
//         helper(arr,ans,idx+1);
//     }
// }


// vector<vector<int>> permute(vector<int> & arr, int idx){
//     vector<vector<int>> ans;

//     helper(arr,ans,idx);

//     return ans;

   
// }




// vector<vector<int>> ans;

// void permute(vector<int> &arr,int idx ){

//     if(idx==arr.size()){
//         ans.push_back(arr);
//         return;
//     }

//     for(int i=idx;i<arr.size();i++){
//         swap(arr[i],arr[idx]);
//         permute(arr,idx+1);
        
//     }
//     return;
// }