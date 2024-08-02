#include<iostream>
using namespace std;

int main(){

    char temp='a';
    

    char a[5]={'a','b','c','d','e'};
    char b[5]={97,98,99,100,101}; //we can initialize a character by giving its ascii codes.

    //cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<endl;
    //printf("%d",a[0]);
    //cout<<b[0]<<b[1]<<b[2]<<b[3]<<b[4];

    char name[5]={'C','A','T'};
    //cout<<name<<endl;
    /*for(int i=0;i<5;i++){
        cout<<name[i];
    }
    */
    //cout<<name[3];

    char old[10];
    /*scanf("%s",old); // it will only scan a single word
    *///printf("%s",old);//and will print only the first word
    //to resolve that we use gets function that can take more than a single word.

    // gets(old);
    // printf("%s",old);
    char ab[5];
    for(int i=0;i<5;i++){
        cout<<ab[i]<<" ";
    }
    return 0;
}