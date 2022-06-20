#include<bits/stdc++.h>

using namespace std;

bool isSafe(int** board,int r , int c ,int n ){

    for(int row=0;row<r;row++){
        if(board[row][c]==1)return false;
    }

    int row=r;
    int col=c;
    while(row>=0 && col >=0){

        if(board[row][col]== 1)return false;

        row--;
        col--;
    }
    row=r;
    col=c;
    while(row>=0 && col < n){

        if(board[row][col]== 1)return false;

        row--;
        col++;
    }

    return true;

}

bool nQueen(int **board, int x , int n){

    if(x >=n){
        return true;
    }

    for(int col=0;col<n;col++){

        if(isSafe(board,x,col,n)){
            board[x][col]=1;
            if(nQueen(board,x+1,n)){
                return true;
            }
            board[x][col]=0;
        }
        

    }
    return false;

    
}



int main(){
    int n; 
    cin>> n;
    int** arr= new int*[n];

    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++)arr[i][j]=0;
    }


    if(nQueen(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
    };

    
        
    
    return 0;
}