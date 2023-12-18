#include<iostream>
using namespace std;
// 单向链表
struct ListNode {
    int val;        //存储数据
    ListNode *next; //next指针
    ListNode() : val(0), next(NULL) {}  //类似构造函数
    ListNode(int x) : val(x), next(NULL) {}
};
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

int main(){
    ListNode* head=new ListNode(1);
    ListNode* node1=new ListNode(2);
    ListNode* node2=new ListNode(3);
    ListNode* node3=new ListNode(4);
    head->next=node1;
    node1->next=node2;
    node2->next=node3;
    node3->next=node1;
    ListNode* nhead=getLoopNode(head);
    if(nhead){
        cout<<"有环，入环节点的值"<<nhead->val;
    }
    else{
        cout<<"没有环";
    }
}