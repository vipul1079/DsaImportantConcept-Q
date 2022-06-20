#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;


void DNF(int * arr,int s, int l, int m,int h){

    while(h>=m){
        if(arr[m]==0){
            swap(arr[m],arr[l]);
            m++;
            l++;
        }
        else if(arr[m]==1){
             m++;
        }
        else{
           
            swap(arr[m],arr[h]);
            h--;
        }
    }
}


int main(){

    int arr[]= {0,2,2,1,1,0,1,0,2,2,2};
    int s=sizeof(arr)/sizeof(arr[0]);
    DNF(arr,s,0,0,(s-1));

    for(auto i:arr){
        cout<<i<<" ";
    }
   
}