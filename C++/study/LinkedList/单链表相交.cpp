#include<iostream>
#include<cmath>
using namespace std;
// 单向链表
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode() : val(0), next(NULL) {}  //类似构造函数
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* getIntersectNode(ListNode* head1,ListNode*head2){
    if(head1==nullptr||head2==nullptr){
        return nullptr;
    }
    ListNode* loop1=getLoopNode(head1);
    ListNode* loop2=getLoopNode(head2);
    if (loop1==nullptr&&loop2==nullptr)
    {
        return noLoop(head1,head2);
    }
    if (loop1!=nullptr&&loop2!=nullptr)
    {
        return bothLoop(head1,loop1,head2,loop2);
    }
    return nullptr;
    
}
//判断是否有环，如果无环，返回null，如果有环，返回入环节点
ListNode* getLoopNode(ListNode* head){ 
    if(head==nullptr|| head->next==nullptr||head->next->next==nullptr){
        return nullptr; //三个节点以上才能形成环
    }
    ListNode* n1=head->next; //快慢指针
    ListNode* n2=head->next->next;
    while(n1!=n2){
        if(n2->next==nullptr||n2->next->next==nullptr){
            return nullptr;
        }
        n2=n2->next->next;
        n1=n1->next;
    }
    n2=head;
    while (n1!=n2) //n2 会到头节点重走一遍，最后n1、n2在入环结点相遇
    {
        n1=n1->next;
        n2=n2->next;
    }
    
    return n1;
}
// 两个无环链表的相交节点，如果有返回第一个相交节点，如果无则返回null
ListNode* noLoop(ListNode* head1,ListNode* head2){
    if(head1==nullptr||head2==nullptr){
        return nullptr;
    }
    ListNode* cur1=head1;
    ListNode* cur2=head2;
    int n=0;
    while (cur1->next)//找链表1的长度
    {
        n++;
        cur1=cur1->next;
    }
    while (cur2->next)//找链表2的长度
    {
        n--;
        cur2=cur2->next;
    }
    if(cur1!=cur2){//无环链表如果相交最好肯定结点相同
        return nullptr;
    }
    cur1=n>0?head1:head2; //谁长令谁为cur1
    cur2=cur1==head1?head2:head1; //谁短令谁为cur2
    n=abs(n);   
    while(n!=0){//长的先走长度差值
        n--;
        cur1=cur1->next;
    }
    while (cur1!=cur2) //两指针一起走有环总会遇到
    {
        cur1=cur1->next;
        cur2=cur2->next;
    }
    
    return cur1;
}
//一个有环链表和一个无环链表 不可能相交

// 两个有环链表的相交结点，如果有返回第一个相交节点，如果无则返回null
ListNode* bothLoop(ListNode* head1,ListNode*loop1,ListNode* head2,ListNode* loop2){
    ListNode* cur1=nullptr;
    ListNode* cur2=nullptr;
    if(loop1==loop2){ //如果两链表入环节点相同，则说明他们至少在入环前相交,则方式跟无环相同
        cur1=head1;
        cur2=head2;
        int n=0;
        while (cur1!=loop1)// 找链表1到入环节点的长度
        {
            n++;
            cur1=cur1->next;
        }
        while (cur2!=loop2)// 找链表2到入环节点的长度
        {
            n--;
            cur2=cur2->next;
        }
        cur1=n>0?head1:head2; //谁长令谁为cur1
        cur2=cur1==head1?head2:head1; //谁短令谁为cur2
        n=abs(n);   
        while(n!=0){//长的先走长度差值
            n--;
            cur1=cur1->next;
        }
        while (cur1!=cur2) //两指针一起走有环总会遇到
        {
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return cur1;
    }
    else{ //两链表入环节点不同
        cur1=loop1->next;
        while (cur1!=loop1) //入环后一定能与链表2的入环节点相遇
        {
            if(cur1==loop2){
                return loop1; //返回loop1 loop2都行,
            }
            cur1=cur1->next;
        }
        
    }
    return nullptr;
}
int main(){
    ListNode* head1=new ListNode(0);
    ListNode* head2=new ListNode(0);
    ListNode *p1=head1;
    ListNode *p2=head2;
    for(int i=1;i<=5;i++){
        ListNode *node1=new ListNode(i);
        p1->next=node1;
        p1=p1->next;
        if(i<3){
            ListNode *node2=new ListNode(i);
            p2->next=node2;
            p2=p2->next;
        }
        else{
            p2->next=node1;
            p2=p2->next;
        }
    }
    ListNode* meet= noLoop(head1,head2);
    cout<<meet->val;
    
}