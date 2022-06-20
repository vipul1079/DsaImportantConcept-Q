#include <bits/stdc++.h>

using namespace std;

void fib(int n, int arr[]){
	
	for(int i=2;i<n+1;i++){
		
		arr[i]=arr[i-1]+arr[i-2];

		}
	
	


}
int main(){
	int n;cin>>n;
	
	int arr[n+1]={0};
	
	arr[1]=1;

    fib(n,arr);

    for(int i=0;i<n+1;i++){
        cout<<arr[i]<<" ";
    }
	
	return 0;
	}