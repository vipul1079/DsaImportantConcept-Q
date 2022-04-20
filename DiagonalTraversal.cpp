#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented

vector<int> diagonal(Node *root)
{
   vector<int > ans ;
   
   if(root==NULL)return ans;
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       Node* t=q.front();
       q.pop();
       while(t!=NULL){
           ans.push_back(t->data);
           if(t->left)q.push(t->left);
           t=t->right;
       }
   }
       
   
   return ans;
}