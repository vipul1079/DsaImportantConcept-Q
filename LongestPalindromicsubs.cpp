#include <bits/stdc++.h>
using namespace std;
string lps(string s){
    int n=s.length();
    // dp table
    int table[n][n];

    memset(table,0,sizeof(table));

    int maxlen=1;
    // string of size 1 is palindrome 
    for(int i = 0 ;i<n;i++)
        table[i][i]=1;
    
    int start=0;
    //string of size 2
    for(int i=0;i<(n-1);i++){
        if(s[i]==s[i+1]){
            start=i;
            maxlen=2;
        }
    }

    //for all strings above size 2
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i+k-1;

            //check if it is palindrome
            if(table[i+1][j-1] && s[i]==s[j]){
                table[i][j]=1;
                start=i;
                maxlen = k;
            }
        }
    }

    return s.substr(start,start+maxlen-1);

}


int main(){
    cout<<lps("");
    return 0;
}