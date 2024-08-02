#include<iostream>
using namespace std;

int checkString(char name[]){
    for(int i=0;name[i]!='\0';i++){
        if(!(name[i]>=65 && name[i]<=90) 
            && !(name[i] >=97 && name[i]<=122)
            && !(name[i]>=48 && name[i]<=57)){
                return 0;
            }
    }
    return 1;
}

void reverseString_cpoy(char a[]){
    char b[10];
    int i,j;
    for(i=0;a[i]!='\0';i++){}
    i-=1; //to get the last index of string

    for(j=0;i>=0;i--,j++){
        b[j]=a[i];
    }
    b[j]='\0';
    cout<<b<<endl;
}

void reversingSwap(char a[]){
    int j,i=0,temp;
    for(j=0;a[j]!='\0';j++){}
    j=j-1;
    while(i<j){
        temp =a[i];
        a[i]=a[j];
        a[j]= temp;
        j--;i++;
    }
}

int main(){
//valid string -> only contains letters and numbers. (in my case)
    char name[10] = "Mom123?";


/*    if(checkString(name)==1){
        cout<<"Valid String";
    }
    else if(checkString(name)==0){
        cout<<"Invalid String";
    }
*/

    char a[]="Python";
    cout<<a<<endl;
    reversingSwap(a);
    cout<<a<<endl;



return 0;
    }
