#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented

pair<int, int > solve(Node* root, pair<int, int > a){
        if(root==NULL)return make_pair(0,0);
        
        pair<int , int> l=solve(root->left,a);
        pair<int, int > r=solve(root->right,a);
        
        int lmax=max(l.first,l.second);
        int rmax=max(r.first,r.second);
        
        return make_pair(root->data+l.second+r.second,lmax+rmax);
    }
    
    int getMaxSum(Node *root) 
    {
        pair<int ,int> a;
        pair<int , int> p=solve(root,a);
        return max(p.first,p.second);
    }