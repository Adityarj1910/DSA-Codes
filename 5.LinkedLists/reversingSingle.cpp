#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
}*head, *tail;

void create(int a[], int n){
    struct node *t;
    head = (struct node *)malloc(sizeof(struct node));
    head-> data = a[0];
    head-> next = NULL;
    tail = head;

    for(int i=1;i<n;i++){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
    cout<<"Linked List Created YAYAYAY"<<endl;
}

void display( struct node *temp){
    int count =0;
    while(temp != NULL){
        count++;
        cout<<"The element "<<count<<" is "<<temp->data<<endl;
        temp=temp->next;
    }
}


void reverseAuxillary(int size){
    int arr[size];
    node *temp = head;
    int i=0;
    while(temp && i<size){
        arr[i++]=temp->data;
        temp=temp->next;
    }
    i=size-1;
    temp=head;
    while(temp && i>=0){
        temp->data = arr[i];
        i--;
        temp=temp->next;
    }
}

void reverse_SlidingPointers(struct node *p){
    struct node*q=NULL, *r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head = q;
}

void reverse_Recursive(struct node *q, struct node *p){
    if(p){
        reverse_Recursive(p,p->next);
        p->next=q;
    }
    else{
        head = q;
    }
}


int main(){

    int a[]={10,20,30,40};
    int n = sizeof(a)/sizeof(int);
    create(a,n);
    // reverseAuxillary(4);
    // reverse_SlidingPointers(head);
    // reverse_Recursive(NULL, head);


    display(head);
    
    return 0;
}