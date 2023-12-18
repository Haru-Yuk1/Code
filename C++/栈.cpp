#include<iostream>
using namespace std;
#define MAXSIZE 50
struct Stack
{
    int data[MAXSIZE];
    int top;
    Stack():top(-1){}
};
void InitStack(Stack *S){
    S->top=-1;
}
bool StackEmpty(Stack *S){
    if(S->top==-1){
        return true;
    }
    else{
        return false;
    }
}
void Push(Stack *S,int e){
    if(S->top==MAXSIZE-1){
        return;
    }
    S->top++;
    S->data[S->top]=e;
    return;
}
void Pop(Stack *S,int *e){
    if(S->top==-1){
        return;
    }
    *e =S->data[S->top];
    S->top--;
    return;
}
int GetTop(Stack *S,int *e){
    if(S->top == -1){   //栈空
        return 0;
    }
    *e = S->data[S->top];   //记录栈顶元素
    return *e;
}
int main(){
    Stack *stk=new Stack;
    InitStack(stk);
    if(StackEmpty(stk)){
        cout<<"yes";
    }
    Push(stk,1);
    int e=0;
    GetTop(stk,&e);
    cout<<"栈顶"<<e;
    if(StackEmpty(stk)){
        cout<<"yes";
    }
    Push(stk,2);
    Pop(stk,&e);
    cout<<e;
    Pop(stk,&e);
    if(StackEmpty(stk)){
        cout<<"yes";
    }
}