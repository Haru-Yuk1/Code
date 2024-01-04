#include<iostream>
using namespace std;
struct StackNode
{
    int data;
    StackNode* next;
    StackNode():data(0),next(nullptr){}
    StackNode(int x):data(x),next(nullptr){}
};
struct LinkStack
{
    StackNode* top;
    int size;
};

void InitStack(LinkStack *s){
    s->size=0;
    s->top=nullptr;
}
bool IsEmpty(LinkStack* s){
    return s->size;
}
void Push(LinkStack*s,int e){
    StackNode* newNode=new StackNode(e);
    newNode->next=s->top;
    s->top=newNode;
    s->size++;
}
StackNode* Top(LinkStack* s){
    if(IsEmpty(s)){
        return nullptr;
    }
    return s->top;
}
void Pop(LinkStack* s,int e){
    if(IsEmpty(s)){
        return;
    }
    StackNode* tmp=s->top;
    s->top=s->top->next;
    delete tmp;
    s->size--;
}

int main(){

}