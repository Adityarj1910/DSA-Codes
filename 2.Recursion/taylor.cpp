#include<iostream>
using namespace std;


int sum_n(int n){
    if(n==1){
        return 1;
    }
    else 
        return sum_n(n-1)+n;
}

int fact_n_rec(int n){
    if(n==1 || n==0){
        return 1;
    }
    else 
        return fact_n_rec(n-1)*n;
}

int exp_rec(int m,int n){
    if(n==0){
        return 1;
    }
    else 
        return exp_rec(m,n-1)*m;
}