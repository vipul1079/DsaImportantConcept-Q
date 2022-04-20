#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented

vector<int> rightView(Node *root)
    {
        vector<int> ans;
        if(root==NULL)return ans;
        map<int, int > m;
        queue<pair<Node* , int> > q;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node* , int> temp=q.front();
            q.pop();
            
            Node* node=temp.first;
            int lvl=temp.second;
            
            if(m.find(lvl)==m.end())m[lvl]=node->data;
            if(node->right)q.push(make_pair(node->right,lvl+1));
            if(node->left)q.push(make_pair(node->left,lvl+1));
            
        }
        
        for(auto i: m){
            ans.push_back(i.second);
        }
        return ans;
        
    }