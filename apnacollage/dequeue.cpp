#include <bits/stdc++.h>

#include <vector>
#include <deque>

using namespace std;



int main(){
    int n;cin>>n;
    int k;
    vector<int> a(n);
    vector<int> ans;

    for(auto &i: a)cin>>i;

    cin>>k;
    deque<int> dq;
    

    for(int i=0;i<k;i++){
        while(!dq.empty() && a[dq.back()] < a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]);

    for(int i=k;i<n;i++){
        if(dq.front() == (i-k)){
            dq.pop_front();
        }

        while(!dq.empty() && a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }
    for(auto i:ans){
        cout<<i<<" ";
    }







    return 0;
}