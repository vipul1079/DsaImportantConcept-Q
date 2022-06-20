#include <bits/stdc++.h>
#include <climits>
using namespace std;
// max area rectangle problem 
int MaxArea(vector<int> &a,int n){
    stack<int> s;

    int right[n];
    int left[n];
    int ans=0;


    for(int i=0;i<n;i++){

        while(!s.empty() && a[s.top()] > a[i]){
            s.pop();
        }
        if(s.empty()){
            left[i]=0;
        }else{
            left[i]=s.top()+1;
        }
        s.push(i);
    }
    // 0 1

    while(!s.empty())s.pop();

    for(int i=n-1;i>=0;i--){

        while(!s.empty() && a[s.top()] > a[i]){
            s.pop();
        }
        if(s.empty()){
            right[i]=n-1;
        }else{
            right[i]=s.top()-1;
        }

        s.push(i);
    }

    // 4 4

    for(int i=0;i<n;i++){
        int area=a[i]*(right[i]-left[i]+1);

        ans=max(ans,area);
    }


    
    return ans;
}
 
int main(){
    vector<int> arr={2,4};
    cout<<MaxArea(arr,2);
    return 0;
}