#include <bits/stdc++.h>
#include <stack>
using namespace std;

// Stack using queue
class stac{
    int N;
    queue<int> q1;
    queue<int> q2;

    

    public:
        stac(){
        N=0;
        }
        void remove(){
            q1.pop();
            N--;
        }

        void add(int val){
            q2.push(val);
            N++;
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }

            queue<int> temp;
            temp=q2;
            q2=q1;
            q1=temp;

        }

        void print(){
            while(!q1.empty()){
                cout<<q1.front()<<" ";
                q1.pop();
            }
        }

        int top(){
            return q1.front();
        }

        int size(){
            return N;
        }
};

// queue using stack and memory stack
// class que{
//     stack<int> s1;
//     public:
//         void enQueue(int val){
//             s1.push(val);
//         }
//         int pop(){

//             if(s1.empty()){
//                 cout<<"Error queue is empty\n";
//                 return -1;
//             }
//             int top=s1.top();
//             s1.pop();
//             if(s1.empty()){
//                 return top;
//             }

//             int topelem = pop();
//             s1.push(top);
//             return topelem; 
//         }


//         void print(){
//             while(!s1.empty()){
//                 cout<<s1.top()<<" ";
//                 s1.pop();
//             }
            
//         }

// };


int main(){

    
    stac s;

    s.add(1);
    s.add(2);
    s.add(3);
    s.add(4);

    s.remove();
    s.remove();
    

    s.print();


    
    return 0;
}