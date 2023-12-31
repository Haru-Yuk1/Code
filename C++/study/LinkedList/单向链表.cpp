#include<iostream>
using namespace std;
// 单向链表
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode() : val(0), next(NULL) {}  //类似构造函数
    ListNode(int x) : val(x), next(NULL) {}
};

//求表长
int length(ListNode* head){
    int res=0;
    ListNode* tmp=head;
    while(tmp){
        tmp=tmp->next;
        res++;
    }
    return res;
}
//按序号查找
ListNode* Get(ListNode* head,int index){
    if(index>length(head)){
        return nullptr;
    }
    ListNode* tmp=head;
    for(int i=0;i<index;i++){
        tmp=tmp->next;
    }
    return tmp;
}
//按值查找
ListNode* Search(ListNode* head,int val){
    ListNode* tmp=head;
    while (tmp->val!=val&&tmp)
    {
        tmp=tmp->next;
    }
    return tmp;
}
//插入
ListNode* Insert(ListNode* head,int index,int val){
    ListNode* root=head;
    for(int i=0;i<index-1;i++){
        root=root->next;
    }
    ListNode* tmp=root->next;
    ListNode* newnode=new ListNode(val);
    root->next=newnode;
    newnode->next=tmp;
    return head;
}
//删除 index是从1开始
ListNode* Remove(ListNode* head,int index){
    if(index<1||head==nullptr){
        return head;
    }
    if(head->next==nullptr&&index==1){
        return nullptr;
    }
   
    ListNode* tmp=new ListNode();
    tmp->next=head;
    ListNode* ptr=tmp;
    for(int i=0;i<index-1;i++){
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;
    return tmp->next;
}
int main(){
    ListNode *head=new ListNode();
    ListNode *p=head;
    //循环建立表
    for(int i=1;i<5;i++){
        ListNode *node=new ListNode(i);
        p->next=node;
        p=p->next;
    }
    p->next=nullptr;
    //遍历整个表
    p=head;
    while (p)
    {
        cout<<p->val;
        p=p->next;
    }

    cout<<endl;
    cout<<"——————求表长——————"<<endl;
    cout<<length(head)<<endl;
    cout<<"——————按序号查找——————"<<endl;
    cout<<Get(head,3)->val<<endl;
    cout<<"——————按值查找——————"<<endl;
    cout<<Search(head,4)->val<<endl;
    cout<<"——————删除——————"<<endl;
    cout<<Remove(head,1)->val<<endl;
    return 0;
}


