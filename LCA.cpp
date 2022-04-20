#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented

Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL || root->data == n1 || root->data==n2)return root;
       
       Node* l=lca(root->left,n1,n2);
       Node* r=lca(root->right,n1,n2);
       if(l&&r)return root;
       else if(l)return l;
       else if(r)return r;
       return NULL;
       
    }