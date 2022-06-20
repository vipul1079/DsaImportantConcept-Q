#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>

#include <vector>

using namespace std;


int getBit(int n,int pos){
    return ((n & 1<<pos) != 0)? 1: 0;
}

int setBit(int n,int pos){
    return ((n | 1<<pos));
}

void noof1Bits(int n,int* ans){

    while(n !=0){
        n= (n & (n-1));
        (*ans)++;
    }
}

int main(){
    int n;
    int ans=0;
    cin>>n;
    noof1Bits(n,&ans);
    cout<<ans;

   
}