#include <bits/stdc++.h>


using namespace std;

class LinkedList{
    public:
        LinkedList* next;
        int data;

        LinkedList(){
            next=NULL;
        }

        LinkedList(int data){
            this->data=data;
            this->next=NULL;
        }
};

LinkedList* addNode(LinkedList* node,int data){
    LinkedList* temp=node;
    if(temp==NULL){
        node=new LinkedList(data);
    }else{
        while(temp->next!=NULL)temp=temp->next;
        temp->next=new LinkedList(data);
    }
    return node;
}

void addAtBeginning(LinkedList* &head, int data){
    
    LinkedList* node=head;
    LinkedList* temp=new LinkedList(data);

    if(head == NULL){
        temp->next=temp;
        head=temp;
        return;
    }
    
    while(node->next!=head)node=node->next;

    node->next=temp;
    temp->next= head;

    head=temp;


}

void addAtTail(LinkedList* &head , int data){

    if(head == NULL){
        addAtBeginning(head,data);
        return;
    }

    LinkedList* temp=new LinkedList(data);
    LinkedList* node=head;

    while(head->next!=node)head=head->next;

    head->next=temp;
    temp->next=node;

}


void circularList(LinkedList* &node){

    LinkedList* temp=node;
    while(node->next!=NULL)node=node->next;

     node->next=temp;
}

void print(LinkedList * node){
    LinkedList* head=node;
    do{
        cout<<node->data<<" ";
        node=node->next;
    }while(node !=head);

}

int main(){
    int n;cin>>n;

    LinkedList* root=NULL;

    for(int i=0;i<n;i++){
        int val;cin>>val;
        root=addNode(root,val);
    }

    circularList(root);

    addAtTail(root,3);

    print(root);

    return 0;
}