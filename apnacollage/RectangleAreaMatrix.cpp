#include <iostream>
#include <climits>

#include <string>
#include<bits/stdc++.h>

using namespace std;

int largestArea(vector<int> a){
    
    int largest=0;
    int n=a.size();
    stack<int> st;
    int leftM[n];
    int rightM[n];
    int left=0;
    int right=n-1;

    while(left<n){

        while(!st.empty() && a[st.top()]>a[left]){
            st.pop();
        }
        if(st.empty()){
            leftM[left]=0;
        }else{
            leftM[left]=st.top()+1;
        }
        st.push(left);
        left++;
    }

    while(!st.empty())st.pop();

    while(right>=0){

        while(!st.empty() && a[st.top()]>a[right]){
            st.pop();
        }
        if(st.empty()){
            rightM[right]=n-1;
        }else{
            rightM[right]=st.top()-1;
        }
        st.push(right);
        right--;
    }

    for(int i=0;i<n;i++){
        int max1=a[i]* (rightM[i]-leftM[i]+1);
        largest=max(max1,largest);
    }

    return largest;
}


int largestRect1(vector<vector<int>> dp){

    int m=0;

    int c=dp[0].size();
    int r=dp.size()-1;
    

    vector<int> histogram(c,0);

    for(int i=1;i<=r;i++){
        for(int j=0;j<c;j++){
            if(dp[i][j]==1){
                dp[i][j]=dp[i-1][j]+1;
                histogram[j]=dp[i][j];
            }else{
                histogram[j]=0;
            }
        }
        

        int large=largestArea(histogram);

       
        m=max(m,large);
    }
    return m;
}


int main(){
    int r,c;cin>>r;cin>>c;
    vector<vector<int>> a(r,vector<int>(c));
    for(int i = 0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];

        }
    }

    vector<vector<int>> pass(r+1,vector<int>(c));

    for(int i = 0;i<r;i++){
        for(int j=0;j<c;j++){
            pass[i+1][j]=a[i][j];
        }
    }

    cout<<largestRect1(pass);
    
}