#include<iostream>
using namespace std;

int main(){

    /*int a =10;
    int *p;
    p = &a;
    cout<<a<<endl; //returns the value stored in the variable a
    cout<<p<<endl; //returns the value(address) stored the address variable p
    cout<<*p<<endl;//returns the value stored in the address stored in pointer variable
    cout<<&a<<endl;//returns the address of the variable a;
    cout<<*&a<<endl;//returns the address of the variable a;
    */
    int *p;
    //p = (int *)malloc(3*sizeof(int));
    p = new int[3];//creating a dynamic array in heap
    p[0]=10; p[1]=11, p[2]=12;
    for(int i=0;i<3;i++){
        cout<<p[i]<<endl;
    } 
    //free(p); in c to free the heap memory;
    delete []p//delete/release the array

    return 0;
}