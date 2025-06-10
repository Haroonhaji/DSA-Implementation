#include <iostream>
using namespace std;
#include<cstring>

struct stack_node{
    int data;
    stack_node *next;
};


void create(int A[],int n,stack_node *&p)
{
    int i;
    struct stack_node *last, *t;
    p=new stack_node;
    p->data=A[0];
    p->next=NULL;
    last=p;//addreess is passed and now first is refferd as last

    for(i=1;i<n;i++)
    {
        t=new stack_node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;//putting address of current node in the next of last node 
        last=t;//assigning current node as last node
    }
}

void display(stack_node *s){
    stack_node *t=s;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }
}
void push_stack_node(stack_node *&S,int x){  
    stack_node *s=new stack_node;
    s->data=x;
    s->next=S;
    S=s;
}

void pop_stack_node(stack_node *&S){
    stack_node *t=S;
    S=S->next;
    free(t);
}

int peek(stack_node *S,int pos){
    if(pos<=0) return -1;
    stack_node *p=S;
    for(int i=0;i<pos-1 && p;i++){
        p=p->next;
    }
    if(p) return p->data;
    
    return -1;
}

int is_Empty(stack_node *top){
    if(top==NULL) return 1;
    return 0;
}
int is_Full(stack_node *top){
    stack_node *t=new stack_node;
    if(t==NULL) return 1;
    return 0;
}


int main(){
    stack_node *s= NULL;

    push_stack_node(s,1);
    display(s);
    cout<<endl;

    push_stack_node(s,2);
    display(s);
    cout<<endl;

    push_stack_node(s,3);
    display(s);
    cout<<endl;

    push_stack_node(s,4);
    display(s);
    cout<<endl;

    push_stack_node(s,5);
    display(s);
    cout<<endl;

    cout<<peek(s,2)<<" "<<peek(s,0);





}




