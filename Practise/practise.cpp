#include<bits/stdc++.h>
using namespace std;

void swapp(int *p, int*q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

int bin_ser(int arr[],int l, int h, int key){
while (true){
     int mid = (l+h)/2;
    if(arr[mid] == key){
        return mid;
    }
    else if(key < arr[mid]){
        h = mid-1;
    }
    else{
        l = mid+1;
    }
}
return -1;
}
int main(){
    int arr[] = {10, 20 , 35, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
//     for(int i =0;i<n;i++){
//         cout<< arr[i]<<" ";
//     }
//     cout<<endl;
//     sort(arr, arr+n);
//     for(int i =0;i<n;i++){
//         cout<< arr[i]<<" ";
//     }
// }
    // int a = 10, b = 20;
    // swapp(&a,&b);
    // cout<<a<<" "<<b;

    int arr2[10]= {};
    memcpy(arr2, arr, sizeof(arr));

    for(int i =0;i<10;i++){
        // cout<<arr2[i]<<" ";
    }
    
    int x = bin_ser(arr, 0, n-1, 25);
    cout<<x;
    
    return 0;
}