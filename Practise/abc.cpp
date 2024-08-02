#include<stdio.h>
#include<iostream>

using namespace std;

int A[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int size=20;
int length=15;

void insert(int x){
    int i=length-1;
    while(A[i]>x){
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
}

int main(){
    int x;
    cout<<"enter the number to be inserted:";
    cin>>x;
    cout<<endl;
    insert(x);
    cout<<"array after insertion:";
    for(int i=0;i<length;i++){
        cout<<A[i]<<" ";
    }

    return 0;
}