#include<iostream>
using namespace std;

class queue_singlePointer{
    int size;
    int rear;
    int *q;

    public:
    queue_singlePointer(int size){
        this->size=size;
        rear=-1;
        q=new int[size];
    }

    void enqueue(int data);
    int dequeue();
    void display();
};

void queue_singlePointer :: enqueue(int data){
    if(rear<size-1){
        q[++rear]=data;
    }
    else
        cout<<"Queue is full"<<endl;
}

int queue_singlePointer :: dequeue(){
    if(rear>=0){
        int x=q[0];
        for(int i=0;i<rear;i++){
            q[i]=q[i+1];
        }
        rear--;
        return x;
    }
    else{
        cout<<"No elements in queue"<<endl;
        return -1;
    }
}

void queue_singlePointer::display(){
    if(rear>-1){
        for(int i=0;i<=rear;i++){
            cout<<q[i]<<"  ";
        }
        cout<<endl;
    }
    else{
        cout<<"The queue is empty"<<endl;
    }
}


class queue_twoPointer{
    int size;
    int front;
    int rear;
    int *q2;

    public:
    queue_twoPointer(int size);
    void enqueue(int data);
    int dequeue();
    void display();
};

queue_twoPointer::queue_twoPointer(int size){
    front=rear=-1;
    this->size=size;
    q2=new int[size];
}

void queue_twoPointer::enqueue(int data){
    if(front<rear && rear<size-1){
        q2[++rear]=data;
    }
    else{
        cout<<"Queue is full"<<endl;
    }
}

int queue_twoPointer::dequeue(){
    int x;
    if(front< rear){
        front++;
        x=q2[front];
        return x;
    }
    else{
        cout<<"Queue is empty"<<endl;
        return -1;
    }
}

void queue_twoPointer::display(){
    if(front<rear){
        for(int i=front+1;i<=rear;i++){
            cout<<q2[i]<<"  ";
        }
        cout<<endl;
    }
    else{
        cout<<"Queue is empty"<<endl;
    }
}


class cQueue{
    int size;
    int front; int rear;
    int *cQ;

    public:
    cQueue(int size);
    void enqueue(int data);
    int dequeue();
};

cQueue::cQueue(int size){
    front=rear==-1; 
    this->size=size;
    cQ=new int[size];
}

void cQueue::enqueue(int data){
    if(front=(rear+1)%size){
        cout<<"Circular overflow"<<endl;
    }
    else{
        if(front==-1){
            front=0;
            rear=0;
        }
        else{
            rear = (rear+1)%size; // increamenting the index by one.
        }
        cQ[rear]=data;
    }
}

int cQueue::dequeue(){
    if(front==-1){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        int x = cQ[front];
        if(front==rear){// condition where only one element is present in the queue -> _ _ _ fr _ _ _... 
        //so after deleting the queue becomes empty, hence must me reset
            front=rear=-1;
        }
        else{
            front = (front+1)%size;// increamenting the index by one
        }
    }
}


int main(){

    int size=7;
    queue_singlePointer q(size);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display(); 


    queue_twoPointer q1(size);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.display();
    q1.dequeue();
    q1.display();


    return 0;
}

