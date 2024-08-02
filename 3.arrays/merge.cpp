#include<iostream>
using namespace std;

int merger(int a[],int b[],int c[],int m, int n){
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(a[i]<b[j]){
            c[k]=a[i];
            k++;i++;
        }
        else{
            c[k]=b[j];
            k++;j++;
        }
    }
    while(i<m){
        c[k]=a[i];
        k++;i++;
    }

    while(j<n){
        c[k]=b[j];
        k++;j++;
    }
}


int main(){

    int a[5]={2,4,6,8,10};
    int b[5]={1,3,5,7,9};
    int c[10];
    for(int i=0;i<5;i++){cout<<a[i]<<" ";}
    cout<<endl; 
    for(int i=0;i<5;i++){cout<<b[i]<<" ";}
    cout<<endl;
    merger(a,b,c,5,5);
    for(int i=0;i<10;i++){cout<<c[i]<<" ";}

    return 0;
}