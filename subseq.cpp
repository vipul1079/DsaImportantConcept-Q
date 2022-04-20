#include<bits/stdc++.h>

using namespace std;

void utilSub(string str,vector<string>& ans,int idx,string out){
    if(idx>=str.length() ){
        ans.push_back(out);
        return;
    }
    
    utilSub(str,ans,idx+1,out);
    utilSub(str,ans,idx+1,out+str[idx]);
}

vector<string> subsequences(string str){
    
	vector<string> ans;
    int idx=0;
    utilSub(str,ans,idx,"");
    return ans;
	
}

int main(){

    vector<string> s=subsequences("abc");

    for(auto i= s.begin();i!=s.end();i++)cout<<(*i)<<" ";

    return 0;
}