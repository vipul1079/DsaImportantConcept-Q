#include <bits/stdc++.h>

using namespace std;

string lcs(string s){

    vector<int> arr(26,-1);
    int n = s.length();
    int start=-1;
    int maxlen=0;

    for(int i=0;i<n;i++){
        
        if(arr[s[i]-'a'] > start){
            start=arr[s[i]-'a'];
        }
        arr[s[i]-'a']=i;
        maxlen=max(maxlen,i-start);
    }

    return s.substr(start+1,maxlen+1);
}




int main(){

    string s;cin>>s;

    cout<<lcs(s);

    return 0;
}


































// string lcs(string s){
//     vector<int> arr(26,-1);
//     int n =s.length();
//     int maxlen=0;
//     int start=-1;

//     for(int i=0;i<n;i++){

//         if(arr[s[i]-'a'] > start)start=arr[s[i]-'a'];

//         arr[s[i]-'a']=i;

//         maxlen=max(maxlen,i-start);
//     }

//     return s.substr(start+1,maxlen+1);

// }

