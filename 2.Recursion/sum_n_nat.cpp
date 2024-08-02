#include<iostream>
using namespace std;

int sum_n(int n){
    if(n==1){
        return 1;
    }
    else 
        return sum_n(n-1)+n;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    cout<<"Sum of first n natural numbers are : "<<sum_n(n);
}