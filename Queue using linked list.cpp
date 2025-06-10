#include <iostream>
using namespace std;
#include<cstring>

struct node{
    int data;
    struct node *next;
};

struct queue{
    struct node* front;
    struct node* rear;
};

void create_queue(queue &Q){
    Q.front = Q.rear= NULL;
}


void enqueue(queue &Q,int x){
    node *t = new node;
    if(!t) cout<<"queue is full\n";
    else{
         t->data = x;
         t->next = NULL;
        if(Q.front == NULL){
            Q.rear = Q.front=t;
        }
        else{
            (Q.rear)->next=t;
             Q.rear = t;
        }
    }
}

void dequeue(queue &Q){
    if(Q.front) Q.front = (Q.front)->next;
    else cout<<"queue is empty\n";
}



void display(queue Q){
    node *t = Q.front;
    while(t!=NULL) {
        cout<<t->data<<" ";
        t=t->next;
        }
}

int main(){
    queue q1;
    create_queue(q1);
    enqueue(q1,1);
    enqueue(q1,2);
    enqueue(q1,3);
    enqueue(q1,4);

    dequeue(q1);
    dequeue(q1);
    dequeue(q1);
    display(q1);

    cout<<endl;

}
