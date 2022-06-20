#include <bits/stdc++.h>

#include <stack>
using namespace std;

void insertAtBottom(stack<int>&stack,int val){

    if(stack.empty()){
        stack.push(val);
        return;
    }

    int topval=stack.top();
    stack.pop();
    insertAtBottom(stack,val);
    stack.push(topval);
}

void reverseS(stack<int> &stack){
    
    if(stack.empty()){
        
        return;
    }
    int topelement=stack.top();
    stack.pop();
    
        
    reverseS(stack);
    
        
    insertAtBottom(stack,topelement);

}

int main(){

    stack<int> stack;

    int n;cin>>n;

    for(int i=0;i<n;i++){
        int val;cin>>val;
        stack.push(val);
    }
    cout<<"\n";
    reverseS(stack);

    for(int i=0;i<n;i++){
        cout<<stack.top()<<"\n";
        stack.pop();
        
    }


    return 0;
}