#include<iostream>
using namespace std;
#define MAXSIZE 50
//采用虚指针的队列
struct Queue
{
    int data[MAXSIZE];
    int front;
    int rear;
    Queue():front(0),rear(0){}
};
//初始化
void InitStack(Queue* queue){
    queue->front=0;
    queue->rear=0;
}
//求队列长度
int QueueLength(Queue* Q){
    return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}
//判断是否为空
bool isEmpty(Queue* Q){
    if(Q->rear==Q->front){
        return true;
    }
    else{
        return false;
    }
}
//判断是否满
bool isFull(Queue* Q){
    if((Q->rear+1)%MAXSIZE==Q->front){
        return true;
    }
    else{
        return false;
    }
}
//入队
void EnQueue(Queue* Q,int x){
    if(isFull(Q)){
        return;
    }
    Q->data[Q->rear]=x;
    Q->rear=(Q->rear+1)%MAXSIZE;
    
}
//出队
void DeQueue(Queue* Q){
    if(isEmpty(Q)){
        return;
    }
    Q->front=(Q->front+1)%MAXSIZE;
}

int main(){

}