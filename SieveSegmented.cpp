#include <bits/stdc++.h>

using namespace std;
#define MAX 1001

vector<int>* sieve(){

    int isPrime[MAX];

    for(int i=0;i<MAX;i++)isPrime[i]=true;
    
    isPrime[0]=isPrime[1]=false;

    for(int i=2;i*i<MAX;i++){

        if(isPrime[i]){
            for(int j=2*i;j<=MAX;j+=i){
                isPrime[j]=false;
            }
        }
    }

    vector<int>* Prime=new vector<int>;

    for(int i=2;i<=MAX;i++){
        if(isPrime[i]){
            Prime->push_back(i);
            
        }
    }
    

    return Prime;
}


void segmentedSieve(long long l , long long r,vector<int>* &Prime ){

    bool isPrime[r-l+1];
    
    for(int i=0;i<r-l+1;i++){
        isPrime[i]=true;
    }
    
    isPrime[0]=false;
    for(int i=0;Prime->at(i)*(long long )Prime->at(i)<=r;i++){
        int currPrime=Prime->at(i);
        
        int base=((l/currPrime)*currPrime);
        
        if(base<l)base+=currPrime;

        
        for(long long j=base;j<=r;j+=currPrime){
            isPrime[j-l]=false;
        }

        if(base==currPrime)isPrime[base-l]=true;
        
    }

    for(int i=0;i<r-l+1;i++){
        if(isPrime[i]){
            cout<<i+l<<" ";
        }
    }
    cout<<"\n";
    

}



int main(){
    vector<int>* Prime=sieve();
    

    

    int t;cin>>t;

    while(t--){
        long long l,r;
        cin>>l>>r;
        
        segmentedSieve(l,r,Prime);

        
    }
    

}