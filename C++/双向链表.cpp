#include<iostream>
using namespace std;
struct DoubleListNode{
    int val; //存储数据
    DoubleListNode *next=nullptr; //next指针指向下一结点
    DoubleListNode *pre=nullptr;//pre指针指向上一结点
    DoubleListNode() : val(0),next(nullptr),pre(nullptr){} //构造函数，建立了构造函数，必须使用构造函数
    DoubleListNode(int x):val(x),next(nullptr),pre(nullptr){}
};
int main(){
    DoubleListNode *node1=new DoubleListNode;
    DoubleListNode *node2=new DoubleListNode();
    DoubleListNode *node3=new DoubleListNode(100);
    cout<<node1->val<<endl;
    cout<<node2->val<<endl;
    cout<<node3->val<<endl;
    DoubleListNode *head=new DoubleListNode();
    DoubleListNode *p=head;
    for(int i=1;i<5;i++){
        DoubleListNode *temp=new DoubleListNode(i);
        p->next=temp;
        temp->pre=p;
        p=p->next;
    }
    p=head;
    //正向遍历
    while (p)
    {
        cout<<p->val;
        p=p->next;
    }
    // p=p->pre; 当p指针已经指向了链表的最后一个结点，这时p指针已经是一个空指针，那么这一句就没用
    cout<<endl;
    p=head;
    while(p->next)
    {
        p=p->next;
    }
    //反向遍历
    while (p)
    {
        cout<<p->val;
        p=p->pre;
    }
    
}