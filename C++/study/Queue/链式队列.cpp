#include<iostream>
using namespace std;
struct QueueNode
{
    int data;
    QueueNode* next;
    QueueNode():data(0),next(nullptr){}
    QueueNode(int x):data(x),next(nullptr){}
};
struct LinkQueue
{
    QueueNode *front,*rear;
};

void InitQueue(LinkQueue *Q){
	Q->front = Q->rear = new QueueNode();	//建立头结点
	Q->front->next = NULL;	//初始为空
}
void EnQueue(LinkQueue*Q,int e){
    QueueNode* s=new QueueNode(e);
    Q->rear->next=s;    //把拥有元素e新结点s赋值给原队尾结点的后继
    Q->rear=s;          //把当前的s设置为新的队尾结点
}

/*若队列不空，删除Q的队头元素，用e返回其值*/
int DeQueue(LinkQueue *Q, int e){
	QueueNode* tmp;
	if(Q->front == Q->rear){
		return 0;
	}
	tmp = Q->front->next;	//将欲删除的队头结点暂存给p
	e = tmp->data;	//将欲删除的队头结点的值赋值给e
	Q->front->next = tmp->next;	//将原队头结点的后继赋值给头结点后继
	//若删除的队头是队尾，则删除后将rear指向头结点
	if(Q->rear == tmp){	
		Q->rear = Q->front;
	}
	delete tmp;
	return e;
}