#include<iostream>
using namespace std;

void checkDuplicate_Hash(char a[]){
    int hash[122-96]={0};
    int i=0;
    while(a[i]!='\0'){
        hash[a[i]-97]++;
        i++;    
    }
    for(int i=0;i<26;i++){
        if(hash[i]>1){
            cout<<char(i+97)<<" has "<<hash[i]<<" occurences "<<endl;
        }
    }
}

void checkDuplicate_Bit(char a[]){
    int h =0, x=0; //we take h and x as a single variable as we needed 26 bit to store each charcter hence 32 bit is nearest and integer is perfect
                   // in a loop we check weather the bit is on or off. If the bit is on that means it is an duplicate else we set the bit as 1

                   //h is main varible where the bits are updated and compared to.

    for(int i=0;a[i]!='\0';i++){
        x = 1; //we set x = 1 that means in a 32 bit we store as 00000000000000000000000000000001 so that we can shift it to the desrired bit location
        x = x<<a[i]-97; // we left shift the 1 to the bit location of the i(sort of bit index) so we can comapre it with h weather its on or off

        if((h&x) > 0){ // now we check weather the bit is on or off using and opration (as and operation makes the o/p 1 only if 1 & 1 else 0)
            cout<<(a[i])<<" is duplicate"<<endl;// and is 1 that means the char is already in the array hence the COUT
        }
        else // else meaning the o/p of the AND op is 0 => char is not duplicate
            h = h|x; //hence we set the bit as 1 by OR operation (as 0 OR 1, 1 OR 1. 1 OR 0  is " 1 ") so that for the next iteration we can check if this char appears again
    } // and this continues for all the char present in the array, setting x=1 each time as x is a comparator/auxillary variable
}


int main(){

    char a[]="finding";
         
    //checkDuplicate_Hash(a);
    checkDuplicate_Bit(a);

    return 0;
}