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

void display_iterative(struct node *temp){ //IT PRINTS THE ELEMENTS IN LIST ITERATIVELY
    int count =0;
    while(temp != NULL){
        count++;
        cout<<"The element "<<count<<" is "<<temp->data<<endl;
        temp=temp->next;
    }
}

//IT FIRST PRINTS THE ELEMENTS AND THEN MOVE TO THE NEXT NODE (RECURSIVELY)
void display_recursive(struct node* temp){
    if(temp!=NULL){
        cout<<"The element is "<<temp->data<<endl;
        display_recursive(temp->next);
    }
}

void display_recursive_REVERSE(struct node* temp){ //IT PRINTS THE ELEMENTS IN THE REVERSE ORDER.
    if(temp!=NULL){
        display_recursive_REVERSE(temp->next);
        cout<<"The element is "<<temp->data<<endl;
    }
}
int count_iterative(struct node* temp){
    int count=0;
    while(temp!= NULL){
        count++;
        temp=temp->next;
    }
        return count;
}

// int c_rec=0;               //NOT SO GOOD APPROACHHHH
// int count_recursive(struct node *temp){
//     if(temp!=NULL){
//         c_rec++;
//         count_recursive(temp->next);
//     }
// }

int count_recursive(struct node* temp){
    if(temp == NULL)
        return 0;
    else
        return count_recursive(temp->next)+1;
} 


int main(){

    int a[]={10,20,30,40};
    int n = sizeof(a)/sizeof(int);
    create(a,n);
    //display_iterative(head);
    //display_recursive(head);
    //display_recursive_REVERSE(head);
    //cout<<"The number of nodes in the list is "<< count_iterative(head) <<endl;
    cout<<"The number of nodes in the list is "<< count_recursive(head) <<endl;
    return 0;
}