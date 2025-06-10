#include <iostream>
using namespace std;
#include<cstring>

struct tree_node{
    int data;
    tree_node *lchild;
    tree_node *rchild;

};

struct queue{
    int size;
    int front;
    int rear;
    tree_node**Q;                // not like a normal queue has a pointer to an array as INT *S. here this pointer is of type node.
};


void create_queue(int s,queue &S){
    S.size=s;
    S.front=0;
    S.rear=0;
    S.Q = new tree_node*[s];
}


void enqueue(queue &S, tree_node *x){
    if((S.rear +1)%(S.size)==S.front) cout<<"queue is full\n";
    else{
        S.rear=(S.rear +1)%(S.size);
        S.Q[S.rear]=x;
    }

}
tree_node* dequeue(queue &S){
    if(S.rear == S.front) cout<<"queue is empty\n";
    else {
        S.front=(S.front +1)%(S.size);    
    }
    return S.Q[S.front]; 
}

int is_Empty(queue S){
    if(S.rear == S.front) return 1;
    return 0;
}

int is_Full(queue S){
    if((S.rear +1)%(S.size)==S.front) return 1;
    return 0;
}


// void display(queue S){
//     for(int i=(S.front)+1 ; i!=S.rear ;i=(i+1)%S.size){
//         cout<<S.Q[i]<<" ";
//     }
//     cout<<S.Q[S.rear];
// }


void create_binary_tree(tree_node *&root, queue &q){
    tree_node *p, *t;
    int x,y;
    cout<<"Enter root value\n";
    cin>>x;
    root->data =x;
    root->lchild=root->rchild=0;
    enqueue(q,root);

    while(! is_Empty(q)){
        p=dequeue(q);
        cout<<"enter left child of "<<p->data<<endl;
        cin>>y;
        if(y!=-1){
            t= new tree_node;
            t->data = y;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(q,t);
        }
        cout<<"enter right child of "<<p->data<<endl;
        cin>>y;
        if(y!=-1){
            t= new tree_node;
            t->data = y;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(q,t);
        }
    }

}

void preorder(tree_node *r){          // recursive
    if(r){
        cout<<r->data<<" ";
        preorder(r->lchild);
        preorder(r->rchild);
    }
}

void inorder(tree_node *r){         // recursiveb
    if(r){
        inorder(r->lchild);
        cout<<r->data<<" ";
        inorder(r->rchild);
    }
}


void postorder(tree_node *r){           // recursive
    if(r){
        postorder(r->lchild);
        postorder(r->rchild);
        cout<<r->data<<" ";
    }
}

void level_order_traversal(tree_node* p){
    queue q1;
    create_queue(20,q1);
    enqueue(q1,p);
    cout<<p->data<<" ";
    while(! is_Empty(q1)){
        p=dequeue(q1);
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            enqueue(q1,p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            enqueue(q1,p->rchild);
        }
    }
}


int Height(tree_node *p) {
    int l = 0;
    int r = 0;
 
    if (p != nullptr){
        l = Height(p->lchild);
        r = Height(p->rchild);
        if (l > r){
            return l + 1;
        } else {
            return r + 1;
        }
    }
    return 0;
}
 
int Count(tree_node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = Count(p->lchild);
        y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}
 
int sum(tree_node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = sum(p->lchild);
        y = sum(p->rchild);
        return x + y + p->data;
    }
    return 0;
}
 
int deg2NodeCount(tree_node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = deg2NodeCount(p->lchild);
        y = deg2NodeCount(p->rchild);
        if (p->lchild && p->rchild){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
 

int main(){
    queue q1;
    create_queue(20,q1);
    tree_node *root;
    root = new tree_node;
    create_binary_tree(root,q1);

    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;

    level_order_traversal(root);
    cout<<endl;

}

