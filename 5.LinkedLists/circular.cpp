#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
};

class circularLL{
    public:
        node *head;
        circularLL(){head=NULL;}
        circularLL(int a[],int n);

        void display(node *temp);
        void display_recursive(node *temp);
        void insert(node *temp,int index, int data);
        int Delete(node *temp, int index);
};


circularLL::circularLL(int a[],int n){
    node *last;
    head=new node;
    head->data=a[0];
    head->next=head;
    last=head;

    for(int i=1;i<n;i++){
        node *t=new node;
        t->data=a[i];
        t->next=head;
        last->next=t;
        last=last->next;
    }
}

void circularLL::display(node *temp){
    do{
        cout<<temp->data<<"  ";
        temp=temp->next;
    }while(temp!=head);
}

void circularLL::display_recursive(node *temp){
    
    static int flag=0;
    if(temp!=head || flag == 0){
        flag=1;
        cout<<temp->data<<"  ";
        display_recursive(temp->next);
    }
}

void circularLL::insert(node *temp,int index,int data){
    if(index>1){
        node *t=new node;
        for(int i=1;i<index-1;i++){
            temp=temp->next;
        }
        t=new node;
        t->data=data;
        t->next=temp->next;
        temp->next=t;
    }
    else if(index==1){
        node *t=new node;
        t->data=data;
        t->next=head;
        do{
            temp=temp->next;
        }while(temp->next!=head);
        temp->next=t;
        head=t;
    }
    
}

int circularLL::Delete(node *temp, int index){
    node *p=temp, *q=NULL;
    int pos=1;
    int x;
    if(index>1){
        while(pos<index){
            pos++;
            q=p;
            p=p->next;
        }
        if(p==NULL){
            cout<<"Index out of bound"<<endl;
        }
        else{
        q->next=p->next;
        x=p->data;
        delete p;
        }
    }
    else if(index==1){
        node *q=head;
        do{
            q=q->next;
        }while(q->next!=head);
        head=head->next;
        q->next=head;
        x=p->data;
        delete p;
    }
return x;
}

int main(){
    int a[]={10,20,30,40};
    int n = sizeof(a)/sizeof(a[0]);
    circularLL c(a,n);
    // c.insert(c.circularLL::head,1, 99);
    cout<<c.Delete(c.circularLL::head,3)<<endl;
    c.display_recursive(c.circularLL::head);
    
}
