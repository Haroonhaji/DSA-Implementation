#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    struct Node* next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n) {
    int i;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[],int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node* p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

void RDisplay(struct Node* p) {
    if (p != NULL) {
        RDisplay(p->next);
        cout << p->data << " ";
    }
}

int count(struct Node* p) {
    int l = 0;
    while (p) {
        l++;
        p = p->next;
    }
    return l;
}

int Rcount(struct Node* p) {
    if (p != NULL)
        return Rcount(p->next) + 1;
    else
        return 0;
}

int sum(struct Node* p) {
    int s = 0;
    while (p != NULL) {
        s += p->data;
        p = p->next;
    }
    return s;
}

int Rsum(struct Node* p) {
    if (p == NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
}


int Max(struct Node* p) {
    int max = INT_MIN;
    while (p) {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int RMax(struct Node* p) {
    int x;
    if (p == NULL)
        return INT_MIN;
    x = RMax(p->next);
    return (x > p->data) ? x : p->data;
}

struct Node*linear_search(struct Node*p,int key){
    while(p!=NULL){
       if(p->data==key){
           return p;
       }
       p=p->next;
    }
    return NULL;
}
struct Node* modified_linear_search(struct Node* p, int key)
{
    Node* q = nullptr; // Initialize q to nullptr

    while (p != nullptr)
    {
        if (key == p->data)
        {
            if (q != nullptr)  // Only move to front if it's not already the first node
                q->next = p->next;

            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return nullptr;
}

struct Node* RSearch(struct Node* p, int key)
{
    if (p == nullptr)
        return nullptr;
    if (key == p->data)
        return p;
    return RSearch(p->next, key);
}




void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > count(p)) return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index == 0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
        p=p->next;
        t->next=p->next;
        p->next=t;

    }
}



int Delete(struct Node *p,int index)
{
    struct Node *q=NULL;
    int x=-1,i;

    if(index < 1 || index > count(p))
    return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;

    }

}


bool isSorted(struct Node *p)
{
    int x= INT_MIN;

    while(p!=NULL)
    {
        if(p->data < x)
        return false;
        x=p->data;
        p=p->next;
    }
    return true;

}

void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;

    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }

}
void Reverse2(struct Node *&p)
{
    struct Node *q=NULL,*r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    p=q;
}

void Merge(struct Node *p,struct Node *q)
{
    struct Node *last;
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q)
    {
        if(p->data < q->data)
        {
        last->next=p;
        last=p;
        p=p->next;
        last->next=NULL;

        }
        else
        {
        last->next=q;
        last=q;
        q=q->next;
        last->next=NULL;

        }
    }
    if(p)last->next=p;
    if(q)last->next=q;

}

int isLoop(Node *p){
    Node *m=p,*n=p;
    while(1){
        m=m->next;
        n=n->next;
        if(n==NULL) return 0;
        n=n->next;
        if(n==NULL) return 0;
        if(m==n) return 1;
    }
}

void convert_to_circular_LL(Node *p){
    Node *q=p;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=p;
}
void Display_circular_LL(Node *p){
    Node *q=p;
    do{
        cout<<q->data<<" ";
        q=q->next;
    }
    while(q!=p);
}

void Display_circular_recursive(Node *p){
    static Node *q=p;
    static int flag =0;
    if(p!=q || flag==0){
        cout<<p->data<<" ";
        flag=1;
        Display_circular_recursive(p->next);
    }

}


void insert_circular(Node *q,int x,int position){
    Node *t=new Node, *p=q;
    t->data=x;
    if(position!=0){
        for(int i=0;i<position-1;i++){
            p=p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    else {
        while(p->next != q) p=p->next;
        p->next = t;
        t->next=q;
    }

}

void delete_from_circular_LL(Node *&p,int position){
    Node *q=p;
    if(position==1){
        while(q->next!=p) q=q->next;                    //     O R : 
        q->next=p->next;                                // q->next = p->next;
                                                       // delete p;
        p=p->next;                                      // p=q->next;
    }
        
    else{
        for(int i=0;i<position-2;i++){
            q=q->next;
        }
        q->next=(q->next)->next;
    }
}
int main() {

    int A[]={10,20,40,50,60};
    int B[]={15,18,25,30,55};
    create(A,5);
    create2(B,5);


    Merge(first,second);
    Display(third);
    cout<<endl;
    convert_to_circular_LL(third);
    Display_circular_LL(third);
    cout<<endl;
    insert_circular(third, 5,0);
    Display_circular_LL(third);
    cout<<endl;
    return 0;
   
    
}
