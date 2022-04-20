#include <bits/stdc++.h>

using namespace std;


void utilfindPath(vector<vector<int>> &m, int r,int c,int n,vector<string>& ans,string s){
        
        if(r==n && c==n){
            ans.push_back(s);
            return;
        }
        
        if(r+1<=n && m[r+1][c]==1){
            m[r][c]=0;
            utilfindPath(m,r+1,c,n,ans,s+"D");
            m[r][c]=1;

        }

        if(r-1>=0 && m[r-1][c]==1){
            m[r][c]=0;
            utilfindPath(m,r-1,c,n,ans,s+"U");
            m[r][c]=1;
        }

        if(c+1<=n && m[r][c+1]==1){
            m[r][c]=0;
            utilfindPath(m,r,c+1,n,ans,s+"R");
            m[r][c]=1;
        }
        
        if(c-1>=0 && m[r][c-1]==1){
            m[r][c]=0;
            utilfindPath(m,r,c-1,n,ans,s+"L");
            m[r][c]=1;
        }
        
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string s;
        if(m[n-1][n-1]==0){
            ans.push_back("-1");
            return ans;
        }
        
        utilfindPath(m,0,0,n-1,ans,s);
        
        return ans;
        
    }

int main(){
    vector<vector<int>> m={{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};

    vector<string> ans=findPath(m,4);

    for(auto i=ans.begin();i!=ans.end();i++)cout<<(*i)<<" ";
    return 0;
}