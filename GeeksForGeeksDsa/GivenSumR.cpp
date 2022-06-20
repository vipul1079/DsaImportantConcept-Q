#include <bits/stdc++.h>

using namespace std;

int findM(vector<int> &a,int l , int h){

    if(l>h){return -1;}

    int m=l+(h-l)/2;

    if(m<h && a[m]>a[m+1]){return m;}

    if(l<m && a[m] < a[m-1]){return m-1;}

    if(a[m] < a[l]){return findM(a,l,m-1);}

    return findM(a,m+1,h);
}

bool giveSum(vector<int> &a,int sum){

    int high=findM(a,0,a.size()-1);
    int len=a.size();
    int low=high+1;

    while(low!=high){
        int rsum = a[low]+a[high];

        if(rsum==sum){return true;}

        else if(rsum<sum){
            cout<<"low : "<<low<<" ";
            low++;
            
        }
        else if(rsum>sum){
            cout<<"high: "<<high<<" ";
            high--;
            
        }

        if(low==len)low=0;
        if(high==-1)high=a.size()-1;

    }

    return false;


}

int main(){
    
    vector<int> a={5,6,7,8,1,2,3,4};

    int sum;cin>>sum;
    if(giveSum(a,sum)){
        cout<<"sum is present";

    }else{
        cout<<"sum is not present";
    }
    
    return 0;
}