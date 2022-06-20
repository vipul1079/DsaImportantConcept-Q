#include <iostream>
#include <climits>

#include <string>
#include<bits/stdc++.h>

using namespace std;





bool isValid(int ** arr, int r ,int c , int n){

    if(arr[r][c]==1 && r<n && c < n ){
        return true;
    }
    return false;
}

bool backtrack(int ** arr, int r , int c , int n , int ** ans){

    if(r==(n-1) && c==(n-1)){
        ans[r][c]=1;
        return true;
    }

    if(isValid(arr,r,c,n)){
        ans[r][c]=1;
        if( backtrack(arr,r,c+1,n,ans)){
            return true;
        }
        if(backtrack(arr,r+1,c,n,ans)){
            return true;
        }
        ans[r][c]=0; //backtracking
        return false;
    }
    return false;
    
}







int main(){
    int n;
    cin>>n;
    int ** arr= new int*[n];

    for(int i =0;i<n;i++){
        arr[i]=new int[n];
    }
    int ** ans= new int*[n];

    for(int i =0;i<n;i++){
        ans[i]=new int[n];
        for(int j = 0;j<n;j++){
            ans[i][j]=0;
        }
    }

    cout<<"Enter the values of the 2-d maze \n1 for the valid block \n0 for invalid block"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }


    if(backtrack(arr,0,0,n,ans)){
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

    }
   
    
    
    return 0;
}






// void permutations(string s,string ans){
//     if(s.length()==0){
//         cout<<ans<<endl;
//         return;
//     }

//     for(int i=0;i<s.length();i++){
//         char ch=s[i];

//         string rest=s.substr(0,i)+s.substr(i+1);
//         permutations(rest,ch+ans);
//     }

// }
