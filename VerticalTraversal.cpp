#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented

vector<int> verticalOrder(Node *root)
    {
        map<int , map<int ,vector<int> > > m;
        
        queue<pair<Node* , pair<int , int > > > q;
        vector<int> ans;
        
        if(root==NULL)return ans;
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node* , pair<int , int > > p=q.front();
            q.pop();
            
            Node* node=p.first;
            int deg=p.second.first;
            int lvl=p.second.second;
            
            m[deg][lvl].push_back(node->data);
            
            if(node->left)q.push(make_pair(node->left,make_pair(deg-1,lvl+1)));
            if(node->right)q.push(make_pair(node->right,make_pair(deg+1,lvl+1)));
        }
        
        for(auto i: m){
            for(auto j : i.second){
                
                for(auto k: j.second)ans.push_back(k);
            }
        }
        
        return ans;
    }