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
}

int add_iterative(struct node* temp){
    int sum=0;
    while(temp){
        sum+=temp->data;
        temp=temp->next;
    }
    return sum;
}

int add_recursive(struct node* temp){
    if(temp){
        return add_recursive(temp->next)+temp->data; // the base condition can be anything weather 
                                    //the single termination condition or the the loop thing (condition)
    }
    else return 0;
}
int add_recursive1(struct node* temp){
    if(temp == NULL) // base condition -> head is pointing to no node.
        return 0;
    else
        return add_recursive1(temp->next)+temp->data;
}


int findMax_itr(struct node* temp){
    int max = head->data;
    while(temp){
        if(temp->data > max){
            max= temp->data;
            temp=temp->next;
        }
        else
            temp=temp->next;
    }
    return max;
}

int findMax_rec(struct node* temp){
    if(temp==NULL){
        return 0;
    }
    else
        return max(findMax_rec(temp->next),temp->data);
}

node* search_typeNode(struct node* temp, int key){
    int pos = -1;
    while(temp){
        if(temp->data==key)
            return temp;

        temp = temp->next; 
    }
    return NULL;
}

int search(struct node* temp, int key){
    int pos = 0;
    while(temp){
        if(temp->data==key){
            return pos;
        }
        else{
        temp = temp->next; 
        pos++;
        }
    }
    return -1;
}

int main(){

    int a[]={10,20,30,40};
    int n = sizeof(a)/sizeof(int);
    create(a,n);
    // <<"Th sum of the elements are :"<<add_iterative(head)<<endl;
    // cout<<"Th sum of the elements are :"<<add_recursive(head)<<endl;
    //cout<<"Th sum of the elements are :"<<add_recursive1(head)<<endl;
    // cout<<"The maximum element in the list is "<<findMax_itr(head)<<endl;
    // cout<<"The maximum element in the list is "<<findMax_rec(head)<<endl;

    //searching. / /
    int key = 20;
    int x=search(head,key);
    if(x>=0)
        cout<<" Position of the key "<<key<<" is "<<x<<endl;
    else
        cout<<"The element "<<key<<" not found"<<endl;
        
    //cout<<"The pos is "<<search(head,key)<<endl;
    return 0;
}