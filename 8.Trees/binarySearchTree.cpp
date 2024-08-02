#include<iostream>
using namespace std;

class node{
    public:
    node *left;
    int data;
    node *right;
    // node *root = NULL;
    // node(){node *root = NULL;}
    node *recSearch(node *p, int key);
    node *iterSearch(node *p, int key);
    node *recInsert(node *p, int key);
    node *iterInsert(node *p, int key);
    void insert(int key);
    void inorder(node *p);
    node *recDelete(node *p, int key);
    int Height(node *p);
    node* InPre(node *p);
    node* InSucc(node *p);

}*root = NULL;

node* node :: recSearch(node *p, int key){
    if(p==NULL) return NULL;
    if(p->data == key) return p;
    else if(key < p->data) return recSearch(p->left, key);
    else return recSearch(p->right, key);
}

node* node :: iterSearch(node *p, int key){
    while(p!=NULL){
        if(p->data == key) return p;
        else if(key<p->data) p = p->left;
        else p = p->right;
    }
    return p;
}

node* node :: recInsert(node *p, int key){
    node *t;
    if(p==NULL){
        t = new node;
        t->data = key;
        t->left=t->right=NULL;
        root = t;
        return t;
    }

    if(key<p->data){
        p->left = recInsert(p->left, key);
    }

    else if(key>p->data){
        p->right = recInsert(p->right, key);
    }
    else return p;
}

node *node :: iterInsert(node *p, int key){ // though this is a functtion to insert to an already created BST
    node *r=NULL, *t;
    while(p!=NULL){
        r=p;
        if(p->data == key) return NULL;
        else if (key < p->data) p = p->left;
        else p = p->right;
    }
    t = new node;
    t->data = key;
    t->left = t->right = NULL;
    if(key < r->data) r->left = t;
    else r->right = t;
} 


void node :: insert(int key){
    node *p=root;
    node *r=NULL, *t;

    if(root==NULL){
        t = new node;
        t->data = key;
        t->left = t->right = NULL;
        root = t;
        return;
    }

    while(p!=NULL){
        r = p;
        if(key < p->data) p = p->left;
        else if(key > p->data )p = p->right;
        else return;
    }
    t = new node;
    t->data = key;
    t->left = t->right = NULL;
    if(key < r->data) r->left = t;
    else r->right = t;
}


void node :: inorder(node *p){
    if(p){
        inorder(p->left);
        cout<<p->data<<"  ";
        inorder(p->right);
    }
}

int node :: Height(node *p){
    int x,y;
    if(p==NULL) return 0;
    x = Height(p->left);
    y = Height(p->right);
    if(x>y) return x+1;
    else return y+1;
    
}

node* node :: InPre(node *p){
    while(p && p->right!=NULL){
        p = p->right; //right most of left subtree
    }
    return p;
}

node* node :: InSucc(node *p){
    while(p && p->left!=NULL){
        p = p->left; //right most of left subtree
    }
    return p;
}

node* node :: recDelete(node* p, int key){
    node* q;
    if(p==NULL) return NULL; //no BST exist

    if(p->left == NULL && p->right == NULL) {
        if(p == root) root == NULL;
        free(p); // condition for leaf node
        return NULL;
    }
    if(key<p->data) p->left = recDelete(p->left, key);
    else if(key>p->data) p->right = recDelete(p->right, key);
    else{
        if(Height(p->left) > Height(p->right)){
            q = InPre(p->left); //to find the predecessor as left height > right
            p->data = q->data;
            p->left = recDelete(p->left, q->data);
        }
        else{
            q = InSucc(p->right); //to find the predecessor as left height > right
            p->data = q->data;
            p->right = recDelete(p->right, q->data);
        }
    }
    return p;
}

int main(){
    node a;
    /*
    root = a.recInsert(root,30); //using recursive function
    a.recInsert(root, 20);
    a.recInsert(root, 40);
    */
    int arr[] = {9,15,5,20,16,8,12,3,6};
    // root = a.recInsert(root, arr[0]);
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
        a.insert(arr[i]);
    }


    // a.insert(10);
    // a.insert(5);
    // a.insert(20);
    // a.insert(8);
    // a.insert(30);


    a.inorder(root);
    cout<<endl<<a.iterSearch(root,12);
    cout<<endl<<a.recSearch(root,2);

    cout<<endl;
    
    a.recDelete(root,16);
    a.inorder(root);


}