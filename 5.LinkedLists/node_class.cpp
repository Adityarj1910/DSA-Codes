#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
};

class linkedList{
    private:
        node *head;

    public:
        linkedList(){head = NULL;}
        linkedList(int a[], int n);
        ~linkedList();

        void display();
        void insert(int index, int data);
        int Delete(int index);
        int length();

};

linkedList:: linkedList(int a[], int n){
    struct node *t,*tail;
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

linkedList::~linkedList(){
    node *temp = head;
    while(head){
        head=head->next;
        delete temp;
        temp=head;
    }
}


void linkedList::display(){ 
    int cnt=0;
    node *temp=head;
    while(temp != NULL){
        cnt++;
        cout<<"The element "<<cnt<<" is "<<temp->data<<endl;
        temp=temp->next;
    }
}

int linkedList::length(){
    node *temp=head;
    int count=0;
    while(temp!= NULL){
        count++;
        temp=temp->next;
    }
        return count;
}

void linkedList::insert(int index, int data){
    node* temp=head;
    if(index>0){
        struct node* t =new node;
        t->data = data;
        t->next = NULL;
        if(index==1){
            t->next=head;
            head=t;
        }

        else if(index>1){
            int pointer=1;
            while(pointer<index){ 
                if(temp!=NULL){
                    pointer++;
                    temp=temp->next;
                }
                else{
                    cout<<"Given Index is Out of Bound";
                    break;
                }
            }
        t->next=temp->next;
        temp->next=t;
        
        }
    }
}

int linkedList::Delete(int index){
    int x;
    if(index<1){
        cout<<"Negetive integer"<<endl;
        return -1;
    }

    if(index==1){
        struct node *p=head;
        head=head->next;
        x=p->data;
        free(p);
    }
    else{
        int pos=1;
        struct node *p = head, *q=NULL;
        while(p && pos<index){
            q=p;
            p=p->next;
            pos++;
        }if(p==NULL){
            cout<<"Index out of Bound"<<endl;
        }else{
            q->next=p->next;
            x=p->data;
            delete p;
        }
    }
    return x;
} 

int main(){
    int a[]={10,20,30,40};
    linkedList l(a,4);
    l.insert(3,90);
    l.display();
    return 0;
}