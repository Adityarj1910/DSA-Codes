#include<iostream>
//mem - <MEMOIZATION
using namespace std;

int m[10];
// int fib_rec(int n){
//     if(n==0){
//         return 0;
//     }
        
//     else if(n==1){
//         return 1;
//     }
//     else
//         return fib_rec(n-1)+fib_rec(n-2);
// }

int fib_rec_mem(int n){
    
    if(n<=1){
        m[n]=n;
        return n;
    }

    else{
        if(m[n-1]== -1){

            m[n-1]=fib_rec_mem(n-1);
        }
        if(m[n-2]== -1){

            m[n-2]=fib_rec_mem(n-2);
        }

        return m[n-1]+m[n-2];
    }
    
}

// int fib_iter(int n){
//     int r1=0,r2=1,r3;
//     for(int i=2;i<=n;i++){
//         r3=r2+r1;
//         r1=r2;r2=r3;
//     }
//     return r3;
// }

int main(){
    for(int i=0;i<10;i++){
        m[i]=-1;
    }

    int n;
    cout<<"enter n : ";
    cin>>n;
    cout<<"(Memoization ) Fibonacci series : "<<fib_rec_mem(n)<<endl;
    // cout<<"(Recursion) Fibonacci series : "<<fib_rec(n)<<endl;
    // cout<<"(Iteration) Fibonacci series : "<<fib_iter(n);
    return 0;
}