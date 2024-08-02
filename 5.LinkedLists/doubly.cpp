#include<iostream>
using namespace std;

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*head,*tail;

void create(int a[], int n){
    head=new node;
    head->data=a[0];
    head->prev=NULL;
    head->next=NULL;
    tail=head;

    for(int i=1;i<n;i++){
        struct node *t=new node;
        t->data=a[i];
        t->prev=tail;
        t->next=NULL;
        tail->next=t;
        tail=t;
    }
}

void display(){
       struct node *temp=head;
       while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
       }
}
void insert(int data,int index){
    struct node *t=new node, *temp=head;
    if(index>0){
        if(index>1){
            int pos=1;
            while(pos<index-1){
                pos++;
                temp=temp->next;
            }
            t->data=data;
            t->next=temp->next;
            t->prev=temp;
            temp->next=t;
            t->next->prev=t;
        }
        else if(index==1){
            t->data=data;
            t->prev=NULL;
            t->next=temp;
            temp->prev=t;
            head=t;
        }
    }
}

int Delete(int index, int n){
    int x;
    struct node *p=head;
    if(index>0 && index<=n)
    if(index==1){
        head=head->next;
        head->prev=NULL;
        x=p->data;
        delete p;
    }
    if(index>1){
        int pos=1;
        node *q=NULL;
        while(pos<index){
            q=p;
            p=p->next;
            pos++;
        }
        q->next=p->next;
        if(p->next!=NULL){
            p->next->prev=q;
        }
        x=p->data;
        delete p;
    }
    return x;
}

void reverse(){
    node *p=head, *temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p->prev==NULL){// to check weater it is the end of the list
            head=p;
        }
    }

}
int main(){
    int a[]={10,20,30,40};
    int n = sizeof(a)/sizeof(a[0]);
    create(a,n);
    // insert(11,1);
    // cout<<Delete(4,n)<<endl;
    reverse();
    display();
    return 0;
}