#include<iostream>
using namespace std;
#ifndef Queue_h
#define Queue_h

class node{
    public:
    node *left;
    int data;
    node *right;
};

class cQueue{
    int size;
    int front; int rear;
    node **cQ;

    public:
    cQueue(int size);
    void enqueue(node *data);
    node* dequeue();
    int isEmpty();
};

cQueue::cQueue(int size){
    front=rear==-1; 
    this->size=size;
    cQ=(node **)malloc(size*sizeof(node *)); // as it will store the address of the nodes.
}

void cQueue::enqueue(node *data){
    if(front=(rear+1)%size){
        cout<<"Circular overflow"<<endl;
    }
    else{
        if(front==-1){
            front=0;
            rear=0;
        }
        else{
            rear = (rear+1)%size; 
        }
        cQ[rear]=data;
    }
}

node* cQueue::dequeue(){
    if(front==-1){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        node* x = NULL;
        if(front==rear){
            front=rear=-1;
        }
        else{
            front = (front+1)%size;
        }
    }
}

int cQueue::isEmpty(){
    return front==rear;
}


#endif