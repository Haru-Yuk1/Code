#include<iostream>
using namespace std;
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode() : val(0), next(nullptr) {}  //类似构造函数
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct DoubleListNode
{
    int val;
    DoubleListNode *next;
    DoubleListNode *pre;
    DoubleListNode() : val(0),next(nullptr),pre(nullptr){} //构造函数，建立了构造函数，必须使用构造函数
    DoubleListNode(int x):val(x),next(nullptr),pre(nullptr){}
};

//迭代反转法
ListNode* reverseList1(ListNode* head) {
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* pre = nullptr;  // 定义 pre 指针，初始化为 nullptr；
    ListNode* cur = head;  // 定义 cur 指针，指向头结点；
    //迭代反转，利用三个指针，当cur从头结点移动到尾结点停止
    while(cur) {
        ListNode* tmp = cur->next;  // 定义 temp 指针，指向 cur->next 节点
        cur->next = pre;//将头指向null
        // 后移 pre 和 cur 指针
        pre = cur;  
        cur = tmp;
    }
    return pre;
}
// 头插法
ListNode* reverseList2(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* cur=head;
    ListNode* newhead=nullptr;
    while (cur)
    {
        //next 保存当前cur所在结点的下一个结点的位置
        ListNode* next=cur->next;
        cur->next=newhead;//开始头插
        newhead=cur;//更新头结点
        cur=next;//cur指向下一个待插入的节点
    }
    return newhead;
    
}
// 就地逆转法 有头结点
ListNode* reverseList3(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* pre=head->next;
    ListNode* cur=head->next->next;
    
    while (cur!=nullptr)
    {
        pre->next=cur->next;//将cur从链表中摘除
        cur->next=head->next;//将cur移动至链表头，将cur的下一个指向pre
        head->next=cur;//将头指向cur
        cur=pre->next;//将cur调整至pre的下一个
    }
    return head;
    

}
//就地逆转法 无头结点
ListNode* reverseList32(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* pre=head;
    ListNode* cur=head->next;
    
    while (cur!=nullptr)
    {
        pre->next=cur->next;//将cur从链表中摘除
        cur->next=head;//将cur移动至链表头，将cur的下一个指向pre
        head=cur;//将头指向cur
        cur=pre->next;//将cur调整至pre的下一个
    }
    return head;
    

}
//递归反转法
ListNode* reverseList4(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* newhead=reverseList4(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newhead;
}
//反转双向链表
DoubleListNode* reverseDoubleList1(DoubleListNode* head){
    DoubleListNode *cur=NULL;
    DoubleListNode *prev=NULL;
    while (head)
    {
        cur=head->next;
        head->next=prev;
        head->pre=cur;
        prev=head;
        head=cur;
    }
    return prev;
}
int main(){
    //单向链表的一系列操作
    ListNode *head=new ListNode();
    ListNode *p=head;
    //创建一个链表01234
    for(int i=1;i<5;i++){
        ListNode *node=new ListNode(i);
        p->next=node;
        p=p->next;
    }
    p->next=nullptr;
    p=head;
    cout<<"迭代逆转法:";
    ListNode *nhead=reverseList1(head);
    p=nhead;
    for(int i=0;i<5;i++)
    {
        /* code */
        cout<<p->val;
        p=p->next;
    }
    ListNode* nhead2=reverseList2(nhead);
    p=nhead2;
    cout<<endl<<"头插法:";
    for(int i=0;i<5;i++)
    {
        /* code */
        cout<<p->val;
        p=p->next;
    }
    ListNode* nhead3=reverseList3(nhead2);
    p=nhead3;
    cout<<endl<<"就地逆转法，有头结点:";
    for(int i=0;i<5;i++)
    {
        /* code */
        cout<<p->val;
        p=p->next;
    }
    cout<<endl<<"就地逆转法，无头结点:";
    ListNode* nhead4=reverseList32(nhead3);
    p=nhead4;
    for(int i=0;i<5;i++)
    {
        /* code */
        cout<<p->val;
        p=p->next;
    }
    cout<<endl<<"递归逆转法:";
    ListNode* nhead5=reverseList4(nhead4);
    p=nhead5;
    for(int i=0;i<5;i++)
    {
        /* code */
        cout<<p->val;
        p=p->next;
    }
    //双向链表的操作
    cout<<"\n———————————————————双向链表的反转———————————————————"<<endl;
    DoubleListNode *head2=new DoubleListNode();
    DoubleListNode *p2=head2;
    for(int i=1;i<5;i++){
        DoubleListNode *temp=new DoubleListNode(i);
        p2->next=temp;
        temp->pre=p2;
        p2=p2->next;
    }
    p2=head2;
    while (p2)
    {
        cout<<p2->val;
        p2=p2->next;
    }
    cout<<"反转后"<<endl;
    DoubleListNode*newhead=reverseDoubleList1(head2);
    p2=newhead;
    while (p2)
    {
        cout<<p2->val;
        p2=p2->next;
    }
    
    
}