#include<iostream>
using namespace std;
#define MAXSIZE 50
struct Stack
{
    int data[MAXSIZE];  //用数组存储数据
    int top;            //栈顶指针
    Stack():top(-1){}
};
// 初始化栈
void InitStack(Stack *S){
    S->top=-1;
}
//判断栈是否为空
bool StackEmpty(Stack *S){
    if(S->top==-1){
        return true;
    }
    else{
        return false;
    }
}
//压栈
void Push(Stack *S,int e){
    if(S->top==MAXSIZE-1){  //栈满，不压
        return;
    }
    S->top++;               //栈顶指针后移
    S->data[S->top]=e;      //对应元素赋值
    return;
}
//出栈
void Pop(Stack *S,int *e){
    if(S->top==-1){         //栈空，不弹
        return;
    }
    *e =S->data[S->top];    //将栈顶原素赋给e
    S->top--;
    return;
}
//获取栈顶元素
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