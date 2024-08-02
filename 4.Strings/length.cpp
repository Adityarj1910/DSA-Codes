#include<iostream>

#include<math.h>
using namespace std;

int getLength(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

void UppertoLowerCase(char s[]){
    int i=0;
    while(s[i]!='\0'){
        s[i]=s[i]+32;
        i++;
    }
}

void changeCase(char s[]){ //-> if upper then to lower and vice versa
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>=65 && s[i]<=90){
            s[i]+=32;
        }
        else if(s[i]>='a' && s[i]<='z'){
            s[i]-=32;
        }
    }
}

void countWords(char a[]){
    int word = 1;
    for(int i=0;a[i]!='\0';i++){
        if(a[i]==' ' && (a[i-1]!=' ' && a[i+1] != '\0' )){ // to check if the current char is a space and the previous char is not a whitespace.
            word++;
        }
    }
    cout<<"Number of words in "<<a<<" is "<<word<<endl;
}



int main(){

    char s[20] ="WeLCoMe ";
    char a[20] = "How are    you MOM";
    //cout<<getLength(s);

    /*UppertoLowerCase(s);
    cout<<s;
    */

   /*changeCase(s);
   cout<<s;
    */

   countWords(s);
   countWords(a);

    return 0;
}