#include<iostream>
using namespace std;

void swap(int *a,int*b){
    int temp = *a;
    *a =*b;
    *b = temp;
}

void insert_sort(int a[],int n, int element){
    int pos=0,i=0;
    do
    {
        pos++;
    } while (a[pos]<element);
    for(int i=n;i>=pos;i--){
        a[i]=a[i-1];
    }
    a[pos]=element;
}

void insert_better(int a[], int n, int element){
    for(int i=n-1;i>=0;i--){
        if(a[i]>element){
            a[i+1]=a[i];
        }
        else{
            a[i+1]=element;
            break;
        }
    }
}

int check_sorted(int a[],int n){
    bool dirty = 0;
    for(int i=0;i<n-1;i++){
     if(a[i]>a[i+1]){
        dirty=1;
     } 
    }
    return dirty;
}

void neg_on_left_side(int a[],int n){
    int i=0,j=n-1;
while(i<j){
    while(a[i]<0){
        i++;
    }
    while(a[j]>=0){
        j--;
    }
    if(i<j){
        swap(&a[i],&a[j]);
    }
}
}

int main(){
    int a[10] = {4,8,13,16,20,25,28,33};
    int b[10] = {-6,3,-8,10,5,-7,-9,12,-4,2};
    int length = 8; 
    for(int i=0;i<10;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
//  insert_better(a,8,18);
    
/*    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
*/
/*    bool x = check_sorted(a,8);
    if(x == 0) cout<<"Sorted !!";
    else if(x == 1)  cout<<"Not Sorted !!";
*/

neg_on_left_side(b,10);

for(int i=0;i<10;i++){
        cout<<b[i]<<" ";
    }

    return 0;
}