#include<iostream>
using namespace std;

int exp_rec(int m,int n){
    if(n==0){
        return 1;
    }
    else 
        return exp_rec(m,n-1)*m;
}

int exp_iter(int m,int n){
    int i,pow=1;
    for(i=1;i<=n;i++){
        pow=pow*m;
    }
    return pow;
}

int main(){
    int n,m;
    cout<<"Enter the value of m and n : ";
    cin>>m>>n;
    cout<<"(Recurssion) Power of "<<m<<" raised to "<<n<<" is : "<<exp_rec(m,n)<<endl;
    cout<<"(Iteration ) Power of "<<m<<" raised to "<<n<<" is : "<<exp_iter(m,n)<<endl;

}