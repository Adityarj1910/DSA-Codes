#include<iostream>
using namespace std;

void swap(int *a,int*b){
    int temp = *a;
    *a =*b;
    *b = temp;
}

int reverse_aux(int a[], int n){
    int *b;
    b = new int[n]; // created in heap
    int j=0;
    for(int i=n-1;i>=0;i--){
        b[j]=a[i];
        j++;
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
    delete []b; // free the space occupied by auxillay array
}



int reverse_swap(int a[],int n){
    int i =0, j=n-1;
    while(i<j){
        swap(&a[i],&a[j]);
        i++;
        j--;
    }
}

void left_shift(int a[], int n){
    for(int i=1;i<n;i++){
        a[i-1]=a[i];
    }
    a[n-1] = 0;
}

void left_rotate(int a[], int n){
    int temp = a[0];
    for(int i=1;i<n;i++){
        a[i-1]=a[i];
    }
    a[n-1] = temp;
}


int main(){

    int a[10]={8,3,9,15,6,10,7,2,12,4};
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
//  reverse_aux(a,10);
//  reverse_swap(a,10);
//  left_shift(a,10);
//  left_rotate(a,10);



    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}