#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented



Node* solve(Node* root, int k , int node,int & c){
    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }
    //left
    Node* l = solve(root->left,k,node,c);
    //right
    Node* r = solve(root->right,k,node,c);
    
    if(l){

        c++;
        if(c==k)return root;
        return l;
    }else if(r){
        c++;
        
        if(c==k)return root;
        return r;
    }
    return NULL;
    
    
}

int kthAncestor(Node *root, int k, int node)
{
    int c=0;
    Node* ans=solve(root,k,node,c);
    if(ans->data!=node)return ans->data; 
    
    return -1;
}