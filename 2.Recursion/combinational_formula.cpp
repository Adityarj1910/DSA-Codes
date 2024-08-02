#include<iostream>
using namespace std;

int comb(int n, int r){
    if(r==0 || r==n){
        return 1;
    }
    else{
        return comb(n-1, r-1)+comb(n-1,r);
    }
}

int main(){
    int n,r;
    cout<<"Enter the value of n and r: "<<endl;
    cin>>n>>r;
    cout<<"The combination of "<<n<<"C"<<r<<" is : "<<comb(n,r);

    return 0;
}