#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented


map<int,int> createMapping(int in[],int n){
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[in[i]]= i;
        }
        return m;
    }
    
    Node* solve(int in[], int post[],
    map<int,int>&m,int &idx , int startIn , int endIn,int n){
        //base case
        if(idx<0||  startIn>endIn)return NULL;
        
        int element=post[idx--];
        Node* node= new Node(element);
        int pos=m[element];
        
        //recursive Calls
        node->right=solve(in,post,m,idx,pos+1,endIn,n);
        node->left=solve(in,post,m,idx,startIn,pos-1,n);
        
        
        return node;
    }
Node *buildTree(int in[], int post[], int n) {
    
    map<int ,int> m=createMapping(in,n);
    int idx=n-1;
    
    Node* root=solve(in,post,m,idx,0,n-1,n);
    return root;
}