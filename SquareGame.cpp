#include <bits/stdc++.h>

using namespace std;


bool isValid(int** arr,int r ,int c,int n){
    if(arr[r][c]==1 && r<n && c < n && r>=0 && c>=0)return true;
    return false;
}

bool backtrack(int** arr,int r,int c,int n,int** ans){
    if(r==(n-1) && c==(n-1) &&  arr[r][c]==1){
        ans[r][c]=1;
        
        return true ;
    }

    if(r>n || c >n)return false;

    if(isValid(arr,r,c,n)){

        if(ans[r][c]==1)return false;
        
        ans[r][c]=1;

        if(backtrack(arr,r,c+1,n,ans)){
            return true;
        }
        
        if(backtrack(arr,r+1,c,n,ans)){
            
            return true;
        }

       
      
        ans[r][c]=0;


        return false;
        

    }
    
    return false;
}

int main(){

    int n;cin>>n;

    int **arr = new int*[n];
    int **ans=new int*[n];


    cout<<"Enter the values of the 2-d maze \n1 for the valid block \n0 for invalid block"<<endl;

    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        ans[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            ans[i][j]=0;
        }
    }

    if(backtrack(arr,0,0,n,ans)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<"no valid output";
    }

    return 0;
}






































// bool isValid(int ** arr,int r,int c, int n){

//     if(arr[r][c]==1 && r<n && c<n){
//         return true;
//     }
//     return false;

// }

// bool backTrack(int** arr, int r, int c, int n, int** ans){

//     //base case 
//     if(r==(n-1) && c==(n-1)){
//         ans[r][c]=1;
//         return true;
//     }

//     if(isValid(arr,r,c,n)){
//         ans[r][c]=1;

//         if(backTrack(arr,r,c+1,n,ans)){
//             return true;
//         }
//         if(backTrack(arr,r+1,c,n,ans)){
//             return true;
//         }
//         ans[r][c]=0;
//         return false;
//     }

//     return false;
// }


