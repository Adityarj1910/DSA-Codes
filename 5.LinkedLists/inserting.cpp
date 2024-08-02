#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
}*head=NULL,*tail;

int count =0;

void display(struct node *temp){ 

    while(temp != NULL){
        count++;
        cout<<"The element "<<count<<" is "<<temp->data<<endl;
        temp=temp->next;
    }
}
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
}
/*

void insertAtBegg(struct node* temp, int data){ //prototype
    struct node* t;
    // t = (struct node*)malloc(sizeof(struct node));
    t = new node;
    t->data = data;
    t->next = head;
    head = t;
}

// we can assume that the index of the linked list starts from |||(.  \1/  .)|||
void insertAt_Middle(struct node* temp, int index, int data){ //  prototype
    int pointer = 1; // this means inserting a new node after 4th node
    struct node* t;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = data;
    t->next = NULL;

    while(pointer<index){
        temp=temp->next;
        pointer++;
    }
    t->next = temp->next;
    temp->next=t;
}

*/
void insertAt(struct node* temp, int index, int data){
    // struct node* temp=head;
    if(index>0){// to validate the index
        struct node* t =new node;
        t->data = data;
        t->next = NULL;
        if(index==1){ //if the inserion is at the beggining
            t->next=head;
            head=t;
        }

        else if(index>1){ //if insertion is at a posion
            int pointer=1;
            while(pointer<index-1){ 
                if(temp!=NULL){//temp!=NULL to check weather the index is out of bound.
                    pointer++;
                    temp=temp->next;
                }
                else{
                    cout<<"Given Index is Out of Bound";
                    break; //out of loop
                }
            }
        t->next=temp->next;
        temp->next=t;
        
        }
    }
}

void insertatLast(int data){
    struct node *t=new node;
    t->data=data;
    t->next=NULL;
    if(head==NULL){
        head=t;
        tail=t;
    }
    else{
        tail->next=t;
        tail = t;
    }
}

void insertAt_Sorted(int data){
    struct node *temp=head, *t=new node;
    t->data=data;
    t->next=NULL;
    if(temp->data>data){
        t->next=head;
        head=t;
    }else{
        while(temp->next!=NULL && temp->next->data<data){
                temp=temp->next;
        }
        t->next=temp->next;
        temp->next=t;
    }
}

void insert_Sorted_2pointers(int data){
    struct node *p=head, *q=NULL, *t=new node;
    t->data=data;
    t->next=NULL;
    if(p->data>data){
        t->next=head;
        head=t;
    }else{
        while(p && p->data<data){
            q=p;
            p=p->next;
        }
        t->next=q->next;
        q->next=t;
    }
}

/* DELETION PROTOTYPE
void deleteat_Begg(){
    struct node* temp = head;
    head=head->next;
    free(temp);
}

void deleteat_Pos(int index){
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
        delete p;
    }


} 
*/

int delete_element(int index){
    int x;
    if(index<1){
        cout<<"Negetive integer"<<endl;
        return -1;
    }

    if(index==1){//for deleting 1st element
        struct node *p=head;
        head=head->next;
        x=p->data;
        free(p);
    }
    else{ // deleting other elemets in list
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
    int n = sizeof(a)/sizeof(int);
    
    create(a,n);
    // insertAtBegg(head, 99);
    // insertAt_Middle(head,4,99);


/*
    int totalNodes;  // knows the total nodes to create.
    cout<<"Enter the no of nodes to create"<<endl;
    cin>>totalNodes;
    cout<<totalNodes<<endl;
    for(int i=0 ; i<totalNodes; i++){
        int data;
        cout<<"Enter the data of the element"<<endl;
        cin>>data;
        insertatLast(data);
    }

*/

/*
    insertAt(head,1,10);
    insertAt(head,1,5);
*/
    insertAt(head,2,15);
    // insertAt_Sorted(5);
    //insert_Sorted_2pointers(5);

    // deleteat_Begg();
    // deleteat_Pos(3);
    // delete_element(5);
    display(head);

return 0;
}