#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented


vector <int> bottomView(Node *root) {
        
        map<int , int> m;
        queue<pair<Node* , int> > q;
        vector<int> ans;
        
        if(root==NULL)return ans;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node* , int> temp=q.front();
            q.pop();
            Node* node=temp.first;
            
            int hd=temp.second;
            
            m[hd]=node->data;
            
            if(node->left)q.push(make_pair(node->left,hd-1));
            
            if(node->right)q.push(make_pair(node->right,hd+1));
            
        }
        
        for(auto i : m){
            ans.push_back(i.second);
        }
        return ans;
    }