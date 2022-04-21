#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented




int findPos(int in[], int e,int n){
        for(int i=0;i<n;i++){
            if(in[i]==e)return i;
        }
        return -1;
    }
    Node* solve(int in[], int pre[], int &idx , int startIn , int endIn,int n){
        //base case
        if(idx>=n || startIn>endIn)return NULL;
        
        int element=pre[idx++];
        Node* node= new Node(element);
        int pos=findPos(in,element,n);
        
        //recursive Calls
        node->left=solve(in,pre,idx,startIn,pos-1,n);
        node->right=solve(in,pre,idx,pos+1,endIn,n);
        
        return node;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int idx=0;
        Node* root = solve(in , pre , idx, 0,n-1,n);
        return root;
    }