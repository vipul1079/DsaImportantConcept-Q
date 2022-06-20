#include <bits/stdc++.h>

using namespace std;

struct node {
    struct node * left;
    struct node * right;
    int data;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


void inorder(struct node* root){

    if(root !=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}



int height(struct node* root){

    if(root== NULL)return -1;

    int lheight=height(root->left);
    int rheight=height(root->right);

    return max(lheight,rheight)+1;

}

int calcheight(struct node* root){
    if(root==NULL)return 0;
    return max(calcheight(root->left),calcheight(root->right))+1;
}


int diameter(struct node* root){

    if(root==NULL){
        return 0;
    }
    int lheight=calcheight(root->left);
    int rheight=calcheight(root->right);
    int currDiameter=lheight+rheight+1;
    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);

    return max(currDiameter,max(ldiameter,rdiameter));
}


int diameteropt(struct node* root,int* height){

    if(root==NULL){
        *height=0;
        return 0;
    }

    int lh=0,rh=0;
    
    int ldiameter=diameteropt(root->left,&lh);
    int rdiameter=diameteropt(root->right,&rh);

    *height=max(lh,rh)+1;

    return max(lh+rh+1,max(ldiameter,rdiameter));
}

int levelordersum(struct node* root,int k){
    queue<struct node*> q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    int level=0;
    if(level==0)cout<<"level "<<level<<endl;
    while(!q.empty()){
        struct node* val=q.front();
        q.pop();

        
        if(val !=NULL){
            cout<<val->data;
            if(level==k)
                sum+=val->data;
            if(val->left !=NULL)q.push(val->left);
            if(val->right != NULL)q.push(val->right);
            
        }else if(!q.empty()){
            cout<<"\n";
            level++;
            q.push(NULL);
            cout<<"level "<<level<<endl;
            
        }
    }

    cout<<"\n";
    return sum;
    
}




int main(){

    struct node* root=new node(6);

    root->left=new node(3);
    root->right=new node(8);
    root->left->left=new node(2);
    root->left->right=new node(5);

    root->right->left=new node(7);
    root->right->right=new node(10);
    


    cout<<levelordersum(root,2)<<endl;
    int height=0;
    
    cout<<diameteropt(root,&height);
    





    
    return 0;
}