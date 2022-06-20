#include <bits/stdc++.h>

#include <stack>
using namespace std;

bool balancedParanthesis(string s){

    stack<char> st;

    for(int i=0;i<s.length();i++){
        if(s[i]=='{'){
            st.push('}');
        }else if(s[i]=='['){
            st.push(']');
        }else if(s[i]=='('){
            st.push(')');
        }else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if(s[i]==st.top()){
                st.pop();
            }else {
                return false;
            }
        }else{
            continue;
        }
    }
    if(st.empty()){
        return true;
    }else{
        return false;
    }
    
}

int main(){
    
    cout<<balancedParanthesis(s);
    return 0;
}