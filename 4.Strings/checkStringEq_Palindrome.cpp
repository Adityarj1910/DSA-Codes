#include<iostream>
using namespace std;

/* --> this gives some error needs checking

bool CompareStrings(char a[], char b[]){
    int i=0, j=0, count = 0;

    while((a[i]!='\0' && b[j]!='\0')){
        if( a[i]==b[j]){
            i++; j++; count++;
        }
        else{
            cout<<count<<endl;    
            return false;
        }
        
    }
    cout<<count<<endl;
    return true;
}
*/

void checkPalindrome(char a[], int n){
    int i, j=n-1;
    for(i=0;i<=j;i++,j--){
        if(a[i] != a[j]){
            break;
        }
    }
    if(a[i]==a[j]){
        cout<<"Is Palindrome";
    }
    else 
        cout<<"Is Not Palindrome";
    }

void check(char a[], char b[]){
    int i =0,j=0;
    for(i=0,j=0;(a[i]!= '\0' && b[j]!= '\0'); i++,j++){
        if(a[i]!=b[j]){
            break;
        }
    }
    if(a[i]==b[j]) cout<<"Equal";
    else cout<<"unequal";
}

int main(){
 
    char a[10]="Painteri";
    //char b[10]="Painting";
    char b[10]="Painter";
    char c[]="nitin";

/*
    int x = CompareStrings(a,b);
    if(x == 1) cout<<"Equal Stings";
    else cout<<"Unequal Strings";
*/
/*    
    check(a,b);
*/    
    checkPalindrome(c,5);

}