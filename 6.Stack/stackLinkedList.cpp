#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
};

class stack{
        node *top;
        
    public:
        stack(){
            top=NULL;
        }

        void push(int data);
        int pop();
        int peep(int pos);
        int stackTop();
        bool isFull();
        bool isEmpty();
        void display();
};

void stack::push(int data){
    node *p=new node;
    if(p==NULL){
        cout<<"Stack overflow"<<endl;}
    else{
        p->data=data;
        p->next=top;
        top=p;
    }
}

int stack::pop(){
    if(top!=NULL){
        int x;
        node *temp=top;
        x=top->data;
        top=top->next;
        delete temp;
        return x;
    }
    else{
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
}

int stack::peep(int pos){
    node *temp=top;
    int x;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    if(temp!=NULL){
        x=temp->data;
    }
    else cout<<"No such position exist"<<endl;
    return x;
}

int stack::stackTop(){
    if(top!=NULL) return top->data;
    else return -1;
}

bool stack::isEmpty(){
    if(top==NULL){
        return true;
    }
    else return false;
}

bool stack::isFull(){
    node *t=new node;
    if(t==NULL) return true;
    else return false;
}

void stack::display(){
    node *temp=top;
    while(temp){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}

int main(){

    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    // st.pop();
    // cout<<st.isEmpty()<<endl;
    // cout<<st.peep(3)<<endl;
    // cout<<st.stackTop()<<endl;
    st.display();


    return 0;
}