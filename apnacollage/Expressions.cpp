#include <bits/stdc++.h>
#include <stack>
using namespace std;

int postfixSolve(string s){
    stack<int> stack;

    for(int i=0;i<s.length();i++){

        if(s[i]<='9' && s[i]>='0'){
            stack.push(s[i]-'0');
        }
        else{
            int opr2=stack.top();
            stack.pop();
            int opr1=stack.top();
            stack.pop();
            switch(s[i]){
                case '+':
                    stack.push(opr1+opr2);
                    break;
                case '-':
                    stack.push(opr1-opr2);
                    break;
                case '*':
                    stack.push(opr1*opr2);
                    break;
                case '/':
                    stack.push(opr1/opr2);
                    break;
                case '^':
                    stack.push(opr1^opr2);
                    break;
                    
            }
        }
    }
    int ans=stack.top();
    stack.pop();
    return ans;}


int prec(char ch){

    if(ch == '^'){
        return 3;
    }else if(ch== '*' || ch == '/'){
        return 2;
    }else if( ch== '+' || ch== '-'){
        return 1;
    }else{
        return -1;
    }
}

string reverse(string s){
    int i=0;
    int j = s.length()-1;

    while(i<j){
        if(s[i]=='(')s[i]=')';
        else if(s[i]==')')s[i]='(';

        if(s[j]=='(')s[j]=')';
        else if(s[j]==')')s[j]='(';
        char ch= s[i];
        s[i]=s[j];
        s[j]=ch;

        i++;j--;
    }

    return s;
}


string infixToprefix(string s){
    string res;
    stack<char> st;

    s=reverse(s);

    for(int i=0;i<s.length();i++){

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]== ')'){
            while(!st.empty() && st.top() !='('){
                res+=st.top();
                st.pop();
            }
            
            if(!st.empty()){
                st.pop();
            }
        }
        else {
            while(!st.empty() && prec(s[i])<prec(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    
    res=reverse(res);

    return res;

}

string infixTopostfix(string s){
    string res;

    stack<char> st;

    for(int i=0;i<s.length();i++){

        if(s[i]=='('){
            st.push(s[i]);
        }
        else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]==')'){

            while(st.top() !='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }else {
            while(!st.empty() && prec(s[i])<prec(st.top())){
                res+=st.top();
                st.pop();
            }

            st.push(s[i]);
            
        }
    }

    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    return res;

}


int main(){

   string s="(a-b/c)*(a/k-l)";

   

   cout<<infixToprefix(s);
   

    
    return 0;
}