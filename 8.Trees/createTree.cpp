#include <iostream>
using namespace std;

struct node {
    node *left;
    int data;
    node *right;
};

class cQueue {
    int size;
    int front;
    int rear;
    node **cQ;

public:
    cQueue(int size);
    void enqueue(node *data);
    node* dequeue();
    int isEmpty();
    int isFull();
};

cQueue::cQueue(int size) { // Creating the queue
    front = rear = -1;
    this->size = size;
    cQ = new node*[size]; // Allocate memory using new
}

void cQueue::enqueue(node *data) { // Add element to the queue
    if (isFull()) {
        cout << "Circular overflow" << endl;
    } else {
        rear = (rear + 1) % size;
        cQ[rear] = data;
        if (front == -1) // If the queue was empty
            front = 0;
    }
}

node* cQueue::dequeue() { // Remove element from queue
    node* x = NULL;
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
    } else {
        x = cQ[front];
        if (front == rear) { // Queue becomes empty
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }
    return x;
}

int cQueue::isEmpty() { // Checks if the queue is empty
    return front == -1;
}

int cQueue::isFull() { // Checks if the queue is full
    return (rear + 1) % size == front;
}

struct node *root=NULL;

void create(){
    node *p; //this will hold parent (when dequeue).
    node *t; //this will create and hold child.
    int x; //for reading the data
    cQueue q(40); //creating a queue of size 100 --> using constructor
    
    cout<<"Enter the root value ";
    cin>>x;

    root = new node;
    root->data = x;
    root->left = NULL;
    root->right = NULL;

    q.enqueue(root); //push the root address into queue

    while(!q.isEmpty()){ //check wheather there is more parent left (to add new children)
        p = q.dequeue(); //this the parent
        cout<<"Enter left child of "<<p->data<<" "; //for left child
        cin>>x;
        if(x != -1){
            t = new node; //this is the child;
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            q.enqueue(t); //push the addess of the left child into queue --> since we go left to right while creating a tree.
            p->left = t; //assign left child to the parent
        }

        cout<<"Enter right child of "<<p->data<<" "; //for right child
        cin>>x;
        if(x != -1){
            t = new node; //this is the child;
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            q.enqueue(t); //push the addess of the left child into queue --> since we go left to right while creating a tree.
            p->right = t; //assign right child to the parent.
        }
    }

}

void preorder(struct node *p){ //preorder traversal
    if(p){
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct node *p){ //preorder traversal
    if(p){
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}

void postorder(struct node *p){ //preorder traversal
    if(p){
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }
}

void levelOrder(node *p){
    cQueue q(100);
    cout<<p->data;
    q.enqueue(p);
    while(!q.isEmpty()){
        p = q.dequeue();
        if(p->left){
            cout<<p->left->data;
            q.enqueue(p->left);
        }
        if(p->right){
            cout<<p->right->data;
            q.enqueue(p->right);
        }
    }
}
  

int main(){
    create();
    preorder(root);
}