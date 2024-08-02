#include<iostream>
using namespace std;

int maxi = 10;
int arr[maxi] = {30,20,15,5,10,12,6};
int size = 7;
void insert(int key){
    if(size<maxi-1){
        arr[size] = key;
        size++;
    }
    for(   
}