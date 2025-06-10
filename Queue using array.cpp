#include <iostream>
using namespace std;
#include<cstring>

struct queue{
    int size;
    int front;
    int rear;
    int *Q;
};


void create_queue(int s,queue &S){
    S.size=s;
    S.front=-1;
    S.rear=-1;
    S.Q= new int[s];
}

int isEmpty(queue S){
    if(S.front == S.rear) return 1;
    return 0;
}
int isFull(queue S){
    if(S.rear == S.size -1) return 1;
    return 0;
}
void enqueue(queue &S,int x){
    if(S.rear==S.size-1) cout<<"queue is full\n";
    else{
        (S.rear)+=1;
        S.Q[S.rear]=x;
    }
}


void dequeue(queue &S){
    if(S.front==S.rear) cout<<"queue is empty\n";
    else S.front++;
}


void display(queue &S){
    for(int i=S.front+1 ;i<=S.rear;i++){
        cout<<S.Q[i]<<" ";
    }
}


int main(){
    queue q1;
    create_queue(5,q1);
    enqueue(q1,1);
    display(q1);
    cout<<endl;

    enqueue(q1,2);
    enqueue(q1,3);
    enqueue(q1,4);
    enqueue(q1,5);

    display(q1);
    cout<<endl;

    cout<<isFull(q1);

   

}