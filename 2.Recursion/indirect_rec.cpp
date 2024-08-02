#include<iostream>
using namespace std;
int b(int n);
int a(int n){
    if(n>0){
        cout<<n<<" ";
        b(n-1);
    }
}
int b(int n){
    if(n>0){
        cout<<n<<" ";
        a(n/2);
    }
    
}

int main(){
    a(20);
    return 0;
}