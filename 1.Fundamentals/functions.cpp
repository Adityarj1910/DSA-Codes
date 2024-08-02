#include<iostream>
using namespace std;

void fun(int a[]){
    cout<<sizeof(a)/sizeof(int)<<endl;
}


int main(){
    int arr[]={1,2,3,4};
    fun(arr); 

    return 0;
}