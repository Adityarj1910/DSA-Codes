//a demo prog to illustrate if a the size of a dynamic array can be extended.
//## though the original size of the array cannot be increased but it can be an alternative ##
// a static array can't be exteded as the new copy and old copy will be present till lifetime of the program.##

#include<iostream>
using namespace std;

void init(int *p){ //initializes the array
    for(int i=0;i<5;i++){
        p[i]=i+1;
    }
}

void print(int *p,int n){ //prints the array
    for(int i=0;i<n;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int *p;
    p = new int[5];
    init(p);
    print(p,5);
    int *q;
    q = new int[10]; ///dec a new dynamic array
    for(int i=0;i<5;i++){ 
        q[i]=p[i]; // copy the elements to the new bigger array
    }

    delete []p; //free the smaller array
    p = q; //point p to new array ... p and q both are pointing to the new array
    q = NULL; //unpoint q ... free the pointer

    print(p,10); //here the size of the array got increased ... 

    return 0;

}   