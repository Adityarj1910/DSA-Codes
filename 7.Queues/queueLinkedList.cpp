#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class queue{
    node *front,*rear;
    public:
    queue(){
    front=rear=NULL;
    }

    void enqueue(int data);
    int dequeue();
    void display();
};

void queue::enqueue(int data){
    node *temp=new node;
    temp->data=data;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=temp;
        rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

int queue::dequeue(){
    if(front!=NULL){
        int x=front->data;
        node *temp=front;
        front=front->next;
        delete temp;
        return x;
    }
    else{
        cout<<"Queue is empty"<<endl;
        return -1;
    }
}

void queue::display(){
    node *temp=front;
    if(front && rear){
        while(temp!=rear->next){
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
    }
    cout<<endl;
}

int main(){

    queue qL;
    qL.enqueue(10);
    qL.enqueue(20);
    qL.enqueue(30);
    qL.enqueue(40);
    qL.display();
    qL.dequeue();
    qL.dequeue();
    qL.display();
    

    return 0;
}