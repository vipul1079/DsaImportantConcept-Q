#include <bits/stdc++.h>

using namespace std;

int max1(vector<int> a,int k){
    int n=a.size();

    int zerocnt=0;
    int max1=0;

    int i=0;
    int j=0;

    while(j<n){

        if(a[j]==0)zerocnt++;

        while(zerocnt>k){
            if(a[i]==0)zerocnt--;
            i++;
        }
        max1=max(max1,j-i+1);

        j++;

        
    }

    
    

    return max1;
}

int main(){

    int n;cin>>n;
    int k;cin>>k;

    vector<int> a(n);

    for(auto &i:a)cin>>i;

    cout<<max1(a,k);





    return 0;
    
    
}