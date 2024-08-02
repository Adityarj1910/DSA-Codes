#include<iostream>
using namespace std;

class array{ 
    //int *A;
    int a[20] = {1,2,3,4,5,6};
    int size = 20;
    int length = 6;

    public:
    // array(int s){
    //     size=s;
    //     A=new int[size];
    //     length=0;
    // }

    void fill(){
        int n;
        cout<<"How many elements to enter ? : ";
        cin>>n;
        cout<<"Enter numbers : "<<endl;
        for(int i=0;i<n;i++){
            cin>>a[i];
            length++;
        }
    }

    void display(){
        cout<<endl<<"Elements are : "<<endl;
        //cout<<length<<endl;
        for(int i=0;i<length;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    void add(int x){    //T(n) = O(1)
        a[length] = x;
        length++;
        // cout<<length;
    }

    void insert(int ind,int x){   //T(n) = O(n) ... to enter ele at beg of array.

        if(ind<=length){
            for(int i=length;i>ind;i--){
                a[i]=a[i-1];
            }
            a[ind]=x;
            length++;
        }
    }

    void Delete(int ind){ // T(n) = O(n)
        int x;
        if(ind<=length){
            x = a[ind];
            for(int i=ind;i<length;i++){
                a[i] = a[i+1];
            }
            length--;
        }
        cout<<"The deleted element is : "<<x<<" at index : "<<ind;
    }

    int linearSearch(int key){ //T(n) = O(n)
        for(int i=0;i<length;i++){ // -> best 1 worst n
            if(a[i] == key){
                return i;
            }
        }
        return -1;
    }
    int binarySearch_rec(int l,int h,int key){
        if(l<h){
            int mid = (l+h)/2;
            if(key==a[mid])
                return mid;
            else if(key<a[mid])
                return binarySearch_rec(l,mid-1,key);
            else
                return binarySearch_rec(mid+1,h,key);
        }
        return -1;
    }

    int binarySearch_iter(int l,int h,int key){
        int pos = -1;
        int mid;
        while(l<h){
            mid=(l+h)/2;
            if(key==a[mid]){
               pos = mid;
               break;
            }
            else if(key<a[mid])
                h = mid-1;
            else 
                l = mid+1;
        }
        return pos;
    }


};


int main(){
    // int s;
    // cout<<"Enter the size of the array : ";
    // cin>>s;

    array arr;
    // arr.fill();
    arr.display();
    //arr.add(10);
    //arr.insert(3,19);
    //arr.Delete(3);
    //arr.display();


/*  int x = arr.linearSearch(7);
    if(x == -1) 
        cout<<"Element not found";
    else 
        cout<<"Element found at : "<<x;
*/  

/*    int x = arr.binarySearch_rec(0,6,4);
    cout<<x;
*/
    int x = arr.binarySearch_iter(0,6,4);
    cout<<x;

    return 0;

}