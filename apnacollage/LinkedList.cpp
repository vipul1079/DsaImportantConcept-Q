#include <iostream>
#include <climits>

#include <string>
#include<bits/stdc++.h>

using namespace std;

class LinkedList{
    public:
        LinkedList *next;
        int val;
    
    LinkedList(){
        next=NULL;
    }

    LinkedList(int val){
        this->val=val;
        next=NULL;
    }
};


void evenafterodd(LinkedList* &root){
    if(root==NULL|| root->next==NULL)return;
    LinkedList * oddptr=root;
    LinkedList* evenptr=root->next;
    LinkedList* evenptrhead=evenptr;
    while(oddptr!=NULL && evenptr!=NULL && evenptr->next !=NULL){
        oddptr->next=evenptr->next;
        oddptr=oddptr->next;
        evenptr->next=oddptr->next;
        evenptr=evenptr->next;
    }
    if(evenptr==NULL){
        oddptr->next=evenptrhead;
    }else{
        oddptr->next=evenptrhead;
        evenptr->next=NULL;
    }
}




LinkedList* SortedLists(LinkedList* root1,LinkedList* root2){

    LinkedList* ptr1=root1;
    LinkedList* ptr2=root2;
    LinkedList* Dummyroot=new LinkedList(0);
    LinkedList* root3=Dummyroot;

    while(ptr1!=NULL && ptr2!= NULL){

        if(ptr1->val<=ptr2->val){
            Dummyroot->next=ptr1;
            ptr1=ptr1->next;
            Dummyroot=Dummyroot->next;
        }else{
            Dummyroot->next=ptr2;
            ptr2=ptr2->next;
            Dummyroot=Dummyroot->next;
        }
        
    }

    while(ptr1!=NULL){
        
        Dummyroot->next=ptr1;
        ptr1=ptr1->next;
        Dummyroot=Dummyroot->next;
    }
    while(ptr2!=NULL){
        Dummyroot->next=ptr2;
        ptr2=ptr2->next;
        Dummyroot=Dummyroot->next;
    }

    return root3->next;

}

LinkedList* makeCycle(LinkedList* node,int pos){

    LinkedList* temp=node;
    LinkedList* cycle_pos;
    int count=1;
    while((temp->next)!=NULL){
        if(count==pos)cycle_pos=temp;
        temp=temp->next;
        count++;
    }
    temp->next=cycle_pos;

    return node;
}

LinkedList* removeCycle(LinkedList* node){
    LinkedList* slowptr=node;
    LinkedList* fastptr=node;

    while(fastptr!=NULL && fastptr->next != NULL){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(fastptr==slowptr){
            fastptr=node;
            break;
        }
    }

    while(fastptr->next != slowptr->next){
        fastptr=fastptr->next;
        slowptr=slowptr->next;
    }
    slowptr->next=NULL;

    return node;
}

bool detectCycle(LinkedList* node){
    LinkedList* slowptr=node;
    LinkedList* fastptr=node;

    while(fastptr != NULL && fastptr->next != NULL){

        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr){
            return true;
        }
    }
    return false;
}

LinkedList* reverseK(LinkedList* node, int k){
    
    LinkedList* prev=NULL;
    LinkedList* nextptr;
    LinkedList* currptr=node;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prev;
        prev=currptr;
        currptr=nextptr;
        count++;
    }

    if(currptr!=NULL){
        node->next=reverseK(nextptr,k);
    }
    return prev;
}

LinkedList* Reverse(LinkedList* root){
    LinkedList* prev=NULL;
    LinkedList* currptr=root;
    LinkedList* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prev;
        prev=currptr;
        currptr=nextptr;
    }
    

    return prev;
}




LinkedList* Delete(LinkedList* root, int val){
    LinkedList* temp=root;

    if(temp == NULL){
        cout<<"list is empty\n";
    }
    else if(temp->val == val){
        root= temp->next;
        free(temp);
    }else{
        while(temp != NULL && (temp->next)->val != val)temp=temp->next;
        if((temp->next)->val == val){
            LinkedList* prev=temp;
            LinkedList* next=temp->next->next;
            prev->next=next;
            free(temp->next);
        }
    }

    return root;
}



LinkedList * middle(LinkedList* node){
    
    if(node== NULL){
        cout<<"no Mid for empty list\n";
        return node;
    }

    LinkedList* slowptr=node;
    LinkedList* fastptr=node;

    

    while((slowptr != NULL) && (fastptr != NULL) && ((fastptr->next) != NULL)){

        slowptr= slowptr->next;
        fastptr=fastptr->next->next;
    }
    return slowptr;

}

LinkedList* addNode(LinkedList * root,int value){
    LinkedList* ptr=root;
    if(root == NULL){
        
        root=new LinkedList(value);
    }
    else{
        
        while(ptr->next!=NULL)ptr=ptr->next;
        ptr->next= new LinkedList(value);
    }
    

    return root;
}

void print(LinkedList * node){

    while(node != NULL){
        cout<<node->val<<" ";
        node=node->next;
    }

}


int main(){
    // cout<<"Enter lengths of two linked lists\n";
    int n;cin>>n;
    // int d;cin>>d;
    LinkedList * root=NULL;
    // LinkedList * root2=NULL;

    // cout<<"enter values for first list\n";
    for(int i=0;i<n;i++){
        int val;cin>>val;
        root=addNode(root,val);
     }
    // cout<<"enter values for second list\n";
    // for(int i=0;i<d;i++){
    //     int val;cin>>val;
    //     root2=addNode(root2,val);
    // }
    
    print(root);

    cout<<"\n";

    // print(root2);

    // LinkedList* mid1=middle(root);
    // LinkedList* mid2=middle(root2);

    // cout<<"\n";

    // if(mid1!=NULL)cout<<"Middle : "<<mid1->val<<"\n";
    // if(mid2!=NULL)cout<<"Middle : "<<mid2->val<<"\n";

    // root=Reverse(root);
    // cout<<"enter the value you want to delete \n";
    // int del_val;cin>>del_val;
    // root=Delete(root,del_val);
    // cout<<"enter the value of k to reverse last k nodes\n";
    // int k;cin>>k;
    // root=reverseK(root,k);
    // cout<<"Enter the position at which a cycle should me made\n";
    // int cyclic;cin>>cyclic;
    // root=makeCycle(root,cyclic);
    
    // if(detectCycle(root)){
    //     root=removeCycle(root);
    //     cout<<"Cycle removed\n";
    //     print(root);
    // }else{
    //     cout<<"No cycle detected\n";
    // }

    // cout<<"\n";

    // LinkedList* root3=SortedLists(root,root2);

    // print(root3);


    evenafterodd(root);

    print(root);





    

    

    return 0;
}