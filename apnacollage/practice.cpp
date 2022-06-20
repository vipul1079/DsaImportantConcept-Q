#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
        int data;
        Node* left;
        Node* right;
        
        

        //Constructor
        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

void levelOrder(Node* root){
        
    queue<Node*> q;
    if(root!=NULL)q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty())q.push(NULL);
        }else{
            cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        
    }
}

Node* InsertNode(Node* root , int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data)root->right=InsertNode(root->right,data);
    else root->left=InsertNode(root->left,data);
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=InsertNode(root,data);
        cin>>data;
    }
}

Node* FindMin(Node* root){
    if(root){
        while(root->left)root=root->left;
    }
    return root;
}

Node* Delete(Node* root, int data){
    if(root==NULL){
        return root;
    }

    if(root->data<data)root->right=Delete(root->right,data);
    else if (root->data > data) root->left = Delete(root->left,data);
    else{
        if(!(root->left && root->right)){
            delete root;
            root=NULL;
        }
        else if(!(root->right)){
            Node* temp=root;
            root=root->left;
            delete temp;
        }
        else if(!(root->left)){
            Node* temp=root;
            root=root->right;
            delete temp;
        }else{
            Node* max=FindMin(root->right);
            root->data=max->data;
            root->right=Delete(root->right,root->data);
        }
        
    }
    return root;
}
  

Node* lca(Node* root , int n1 , int n2){
    if(root==NULL || root->data == n1 || root->data == n2 )return root;

    Node* l= lca(root->left,n1,n2);
    Node* r= lca(root->right,n1,n2);

    if(l&&r)return root;
    else if(l)return l;
    else if(r)return r;
    return NULL;
}
//Inorder traversal of the tree we should get values in ascesding order
vector<int> MorrisTraversal(Node* root){
    vector<int>v;
    if(!root)return v;

    Node* curr=root;
    while(curr){
        if(!curr->left){
            
            v.push_back(curr->data);
            curr=curr->right;
        }else{
            Node* pred=curr->left;
            while(pred->right && pred->right!=curr)pred=pred->right;
            if(pred->right){
                v.push_back(curr->data);
                curr=curr->right;
                pred->right=NULL;
            }else{
                pred->right=curr;
                curr=curr->left;
            }
        }
    }
    return v;

}


int main(){
    Node* root=NULL;
    takeInput(root);
    

    vector<int> v=MorrisTraversal(root);

    for(auto i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }
    return 0;
}