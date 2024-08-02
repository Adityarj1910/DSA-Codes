#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
}*head, *tail=NULL;

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

void display(){
    struct node *temp = head;
    int count =0;
    while(temp != NULL){
        count++;
        cout<<"The element "<<count<<" is "<<temp->data<<endl;
        temp=temp->next;
    }
}
bool checkSorted(struct node *temp){
    int max = head->data;
    while(temp){
        if(temp->data>=max){
            max=temp->data;
            temp=temp->next;
        }
        else{
            return false;
        }
    }
    return true;
}

void removeDuplicates(){ //we know the list is already sorted
    struct node *p=head->next, *q=head;
    while(p){
        if(q->data!=p->data){
            q=p;
            p=p->next;
        }
        else{
            q->next=p->next;
            delete p;
            p=q->next;
        }
    }
    cout<<"The Duplicate elements are deleted"<<endl;
}

int main(){

    int a[]={3,5,5,8,8,8};
    int n = sizeof(a)/sizeof(int);
    create(a,n);
    removeDuplicates();
    display();

    /*
    bool ifSorted = checkSorted(head);
    if(ifSorted==1) cout<<"Is Sorted";
    else cout<<"Is NOT Sorted";
    */

    return 0;
}