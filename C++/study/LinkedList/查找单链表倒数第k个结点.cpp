#include<iostream>
using namespace std;
// 单向链表
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode() : val(0), next(NULL) {}  //类似构造函数
    ListNode(int x) : val(x), next(NULL) {}
};
// 单指针法
ListNode* FindkthNodeReverse1(ListNode* head,int k){
    ListNode* ptr=head;
    int n=0;
    while (ptr)
    {
        n=n+1;
        ptr=ptr->next;
    }
    if(n>=k){
        ptr=head;
        for(int i=0;i<n-k;i++){
            ptr=ptr->next;
        }
    }
    return ptr;
}
//双指针法
ListNode* FindkthNodeReverse2(ListNode* head,int k){
    ListNode* ptr1=head;
    ListNode* ptr2=nullptr;
    for(int j=0;j<k-1;j++){
        if(ptr1){
            ptr1=ptr1->next;
        }
    }
    if(ptr1!=nullptr){
        ptr2=head;
    }
    while (ptr1->next)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return ptr2;
    
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
    cout<<FindkthNodeReverse1(p,3)->val;
    p=head;
    cout<<FindkthNodeReverse2(p,3)->val;
}