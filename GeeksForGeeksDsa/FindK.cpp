#include <bits/stdc++.h>

using namespace std;


int BinarySearch(vector<int> &a,int l, int h,int k){

    if(l>h){return -1;}

    int m=l+(h-l)/2;

    if(a[m]==k){return m;}

    else if(a[m]>k){return BinarySearch(a,l,m-1,k);}

    return BinarySearch(a,m+1,h,k);

}

int FindM(vector<int> &a,int l,int h){
    
    if(l>h)return -1;

    if(l==h)return l;
    
    int M=l+((h-l)/2);

    if(M<h && a[M]>a[M+1])return M;

    if(l<M && a[M]<a[M-1])return M-1;

    if(a[M]<a[l])return FindM(a,l,M-1);

    return FindM(a,M+1,h);
}

int FindK(vector<int> &a,int k,int n){

    int M=FindM(a,0,n-1);
    int a1=BinarySearch(a,0,M,k);
    int K=(a1==-1)?BinarySearch(a,M+1,n-1,k):a1;
    return K;


}

int main(){

    vector<int> a={5,6,7,8,1,2,3,4};
    int k;cin>>k;
    cout<<"Index of "<<k<<" is "<<FindK(a,k,a.size());
    
    return 0;
}