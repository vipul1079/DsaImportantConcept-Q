#include<bits/stdc++.h>

using namespace std;

//Dirvers code has to be implemented

void leftTraverse(Node* root, vector<int> & ans){
        if(root){
            if(root->left){
                ans.push_back(root->data);
                leftTraverse(root->left,ans);
            }
            else if(root->right){
                ans.push_back(root->data);
                leftTraverse(root->right,ans);
            }
        }
    }
    
    void allLeafNodes(Node* root , vector<int>& ans){
        if(root){
            if(root->left==NULL && root->right==NULL){
                ans.push_back(root->data);
            }
            allLeafNodes(root->left,ans);
            allLeafNodes(root->right,ans);
        }
    }
    void rightTraverse(Node* root,vector<int>& ans){
        if(root){
            if(root->right){
                rightTraverse(root->right,ans);
                ans.push_back(root->data);
            }
            else if(root->left){
                rightTraverse(root->left,ans);
                ans.push_back(root->data);
            }
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        leftTraverse(root->left,ans);
        if(root->left || root->right){
            allLeafNodes(root,ans);
        }
        rightTraverse(root->right,ans);
        return ans;
    }