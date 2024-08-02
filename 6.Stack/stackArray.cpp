#include<iostream>
using namespace std;

class stack{
    int size;
    int top;
    int *s;

    public:
    stack(int size){
        this->size=size;
        this->top=-1;
        this->s=new int[size];
    }
    
    int getTop(){
        return top;
    }
    int getCurrentSize(){
        return top+1;
    }

    void push(int data){
        if(top<size-1){
            top++;
            s[top]=data;
        }
        else cout<<"Stack is full"<<endl;
    }

    int pop(){
        if(top==1){
            cout<<"The stack is empty"<<endl;
        }
        else{
            int x=s[top];
            top--;
            return x;
        }
        
    }
    int topStack(){
        if(top==-1) return -1;
        else
            return s[top];
    }

    void display(){
        for(int i=0;i<=top;i++){
            cout<<s[i]<<" ";
        }
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else
            return false;
    }

    bool isFull(){
        if(top==this->size-1)
            return true;
        else
            return false;
    }

    int peek(int pos){
        if(pos<=top+1){
            return s[top-pos+1]; // this formula is used to get the element stored at a pos
        }
        else
            return -1;
    }
};

int main(){
    int size=5;
    stack st(size);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    // cout<<st.peek(3)<<endl;
    st.pop();
    // cout<<st.peep(30)<<endl ;
    st.display();
    return 0;
}