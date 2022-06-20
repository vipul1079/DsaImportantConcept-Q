#include <bits/stdc++.h>
#include <vector>
using namespace std;


// another way of doing the same problem

int maxW(vector<int> a){
    int water=0;    

    int n=a.size();

    if(n<3)return 0;

    int leftM=a[0];
    int rightM=a[n-1];
    
    int left=1;
    int right=n-2;

    while(left<=right){
        if(leftM <=rightM){
            int w=leftM-a[left];
            if(w>0)water+=w;
            else leftM=a[left];
            left++;
            
        }
        else{
            int w=rightM-a[right];
            if(w>0)water+=w;
            else rightM=a[right];
            right--;
        }
    }


    return water;
}

int maxTrappedwater(vector<int> a){
    int maxwater=0;
    int n=a.size();
    if(n<3)return 0;
    int maxLeft[n];
    int maxRight[n];
    maxLeft[0]=0;
    int m=0;
    for(int i=1;i<n;i++){
        m=max(m,a[i-1]);
        maxLeft[i]=m;

        
    }
    

    maxRight[n-1]=0;
    m=0;
    for(int i=n-2;i>=0;i--){
        
        m=max(m,a[i+1]);
        maxRight[i]=m;
        
    }
    for(int i=0;i<n;i++){
        int blockofwater=min(maxLeft[i],maxRight[i])-a[i];
        maxwater+=(blockofwater>0)? blockofwater:0;
    }
    return maxwater;
}
int main(){
   
    vector<int> a={};
    
    cout<<maxW(a);
    
    return 0;
}