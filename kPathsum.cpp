#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented

void solve(Node *root , int & count , int k , vector<int> a ){
        if(root){
            a.push_back(root->data);
            solve(root->left,count,k,a);
            solve(root->right,count,k,a);
            
            int sum =0;
            for(int i=a.size()-1;i>=0;i--){
                sum+=a[i];
                if(sum==k){
                    count++;
                }
            }
            
            a.pop_back();
        }
    }
    int sumK(Node *root,int k)
    {
        vector<int> a;
        int count=0;
        solve(root,count,k,a);
        return count;
    }