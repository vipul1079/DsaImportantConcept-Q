#include <bits/stdc++.h>

using namespace std;

int longestSubs(string s){
    vector<int> arr(256,-1);
    int maxlen=0;
    int n=s.length();
    int start=-1;
   
    for(int i=0;i<n;i++){

        if(arr[s[i]] > start){
            start=arr[s[i]];
        }
        arr[s[i]]=i;
        maxlen=max(maxlen,i-start);
    }

    return maxlen;

}

int main(){

 
    cout<<longestSubs("abaa");
    
    return 0;
}