#include<iostream>
#include "header.h"
using namespace std;

struct node *root=NULL;

void create(){
    node *p, *t;
    int x;
    cQueue q(100);
    cout<<"Enter the value of the root node"<<endl;
    cin>> x;
    root = new node;
    root->data=x;
    root->left=root->right=NULL;
    q.enqueue(root);
    while(!q.isEmpty()){
        p=q.dequeue();
        cout<<"Enter the left child"<<endl;
        cin>>x;
        if(x!=-1){
            t=new node;
            t->data=x;
            t->left=t->right=NULL;
            p->left=t;
            q.enqueue(t);
        }
        cout<<"Enter the right child"<<endl;
        cin>>x;
        if(x!=-1){
            t=new node;
            t->data=x;
            t->left=t->right=NULL;
            p->right=t;
            q.enqueue(t);
        }
    }

}

int main(){
    create();
    
    return 0;
}