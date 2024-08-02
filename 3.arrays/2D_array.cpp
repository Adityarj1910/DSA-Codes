#include<iostream>
using namespace std;

int main(){
/*creating a 2D array completely in stack
#
    int arr[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};
#
*/
/*creating a array of pointers(in stack) and then pointing each to a dynamically created array(in heap)
#
    int* arr[3]; // this creates an array of pointers in stack
#   arr[0]=new int[4]; 
#   arr[1]=new int[4]; 
#   arr[2]=new int[4];

// accesing elements is same as a normal 2d array i.e;
    arr[1][2];
*/

/*creating a double pointers(in stack) and then then creating an array of pointers(in heap) and pointing them to array(in heap)
#
    int** a; // this creates a double pointer in stack

    a=new int*[3]; //creating an array of pointer dynamically(in heap)

#   arr[0]=new int[4]; 
#   arr[1]=new int[4]; 
#   arr[2]=new int[4];

// accesing elements is same as a normal 2d array i.e;
    arr[1][2];
*/

}