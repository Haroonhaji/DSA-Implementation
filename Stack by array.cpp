#include <iostream>
using namespace std;
#include<cstring>

struct stack{
    int size;
    int top;
    int *s;
    char *exp;
};
void create_stack(stack &S,int t){
    S.size=t;
    S.top=-1;
    S.s = new int[t];
}
void create_char_stack(stack &S,int t){
    S.size=t;
    S.top=-1;
    S.exp = new char[t];
}

void push_stack(stack &S,int x){
    if(S.size -1 == S.top){
        cout<<"stack overflow\n";
    }
    else{
        S.top++;
        S.s[S.top]=x;
    }
}

void push_stack_char(stack &S,char x){
    if(S.size -1 == S.top){
        cout<<"stack overflow\n";
    }
    else{
        S.top++;
        S.exp[S.top]=x;
    }
}
void pop(stack &S){
    if(S.top==-1){
        cout<<"stack underflow\n";
    }
    else{
        S.top--;
    }
}

void Pop(stack &S){
    if(S.top>-1){
        S.top--;
    }
}

int peek(stack &S,int pos){
    int x=-1;
    if(S.top - pos + 1 <0){
        cout<<"invalid positon\n";
        return x;
    }
    x=S.s[S.top - pos + 1];
    return x;
}
int isFull(stack &S){
    if(S.top + 1==S.size) return 1;
    return 0;
}
int isEmpty(stack &S){
    if(S.top==-1) return 1;
    return 0;
}
void display(stack S){
    int i=S.top;
    while(i >-1){
        cout<<S.s[i]<<" ";
        i--;
    }
}
int is_balanced(char *exp){           //for parathesis matching. 
    stack s1;
    create_stack(s1,strlen(exp));
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push_stack(s1,1);
        }
        else if(exp[i]==')'){
            if(s1.top==-1) return 0;
            Pop(s1);
        }
    }
    if(s1.top==-1) return 1;
    return 0;
}

int precedence(char s){
    if(s=='+'|| s=='-') return 1;
    else if(s=='*'|| s=='/') return 2;
    else return 3;
}
int main(){
    stack s1;
    create_stack(s1,10);
    push_stack(s1,2);
    push_stack(s1,3);
    push_stack(s1,4);
    push_stack(s1,5);

    display(s1);
    cout<<endl;
    cout<<peek(s1,1)<<endl;
    Pop(s1);
    display(s1);
    cout<<endl;



    return 0;

}
