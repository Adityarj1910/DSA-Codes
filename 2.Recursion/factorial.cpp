#include<iostream>
using namespace std;

int fact_n_rec(int n){
    if(n==1 || n==0){
        return 1;
    }
    else 
        return fact_n_rec(n-1)*n;
}

int fact_n_iter(int n){
    int i,fact=1;
    for(i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    cout<<"Factorial(rec) of n is : "<<fact_n_rec(n)<<endl;
    cout<<"Factorial(rec) of n is : "<<fact_n_iter(n);

}