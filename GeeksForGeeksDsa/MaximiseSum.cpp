#include <bits/stdc++.h>

using namespace std;

int findM(vector<int>&a, int l  ,int h){

    if(l>h){return -1;}

    int m=l+h/2;

    if(m<h && a[m] > a[m+1]){return m;}
    if(l<m && a[m] < a[m-1]){return m-1;}

    if(a[l] > a[m])return findM(a,l,m-1);
    return findM(a,m+1,h);
}

void reverse(vector<int>& arr, int start,int end){
    while(start<end){  
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;end--;
    }
}


int maximizeSum(vector<int> & a, int k){
    int size=a.size();
    reverse(a,0,k);
    reverse(a,k+1,size-1);
    reverse(a,0,size-1);
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=(i*a[i]);
    }
    return sum;
}


int main(){
    vector<int> a={1,20,2,10};
    int k=findM(a,0,a.size()-1);

    cout<<"maxsum of the above arr is : "<<maximizeSum(a,k);

    



    return 0;
}