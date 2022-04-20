#include <iostream>
using namespace std;
void towerOfHanoi(int n , char src,char dest,char helper){

    if(n == 0){
        return ;
    }
    towerOfHanoi(n-1,src,helper,dest);
    cout<<"from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,helper,dest,src);
}


int main(){

    towerOfHanoi(4,'S','D','H');

    return 0;
}

// S->H
// S->D
// H->D
// S->H
// D->S
// D->H
// S->H
// S->D
// H->D
// H->S
// D->S
// H->D
// S->H
// S->D
// H->D