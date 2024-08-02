#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
}*first=NULL,*second=NULL, *third=NULL;

void create1(int a[], int n){
    struct node *t, *tail=NULL;
    first = (struct node *)malloc(sizeof(struct node));
    first-> data = a[0];
    first-> next = NULL;
    tail = first;

    for(int i=1;i<n;i++){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
}

void create2(int a[], int n){
    struct node *t, *tail=NULL;
    second = (struct node *)malloc(sizeof(struct node));
    second-> data = a[0];
    second-> next = NULL;
    tail = second;

    for(int i=1;i<n;i++){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
}

void display(struct node *temp){

    while(temp != NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}

void concat(){
        struct node *temp=first;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=second;
        third=first;
}

void merge(){
    struct node *p=first, *q=second,*r=third;
    struct node *t=new node;
    if(p->data<q->data){
        t->data=p->data;
        t->next=NULL;
        third = t;
        r = t;
        p=p->next;
    }
    else{
        t->data=q->data;
        t->next=NULL;
        third = t;
        r = t;
        q=q->next;
    }
    while(p!=NULL && q!=NULL){
        struct node *t=new node;
        if(p->data<q->data){
            t->data=p->data;
            t->next=NULL;
            r->next=t;
            r=t;
            p=p->next;
        }
        else{
            t->data=q->data;
            t->next=NULL;
            r->next=t;
            r=t;
            q=q->next;
        }
    }
    while(p){
        struct node *t=new node;
        t->data=p->data;
        t->next=NULL;
        r->next=t;
        r=t;
        p=p->next;
    }
    while(q){
        struct node *t=new node; 
        t->data=q->data;
        t->next=NULL;
        r->next=t;
        r=t;
        q=q->next;
    }
}

int main(){
    int a[]={1,3,5,7,9};
    int x=sizeof(a)/sizeof(a[0]);
    int b[]={2,4,6,8};
    int y=sizeof(b)/sizeof(b[0]);

    create1(a,x);
    create2(b,y);
    display(first);
    display(second);
    // concat();
    merge();
    display(third);
    
    return 0;
}