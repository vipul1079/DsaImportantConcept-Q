#include <bits/stdc++.h>
#include <string>
using namespace std;

bool bit1(int a,int pos){

    return ((1<<pos) & a);
}

int main(){
    string s;
    getline(cin,s);
    cout<<s;
    int a;cin>>a;
    int ans=0;
    
    for(int i=0;i<32;i++){
        if(bit1(a,i))ans++;
    }

    cout<<ans;
    
    return 0;
}