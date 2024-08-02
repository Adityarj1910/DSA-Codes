#include<iostream>
using namespace std;


void checkAnagram(char a[],char b[]){
    int *hash;
    hash = new int[26];
    for(int i=0;i<26;i++){
        hash[i]=0;
    }
    

    for(int i=0;a[i]!='\0';i++){
        hash[a[i]-97]++;
    }

    for(int i=0;b[i]!='\0';i++){
        hash[b[i]-97]--;
    }
int j;
    for(j=0;j<26;j++){
        if(hash[j]!=0) {
            cout<<"They ARE NOT anagram";
            break;
        }
    }
if( j==26){
    cout<<"They ARE anagram";
}
delete []hash;
}

int main(){

    char a[] = "decimalz";
    char b[] = "medialaa";
    
    checkAnagram(a,b);

    return 0;
}